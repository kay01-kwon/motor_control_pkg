#ifndef ROS_MOTOR_CONTROL_HPP
#define ROS_MOTOR_CONTROL_HPP
#include <ros/ros.h>

#include "motor_control.hpp"
#include "motor_torque_control.hpp"
#include "motor_pos_control.hpp"

#include "socket_client_impl.hpp"

#include "scoped_ptr.hpp"

#include "motor_control_msg/actual_value.h"
#include "motor_control_msg/target_pos_value.h"
#include "motor_control_msg/target_torque_value.h"

using motor_control_msg::actual_valueConstPtr;
using motor_control_msg::target_pos_valueConstPtr;
using motor_control_msg::target_torque_valueConstPtr;

class RosMotorControl
{
    public:

    RosMotorControl();

    void publish_actual_data();


    private:

    void callback_pos(const target_pos_valueConstPtr& msg);

    void callback_torque(const target_torque_valueConstPtr& msg);

    ros::NodeHandle nh_;

    ros::Subscriber sub_;
    ros::Publisher pub_;

    scoped_ptr<MotorControl> motor_control_;

    SocketClientImpl socket_client_;

    uint8_t* send_data_ptr;
    uint8_t recv_data[20];

};

#endif