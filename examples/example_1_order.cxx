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
#include <stdexcept>

#include "ba7lya/pid/pid_controller.hxx"
#include "first_order_system.hxx"
#include "utility.hxx"

using namespace ba7lya::pid;

int main(int argc, char* argv[]) {
    // 参数个数校验
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <Kp> <Ki> <Kd>\n";
        return 1;
    }

    // 参数解析
    auto args = parse_args(argc, argv);
    double Kp = args[0];
    double Ki = args[1];
    double Kd = args[2];

    // 参数范围校验
    if (Kp < 0 || Kp > 100 || Ki < 0 || Ki > 100 || Kd < 0 || Kd > 100) {
        std::cerr << "error: Kp, Ki, Kd out of range\n";
        throw std::runtime_error("error: Kp, Ki, Kd out of range");
        return 1;
    }

    // 创建PID控制器
    pid_controller pid(Kp, Ki, Kd);

    // 创建系统
    first_order_system system(2, 0.5, 0.01);
    const float target = 10.0f; // 目标状态值
    const int steps = 30;       // 模拟步数

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
