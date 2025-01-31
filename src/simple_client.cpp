#include "ros2_template/simple_client.hpp"


using namespace std::chrono_literals;

SimpleClient::SimpleClient(const rclcpp::NodeOptions & options)
: Node("simple_client", options)
{
    RCLCPP_INFO(get_logger(), "Start simple_client_node!");

    client_ = create_client<std_srvs::srv::SetBool>("set_bool_service");

    sendRequest(true);
}

void SimpleClient::sendRequest(bool data)
{
    while (!client_->wait_for_service(1s))
    {
        if (!rclcpp::ok())
        {
            RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Waiting for service to be available...");        
    }
    
    auto request = std::make_shared<std_srvs::srv::SetBool::Request>();
    request->data = data;

    auto future_result = client_->async_send_request(request);

    if (!future_result.valid()) {
        RCLCPP_ERROR(get_logger(), "Service call failed: Future result is invalid.");
        return;
    }

    if (rclcpp::spin_until_future_complete(get_node_base_interface(), future_result) == rclcpp::FutureReturnCode::SUCCESS) 
    {
        auto response = future_result.get();
        RCLCPP_INFO(get_logger(), "Service Response: success=%s, message=%s", 
                    response->success ? "true" : "false", 
                    response->message.c_str());
    }
    else
    {
        RCLCPP_ERROR(get_logger(), "Failed to call service set_bool_service");
    }
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(SimpleClient)