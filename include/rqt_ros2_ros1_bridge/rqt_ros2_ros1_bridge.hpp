#pragma once

// ROS2
#include "rclcpp/rclcpp.hpp"
#include "ros1_bridge/bridge.hpp"

// msgs
#include "sensor_msgs/msg/point_cloud2.h"

// Rqt
#include "rqt_gui_cpp/plugin.h"

// Qt
#include <QWidget>

// Custom UI
#include "rqt_ros2_ros1_bridge/ui_rqt_ros2_ros1_bridge.h"

// ROS
#include "ros/ros.h"
#include "ros/callback_queue.h"

// STL
#include <vector>
#include <thread>

namespace util
{
    class ros1_handler
    {
    public:
        ros1_handler();
        ~ros1_handler();

        /// argc, argv
        int argc = 0; char ** argv = 0;

    };
} // namespace util

namespace rqt_plugin
{
  enum index {ros1_topic = 0, ros2_topic, ros1_type, ros2_type};

  class ROS2ROS1Bridge : public rqt_gui_cpp::Plugin, public util::ros1_handler
  {
    Q_OBJECT
    public:
      ROS2ROS1Bridge();

      virtual void initPlugin(qt_gui_cpp::PluginContext& context) override;

      virtual void shutdownPlugin() override;

      virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const override;

      virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings) override;

      virtual ~ROS2ROS1Bridge();

      private:
        Ui::gui ui_;
        QWidget * widget_;

      protected:
        /// ROS1 node handler
        ros::NodeHandle global_nh_;
        ros::CallbackQueue ros1_callback_queue_;

        /// Thread list
        std::vector<std::thread> thread_list_;

        /// ROS2 to ROS1 conversion pointer
        std::unique_ptr<ros1_bridge::Bridge2to1Handles> handler_;
      
      protected slots:
        void pointCloudConversionCheckbox();
  };
}  // namespace rqt_plugin