///
/// @file demo.cxx
/// @author BA7LYA (1042140025@qq.com)
/// @brief
/// @version 0.1
/// @date 2025-07-10
/// @copyright Copyright (c) 2025
///

#include <chrono>
#include <iostream>

#include "ba7lya/pid/pid_controller.hxx"

///
/// @brief 简单的一阶系统模型
/// @brief 状态更新公式：state += control_input * 0.1
/// @brief 状态值范围：[0, 10]
/// @brief 控制输入范围：[-10, 10]
/// @brief 控制器参数：Kp=0.5, Ki=0.1, Kd=0.2
/// @brief 目标状态值：10
/// @brief 模拟步数：1000
///
class system_model {
public:
    float update(const float control_input) {
        state_ += control_input * 0.1f;
        return state_;
    }

    void reset() { state_ = 0; }

    float state() const { return state_; }

private:
    float state_ = 0;
};

int main() {
    // 创建PID控制器 (Kp=0.5, Ki=0.1, Kd=0.2)
    ba7lya::pid::pid_controller pid(2.0f, 0.1f, 0.0f);

    system_model system;
    const float target = 10.0f; // 目标状态值
    const int steps = 1000;     // 模拟步数

    std::cout << "pid controller simulation:\n";
    std::cout << "target: " << target << "\n";

    for (int i = 0; i < steps; ++i) {
        float current = system.state();
        float control = pid.compute(target, current);
        float new_state = system.update(control);

        std::cout << "step," << i << ",current," << new_state << ",control," << control << "\n";

        // 当接近目标值时提前结束
        if (std::abs(target - new_state) < 0.001f) {
            std::cout << "target arrived\n";
            break;
        }
    }

    return 0;
}
