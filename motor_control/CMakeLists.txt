cmake_minimum_required(VERSION 3.0.2)
project(motor_control)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES motor_control
 CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_INCLUDE_DESTINATION}
)

add_executable(motor_control_node 
src/ros_motor_control_node.cpp 
include/motor_control/ros_motor_control.cpp
include/motor_control/motor_pos_control.cpp
include/motor_control/motor_torque_control.cpp
include/motor_control/socket_client_impl.cpp)

target_link_libraries(motor_control_node
  ${catkin_LIBRARIES}
)