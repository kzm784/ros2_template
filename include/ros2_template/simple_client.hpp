#ifndef ROS2_TEMPLATE__SIMPLE_CLIENT_
#define ROS2_TEMPLATE__SIMPLE_CLIENT_

#include <chrono>

#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/set_bool.hpp>

class SimpleClient : public rclcpp::Node
{
public:
    explicit SimpleClient(const rclcpp::NodeOptions &options);

private:
    void sendRequest(bool data);

    rclcpp::Client<std_srvs::srv::SetBool>::SharedPtr client_;
};

#endif  // ROS2_TEMPLATE__SIMPLE_CLIENT_