///
/// @file benchmark.cxx
/// @author BA7LYA (1042140025@qq.com)
/// @brief
/// @version 0.1
/// @date 2025-07-10
/// @copyright Copyright (c) 2025
///

#include <benchmark/benchmark.h>
#include <chrono>
#include <ode/ode.h>
#include <thread>

static void BM_SomeFunction(benchmark::State& state) {
    // Perform setup here
    for (auto _ : state) { std::this_thread::sleep_for(std::chrono::milliseconds(1)); }
}

// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
