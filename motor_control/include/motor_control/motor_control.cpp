#include "motor_control.hpp"
#include "motor_torque_control.hpp"
#include "motor_pos_control.hpp"

MotorControl::MotorControl()
{
}

MotorControl::~MotorControl()
{
}

int16_t MotorControl::get_actual_torque(const uint8_t* data)
{
    actual_torque_ = 0;

    for(size_t i = 0; i < 2; i++)
    {
        actual_torque_ = actual_torque_ | (data[i] << (8 * i));
    }
    return actual_torque_;
}

MotorControl *MotorControl::create_motor_control(MotorControlMode mode)
{

    switch(mode)
    {
        case MotorControlMode::TORQUE:
            return new MotorTorqueControl();
        case MotorControlMode::POSITION:
            return new MotorPosControl();
    }

    assert(mode == MotorControlMode::TORQUE || mode == MotorControlMode::POSITION);

    return nullptr;
}

int32_t MotorControl::get_actual_pos(const uint8_t* data)
{
    actual_pos_ = 0;

    for(size_t i = 2; i < 6; i++)
    {
        actual_pos_ = actual_pos_ | (data[i] << (8 * (i - 2)));
    }
    return actual_pos_;
}

int32_t MotorControl::get_actual_vel(const uint8_t* data)
{
    actual_vel_ = 0;

    for(size_t i = 6; i < 10; i++)
    {
        actual_vel_ = actual_vel_ | (data[i] << (8 * (i - 6)));
    }
    return actual_vel_;
}
