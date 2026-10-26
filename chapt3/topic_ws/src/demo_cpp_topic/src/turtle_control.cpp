#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include "turtlesim/msg/pose.hpp"

class TurtleControlNode : public rclcpp::Node
{
private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
    double target_x_{1.0};
    double target_y_{1.0};
    double k_{1.0}; // Proportional gain for linear velocity
    double max_speed_{3.0}; // Maximum speed limit
    
public:
  explicit TurtleControlNode(const std::string& node_name): Node(node_name)
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
    subscriber_ = this->create_subscription<turtlesim::msg::Pose>(
        "turtle1/pose", 
        10,
        std::bind(
            &TurtleControlNode::on_pose_received_, 
            this, 
            std::placeholders::_1
        )
    );
  }

  void on_pose_received_(const turtlesim::msg::Pose::SharedPtr pose)
  {
    // 1.获取当前的位置
    auto current_x = pose->x;
    auto current_y = pose->y;
    RCLCPP_INFO(
        this->get_logger(), 
        "Current Position: x=%.2f, y=%.2f", current_x, current_y);
    
    // 2.计算与目标点的距离
    auto distance = std::sqrt(
        std::pow(target_x_ - current_x, 2) + 
        std::pow(target_y_ - current_y, 2)
    );
    auto angle = std::atan2(
        target_y_ - current_y, 
        target_x_ - current_x) 
        - pose->theta;

    // 3.控制策略
    auto msg = geometry_msgs::msg::Twist();
    if (distance > 0.1) // If the turtle is far from the target
    {
        if (fabs(angle) > 0.2){
            msg.angular.z = fabs(angle); 
        }
        else{
            msg.linear.x = k_ * distance; 
        }
    }

    // 4.速度限制
    if (msg.linear.x > max_speed_) {
        msg.linear.x = max_speed_;
    }
    
    publisher_->publish(msg);
  }
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<TurtleControlNode>("turtle_control");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}