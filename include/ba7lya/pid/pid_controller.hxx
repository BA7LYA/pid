///
/// @file pid_controller.hxx
/// @author BA7LYA (1042140025@qq.com)
/// @brief
/// @version 0.1
/// @date 2025-07-10
/// @copyright Copyright (c) 2025
///

#pragma once

#include <chrono>

namespace ba7lya::pid {

///
/// @brief PID Controller
///
class pid_controller {
public:
    pid_controller(
        const float kp,
        const float ki,
        const float kd,
        const float historical_integral = 0,
        const float last_error_value = 0
    )
        : kp_(kp)
        , ki_(ki)
        , kd_(kd)
        , historical_integral_(historical_integral)
        , last_error_value_(last_error_value)
        , last_time_(std::chrono::high_resolution_clock::now()) {}

    void set_gain(const float kp, const float ki, const float kd) {
        kp_ = kp;
        ki_ = ki;
        kd_ = kd;
    }

    float compute(const float set_point, const float process_variable) {
        // now time
        auto now_time = std::chrono::high_resolution_clock::now();

        // delta time
        std::chrono::duration<float> delta_time = now_time - last_time_;
        float dt = delta_time.count();

        // 时间差保护
        if (dt <= 0.0001f) { dt = 0.0001f; }

        // error value
        float now_error_value = set_point - process_variable;

        // calculate P term
        float p_term = kp_ * now_error_value;

        // calculate I term
        float i_term = historical_integral_ + ki_ * now_error_value * dt;

        // calculate D term
        float d_term = kd_ * ((now_error_value - last_error_value_) / dt);

        // 更新状态
        historical_integral_ = i_term;
        last_error_value_ = now_error_value;
        last_time_ = now_time;

        // return u(t)
        return p_term + i_term + d_term;
    }

private:
    // P/I/D Gain
    float kp_, ki_, kd_;

    // Historical Integral since the launch of PID Controller
    float historical_integral_;

    // the Error Value of last step
    float last_error_value_;

    // the Time when calc last time
    std::chrono::time_point<std::chrono::high_resolution_clock> last_time_;
};

} // namespace ba7lya::pid
