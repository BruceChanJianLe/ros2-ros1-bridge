# ROS2 ros1_bridge

This repository demonstrates the proper usage of ros1_bridge in ROS2.

## Content

- [Content](#Content)
- [Source It Right](#Source-It-Right)
- [Usage](#Usage)

## Source It Right

Before running the ros1_bridge package you will have to go through a few steps.  

**Terminal 1**  
1. Source ROS1 setup.bash
1. Have a roscore running

**Terminal 2**  
1. Export ROS_MASTER_URI which is obtained from terminal 1
1. Source ROS1 setup.bash
1. Source ROS2 local_setup.bash
1. Run ros1_bridge (refer to usage section for more information)

## Usage

This is the help menu of ros1_bridge (updated on 21st Oct 2020).  

```bash
Usage:
 -h, --help: This message.
 --show-introspection: Print output of introspection of both sides of the bridge.
 --print-pairs: Print a list of the supported ROS 2 <=> ROS 1 conversion pairs.
 --bridge-all-topics: Bridge all topics in both directions, whether or not there is a matching subscriber.
 --bridge-all-1to2-topics: Bridge all ROS 1 topics to ROS 2, whether or not there is a matching subscriber.
 --bridge-all-2to1-topics: Bridge all ROS 2 topics to ROS 1, whether or not there is a matching subscriber.
```

### ROS2 to ROS1
```
```

## Reference

- ros1_bridge source code [link](https://github.com/ros2/ros1_bridge)