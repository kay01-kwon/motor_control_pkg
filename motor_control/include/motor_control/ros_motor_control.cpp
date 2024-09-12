#include "ros_motor_control.hpp"

RosMotorControl::RosMotorControl()
{
    string mode_string, ip_addr;
    int port;
    nh_.getParam("mode", mode_string);
    nh_.getParam("ip_addr", ip_addr);
    nh_.getParam("port", port);

    MotorControlMode mode_;

    if (mode_string == "position")
    {
        mode_ = MotorControlMode::POSITION;
        motor_control_ = MotorControl::create_motor_control(mode_);
        sub_ = nh_.subscribe("target_pos", 1, &RosMotorControl::callback_pos, this);
    }
    else if (mode_string == "torque")
    {
        mode_ = MotorControlMode::TORQUE;
        motor_control_ = MotorControl::create_motor_control(mode_);
        sub_ = nh_.subscribe("target_torque", 1, &RosMotorControl::callback_torque, this);
    }
    else
    {
        ROS_ERROR("Invalid mode: %s", mode_string.c_str());
        ros::shutdown();
    }

    pub_ = nh_.advertise<motor_control_msg::actual_value>("actual_data", 1);

    socket_client_ = SocketClientImpl(ip_addr, port);

    // Create socket client
    if(socket_client_.create_socket() == -1)
    {
        ROS_ERROR("Failed to create socket");
        ros::shutdown();
    }

    // Connect to server
    if(socket_client_.socket_connect() == -1)
    {
        ROS_ERROR("Failed to connect to server");
        ros::shutdown();
    }


}