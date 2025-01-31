#include "ros2_template/simple_server.hpp"

SimpleServer::SimpleServer(const rclcpp::NodeOptions & options)
: Node("simple_server", options)
{
    RCLCPP_INFO(get_logger(), "Start simple_server_node!");

    server_ = create_service<std_srvs::srv::SetBool>(
        "set_bool_service",
        std::bind(&SimpleServer::handleService, this, std::placeholders::_1, std::placeholders::_2)
    );
}

void SimpleServer::handleService(
    const std_srvs::srv::SetBool::Request::SharedPtr request,
    const std_srvs::srv::SetBool::Response::SharedPtr response)
{
    RCLCPP_INFO(get_logger(), "Received request: data=%s, waiting 10 seconds...",
                request->data ? "true" : "false");
                
    std::this_thread::sleep_for(std::chrono::seconds(10));

    if (request->data) {
        response->success = true;
        response->message = "The operation was successful.";
    } else {
        response->success = false;
        response->message = "The operation failed.";
    }

    RCLCPP_INFO(get_logger(), "Response sent after 10 seconds: success=%s, message=%s",
                response->success ? "true" : "false",
                response->message.c_str());
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(SimpleServer)
