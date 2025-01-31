#include "ros2_template/simple_client.hpp"

using namespace std::chrono_literals;

SimpleClient::SimpleClient(const rclcpp::NodeOptions & options)
: Node("simple_client", options)
{
    RCLCPP_INFO(get_logger(), "Start simple_client_node!");

    client_ = create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

    sendRequest(10, 20);
}

void SimpleClient::sendRequest(int64_t a, int64_t b)
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
    
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = a;
    request->b = b;

    auto future_result = client_->async_send_request(request);

    if (rclcpp::spin_until_future_complete(get_node_base_interface(), future_result) == rclcpp::FutureReturnCode::SUCCESS) 
    {
        RCLCPP_INFO(get_logger(), "Result: %ld", future_result.get()->sum);
    }
    else
    {
        RCLCPP_ERROR(get_logger(), "Failed to call service add_two_ints");
    }
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(SimpleClient)