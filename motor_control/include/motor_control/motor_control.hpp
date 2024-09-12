#ifndef MOTOR_CONTROL_HPP
#define MOTOR_CONTROL_HPP
#include <iostream>
#include <cassert>

enum class MotorControlMode{
    TORQUE,
    POSITION
};

class MotorControl{

    public:


    MotorControl();

    virtual ~MotorControl();

    virtual uint8_t* set_target_value(const int target) = 0;

    static MotorControl* create_motor_control(MotorControlMode mode);

    int16_t get_actual_torque(const uint8_t* data);

    int32_t get_actual_pos(const uint8_t* data);

    int32_t get_actual_vel(const uint8_t* data);

    protected:

    int16_t actual_torque_;
    int32_t actual_pos_;
    int32_t actual_vel_;

    uint8_t send_data[20];

};



#endif