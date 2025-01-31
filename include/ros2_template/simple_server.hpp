#ifndef ROS2_TEMPLATE__SIMPLE_SERVER_
#define ROS2_TEMPLATE__SIMPLE_SERVER_

#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>

class SimpleServer : public rclcpp::Node
{
public:
    explicit SimpleServer(const rclcpp::NodeOptions &options);

private:
    void handleService(
        const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
        const example_interfaces::srv::AddTwoInts::Response::SharedPtr response);
    
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;
};

#endif  // ROS2_TEMPLATE__SIMPLE_SERVER_