#include "motor_pos_control.hpp"

MotorPosControl::MotorPosControl()
{
}

MotorPosControl::~MotorPosControl()
{
}

uint8_t *MotorPosControl::set_target_value(const int32_t pos)
{
    for(size_t i = 0; i < 4; i++)
    {
        send_data[i] = (pos >> (8 * i));
    }
    return send_data;
}
