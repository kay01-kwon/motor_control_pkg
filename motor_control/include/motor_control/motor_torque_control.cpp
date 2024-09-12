#include "motor_torque_control.hpp"

MotorTorqueControl::MotorTorqueControl()
{
}

uint8_t *MotorTorqueControl::set_target_value(const int torque)
{
    for(size_t i = 0; i < 2; i++)
    {
        send_data[i] = (torque >> (8 * i));
    }
    return send_data;
}