cmake_minimum_required(VERSION 3.0.2)
project(motor_control_msg)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  actual_value.msg
  target_pos_value.msg
  target_torque_value.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
 LIBRARIES motor_control_msg
 CATKIN_DEPENDS roscpp std_msgs message_runtime
)