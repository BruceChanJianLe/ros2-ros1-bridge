#include "rqt_ros2_ros1_bridge/rqt_ros2_ros1_bridge.hpp"
#include <pluginlib/class_list_macros.hpp>
#include <QString>

PLUGINLIB_EXPORT_CLASS(rqt_plugin::ROS2ROS1Bridge, rqt_gui_cpp::Plugin)

namespace util
{
    ros1_handler::ros1_handler()
    {
        ros::init(argc, argv, "ghost_heartbeat_manager");
    }

    ros1_handler::~ros1_handler()
    {
    }
} // namespace util

namespace rqt_plugin
{
    ROS2ROS1Bridge::ROS2ROS1Bridge()
    :   rqt_gui_cpp::Plugin()
    ,   ros1_handler()
    ,   widget_(0)
    {
    }

    void ROS2ROS1Bridge::initPlugin(qt_gui_cpp::PluginContext& context)
    {
        // Access standalone command line arguments
        QStringList argv = context.argv();

        // Create QWidget
        widget_ = new QWidget();

        // Extend the widget with all attributes and children from UI file
        ui_.setupUi(widget_);

        // add widget to the user interface
        context.addWidget(widget_);

        // Setup 
        std::tuple<std::string, std::string, std::string, std::string> ros2_to_ros1_pair = {"/vision60_points", "/mcu/state/pointcloud", "sensor_msgs/PointCloud2", "sensor_msgs/msg/PointCloud2"};
        constexpr std::size_t queue_size = 1;

        // ROS1 related declaration
        global_nh_ = ros::NodeHandle("");
        // global_nh_.setCallbackQueue(&ros1_callback_queue_);

        auto handle = ros1_bridge::create_bridge_from_2_to_1(
            node_, global_nh_,
            std::get<index::ros2_type>(ros2_to_ros1_pair),
            std::get<index::ros2_topic>(ros2_to_ros1_pair),
            queue_size,
            std::get<index::ros1_type>(ros2_to_ros1_pair),
            std::get<index::ros1_topic>(ros2_to_ros1_pair),
            queue_size
        );

        // Connect with Qt Widget
        connect(ui_.ros2PCtoRos1PC, SIGNAL(stateChanged(int)), this, SLOT(pointCloudConversionCheckbox()));

        // Spin ROS1
        // thread_list_.emplace_back(std::move(std::thread([this](){ros::SingleThreadedSpinner spinner; spinner.spin(&this->ros1_callback_queue_);})));
        ros::AsyncSpinner async_spinner{1};
        async_spinner.start();
    }

    void ROS2ROS1Bridge::shutdownPlugin()
    {
        ;
    }

    void ROS2ROS1Bridge::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
    {
        ;
    }

    void ROS2ROS1Bridge::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
    {
        ;
    }

    ROS2ROS1Bridge::~ROS2ROS1Bridge()
    {
        if(widget_)
            delete widget_;

        for(auto & thread : this->thread_list_)
        {
            if(thread.joinable())
                thread.join();
        }
    }

    void ROS2ROS1Bridge::pointCloudConversionCheckbox()
    {
        if(ui_.ros2PCtoRos1PC->isChecked())
        {
            ;
        }
        else
        {
            ;
        }
    }

    // void ROS2ROS1Bridge::button2Callback()
    // {
    //     button2_pub_->publish(msg_);
    // }

} // namespace rqt_plugin