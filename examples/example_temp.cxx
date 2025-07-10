///
/// @file example_heat.cxx
/// @author BA7LYA (1042140025@qq.com)
/// @brief
/// @version 0.1
/// @date 2025-07-10
/// @copyright Copyright (c) 2025
///

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "ba7lya/pid/pid_controller.hxx"

// 模拟的温度系统
class temperature_system {
public:
    temperature_system(const float initial_temp = 25.0f)
        : current_temp_(initial_temp)
        , heater_power_(0.0f) {}

    float update(const float control_signal, const float dt) {
        // 简单的热力学模型
        heater_power_ = std::clamp(control_signal, 0.0f, 100.0f); // 限制加热功率
        float heat_input = heater_power_ * 0.1f;
        float heat_loss = (current_temp_ - ambient_temp) * 0.02f;
        current_temp_ += (heat_input - heat_loss) * dt;
        return current_temp_;
    }

    float get_temperature() const { return current_temp_; }

private:
    float current_temp_;
    float heater_power_;
    const float ambient_temp = 25.0f; // 环境温度
};

int main() {
    // 创建PID控制器 (Kp, Ki, Kd)
    ba7lya::pid::pid_controller pid(2.0f, 0.5f, 1.0f);

    // 创建温度系统
    temperature_system system;

    // 控制参数
    const float targetTemp = 80.0f; // 目标温度80°C
    const float dt = 0.1f;          // 模拟时间步长(秒)
    const int steps = 200;          // 模拟步数

    // 记录数据用于绘图
    std::vector<float> temps;
    std::vector<float> controls;

    // 模拟循环
    for (int i = 0; i < steps; ++i) {
        float currentTemp = system.get_temperature();
        float control = pid.compute(targetTemp, currentTemp);
        system.update(control, dt);

        // 记录数据
        temps.push_back(currentTemp);
        controls.push_back(control);

        // 打印状态
        std::cout << "step " << i << ": temp=" << currentTemp << "^c, control=" << control << "%"
                  << std::endl;
    }

    // 这里可以添加代码将temps和controls数据保存到文件
    // 以便用Python或其他工具绘制响应曲线

    return 0;
}
