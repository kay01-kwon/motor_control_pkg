#ifndef MOTOR_POS_CONTROL_HPP
#define MOTOR_POS_CONTROL_HPP
#include <iostream>
#include "motor_control.hpp"

class MotorPosControl : public MotorControl
{
    public:

    MotorPosControl();

    virtual ~MotorPosControl();

    uint8_t* set_target_value(const int pos) override;

};

#endif