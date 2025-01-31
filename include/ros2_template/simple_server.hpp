#ifndef ROS2_TEMPLATE__SIMPLE_SERVER_
#define ROS2_TEMPLATE__SIMPLE_SERVER_

#include <thread>
#include <rclcpp/rclcpp.hpp>
#include "std_srvs/srv/set_bool.hpp"

class SimpleServer : public rclcpp::Node
{
public:
    explicit SimpleServer(const rclcpp::NodeOptions &options);

private:
    void handleService(
        const std_srvs::srv::SetBool::Request::SharedPtr request,
        const std_srvs::srv::SetBool::Response::SharedPtr response);
    
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr server_;
};

#endif  // ROS2_TEMPLATE__SIMPLE_SERVER_
