// ROS2
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "ros1_bridge/bridge.hpp"

// ROS1
#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"

// STL
#include <chrono>
#include <tuple>
#include <string>

// enum int 

int main(int argc, char ** argv)
{
  /* initialize ROS 1 */
  ros::init(argc, argv, "ros2_ros1_bridge");
  ros::NodeHandle ros1_nh{};


  /* initialize ROS 2 */
  rclcpp::init(argc, argv);
  auto ros2_node = rclcpp::Node::make_shared("ros2_ros1_bridge");

  std::tuple<std::string, std::string, std::string, std::string> ros2_to_ros1_pair = {"/vision60_points", "/mcu/command/pointcloud", "sensor_msgs/PointCloud2", "sensor_msgs/msg/PointCloud2"};

  constexpr std::size_t queue_size = 10;

  ros1_bridge::Bridge2to1Handles handle = ros1_bridge::create_bridge_from_2_to_1(ros2_node, ros1_nh, ros2type, topic, queue_size, ros1type, topic, queue_size);

  /* ROS 1 async spinner */
  ros::AsyncSpinner async_spinner{1};
  async_spinner.start();

  /* ROS 2 spin loop */
  rclcpp::executors::SingleThreadedExecutor executor;
  while(ros1_nh.ok() && rclcpp::ok())
  {
    executor.spin_node_once(ros2_node, std::chrono::milliseconds(1));
  }

  return 0;
}