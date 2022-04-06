cmake_minimum_required(VERSION 3.8)
project(ros2-ros1-bridge)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ros1_bridge REQUIRED)
find_package(roscpp REQUIRED)

set(req_deps
  rclcpp
  rclcpp_components
  ros1_bridge
  std_msgs
  sensor_msgs
)

# ament_auto_find_build_dependencies(REQUIRED ${req_deps})

add_executable(ros2_ros1_bridge_node
  src/main.cpp
)
target_link_libraries(ros2_ros1_bridge_node
  ${roscpp_LIBRARIES}
)
ament_target_dependencies(ros2_ros1_bridge_node rclcpp ros1_bridge std_msgs sensor_msgs)

install(
  TARGETS ros2_ros1_bridge_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
