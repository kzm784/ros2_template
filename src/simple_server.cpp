#include "ros2_template/simple_server.hpp"

SimpleServer::SimpleServer(const rclcpp::NodeOptions & options)
: Node("simple_server", options)
{
    RCLCPP_INFO(get_logger(), "Start simple_server_node!");

    server_ = create_service<example_interfaces::srv::AddTwoInts>(
        "add_two_ints",
        std::bind(&SimpleServer::handleService, this, std::placeholders::_1, std::placeholders::_2)
    );
}

void SimpleServer::handleService(
    const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
    const example_interfaces::srv::AddTwoInts::Response::SharedPtr response)
{
    response->sum = request->a + request->b;
    RCLCPP_INFO(get_logger(), "Recieved request: %ld + %ld = %ld", request->a, request->b, response->sum);
}

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(SimpleServer)