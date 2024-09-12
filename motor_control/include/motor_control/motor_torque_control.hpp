#ifndef MOTOR_TORQUE_CONTROL_HPP
#define MOTOR_TORQUE_CONTROL_HPP
#include <iostream>
#include "motor_control.hpp"


class MotorTorqueControl : public MotorControl
{
    public:

    MotorTorqueControl();

    virtual ~MotorTorqueControl();

    uint8_t* set_target_value(const int torque) override;

};

#endif