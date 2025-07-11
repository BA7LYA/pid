///
/// @file example_2_order.cxx
/// @author BA7LYA (1042140025@qq.com)
/// @brief
/// @version 0.1
/// @date 2025-07-11
/// @copyright Copyright (c) 2025
///

#include "ba7lya/pid/pid_controller.hxx"

class second_order_system {
public:
    struct state {
        float pos; // 位置状态
        float vel; // 速度状态
    };

    state update(float control_input, float dt) {
        // 计算加速度 (根据二阶微分方程)
        float acc = (control_input - damping_ * current_.vel - stiffness_ * current_.pos) / mass_;

        // 更新状态
        current_.vel += acc * dt;
        current_.pos += current_.vel * dt;

        return current_;
    }

    void reset() { current_ = { 0, 0 }; }

private:
    state current_;
    float mass_ = 1.0f;      // 质量参数
    float damping_ = 0.1f;   // 阻尼系数
    float stiffness_ = 1.0f; // 刚度系数
};

int main(int argc, const char* argv[]) {
    /* code */
    return 0;
}
