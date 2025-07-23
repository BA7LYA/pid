///
/// @file second_order_system.hxx
/// @author BA7LYA (1042140025@qq.com)
/// @brief
/// @version 0.1
/// @date 2025-07-23
/// @copyright Copyright (c) 2025
///

#pragma once

#include <cmath>
#include <utility>
#include <vector>

class system_response {
public:
    void add_data_point(double time, double value) { response_data.emplace_back(time, value); }

    const std::vector<std::pair<double, double>>& get_data() const { return response_data; }

    void clear() { response_data.clear(); }

private:
    std::vector<std::pair<double, double>> response_data;
};

///
/// @brief 二阶系统
///
class second_order_system {
public:
    second_order_system(double k, double omega_n, double zeta, double dt)
        : k_(k)
        , omega_n_(omega_n)
        , zeta_(zeta)
        , dt_(dt) {}

    system_response step_response(int steps) const {
        system_response response;
        double t = 0;

        for (int i = 0; i < steps; ++i) {
            double value = 0;
            if (zeta_ < 1) { value = underdamped_response(t); }
            else if (zeta_ > 1) { value = overdamped_response(t); }
            else { value = critically_damped_response(t); }
            response.add_data_point(t, value);
            t += dt_;
        }
        return response;
    }

    double transfer_function(double s) const {
        return k_ * omega_n_ * omega_n_ / (s * s + 2 * zeta_ * omega_n_ * s + omega_n_ * omega_n_);
    }

private:
    double underdamped_response(double t) const {
        double omega_d = omega_n_ * sqrt(1 - zeta_ * zeta_);
        return k_
             * (1
                - exp(-zeta_ * omega_n_ * t)
                      * (cos(omega_d * t) + zeta_ * omega_n_ / omega_d * sin(omega_d * t)));
    }

    double overdamped_response(double t) const {
        double alpha = omega_n_ * zeta_;
        double beta = omega_n_ * sqrt(zeta_ * zeta_ - 1);
        double term1 = exp(-(alpha - beta) * t) / (2 * beta * (alpha - beta));
        double term2 = exp(-(alpha + beta) * t) / (2 * beta * (alpha + beta));
        return k_ * (1 - (term1 - term2));
    }

    double critically_damped_response(double t) const {
        return k_ * (1 - (1 + omega_n_ * t) * exp(-omega_n_ * t));
    }

    double k_;
    double omega_n_;
    double zeta_;
    double dt_;
};
