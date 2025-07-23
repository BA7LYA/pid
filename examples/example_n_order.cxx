///
/// @file example_n_order.cxx
/// @author BA7LYA (1042140025@qq.com)
/// @brief
/// @version 0.1
/// @date 2025-07-11
/// @copyright Copyright (c) 2025
///

#include <Eigen/Eigen>

#include "ba7lya/pid/pid_controller.hxx"

class high_order_system {
public:
    using state_vector = Eigen::VectorXf;

    state_vector update(const state_vector& control_input, float dt) {
        // 状态空间方程离散化
        state_vector derivative = A_ * state_ + B_ * control_input;
        state_ += derivative * dt;
        return state_;
    }

    void reset() { state_.setZero(); }

private:
    state_vector state_; // 状态向量
    Eigen::MatrixXf A_;  // 状态矩阵
    Eigen::MatrixXf B_;  // 输入矩阵
};

int main(int argc, const char* argv[]) {
    // TODO
    return 0;
}
