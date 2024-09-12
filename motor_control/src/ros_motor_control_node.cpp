#include "motor_control/ros_motor_control.hpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ros_motor_control");
    RosMotorControl ros_motor_control;

    ros::Rate loop_rate(100);

    while(ros::ok())
    {
        ros_motor_control.publish_actual_data();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}