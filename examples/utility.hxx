///
/// @file utility.hxx
/// @author BA7LYA (1042140025@qq.com)
/// @brief
/// @version 0.1
/// @date 2025-07-23
/// @copyright Copyright (c) 2025
///

#pragma once

#include <array>
#include <iostream>
#include <stdexcept>
#include <string>

std::array<double, 3> parse_args(int argc, char* argv[]) {
    std::array<double, 3> args;
    for (int i = 1; i < argc; ++i) { // 跳过程序名argv[0]
        try {
            size_t pos;
            double value = std::stod(argv[i], &pos);

            // 检查是否整个字符串都被转换
            if (argv[i][pos] != '\0') {
                throw std::invalid_argument("trailing characters after number");
            }
            args[i - 1] = value;
        }
        catch (const std::exception& e) {
            std::cerr << "error parsing argument " << i << " (" << argv[i] << "): " << e.what()
                      << "\n";
            throw std::runtime_error("error parsing argument");
        }
    }
    return args;
}
