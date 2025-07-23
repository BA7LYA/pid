///
/// @file first_order_system.hxx
/// @author BA7LYA (1042140025@qq.com)
/// @brief
/// @version 0.1
/// @date 2025-07-23
/// @copyright Copyright (c) 2025
///

#pragma once

#include <cmath>

///
/// @brief 一阶系统
///
class first_order_system {
public:
    /// @brief 构造函数
    /// @param gain 系统增益
    /// @param time_const 时间常数
    /// @param step_time 仿真步长
    first_order_system(const double gain, const double time_const, const double step_time)
        : K_(gain)
        , T_(time_const)
        , dt_(step_time)
        , y_prev_(0.0) {}

    double update(const double input) {
        // 欧拉法离散化: dy/dt ≈ (y[n] - y[n-1])/dt
        double y_current = (K_ * dt_ * input + T_ * y_prev_) / (T_ + dt_);
        y_prev_ = y_current;
        return y_current;
    }

    double state() const { return y_prev_; }

    void reset() { y_prev_ = 0.0; }

private:
    double K_;      // 系统增益
    double T_;      // 时间常数
    double y_prev_; // 前次输出值
    double dt_;     // 仿真步长
};
