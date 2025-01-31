#ifndef ROS2_TEMPLATE__SIMPLE_CLIENT_
#define ROS2_TEMPLATE__SIMPLE_CLIENT_

#include <chrono>

#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>

class SimpleClient : public rclcpp::Node
{
public:
    explicit SimpleClient(const rclcpp::NodeOptions &options);

private:
    void sendRequest(int64_t a, int64_t b);

    rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client_;
};

#endif  // ROS2_TEMPLATE__SIMPLE_CLIENT_