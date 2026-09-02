#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include "mlp.hpp"

int main(int argc, char* argv[]) {
    long iterations = 10000000; // 10 million inferences
    if (argc > 1) {
        iterations = std::atol(argv[1]);
    }

    const data_t test_input[INPUT_NODES] = {0.5f, -0.2f, 0.8f, 0.1f, -0.4f, 0.6f, -0.1f, 0.3f};
    data_t output[OUTPUT_NODES];

    // Warmup cache
    for (int i = 0; i < 10000; ++i) {
        mlp_accel(test_input, output);
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    for (long i = 0; i < iterations; ++i) {
        mlp_accel(test_input, output);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> total_seconds = end_time - start_time;

    double total_time_sec = total_seconds.count();
    double avg_latency_ns = (total_time_sec * 1e9) / iterations;
    double avg_latency_us = (total_time_sec * 1e6) / iterations;
    double throughput_ips = iterations / total_time_sec;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "BENCHMARK_RESULT:ITERATIONS=" << iterations << std::endl;
    std::cout << "BENCHMARK_RESULT:TOTAL_TIME_SEC=" << total_time_sec << std::endl;
    std::cout << "BENCHMARK_RESULT:AVG_LATENCY_NS=" << avg_latency_ns << std::endl;
    std::cout << "BENCHMARK_RESULT:AVG_LATENCY_US=" << avg_latency_us << std::endl;
    std::cout << "BENCHMARK_RESULT:THROUGHPUT_IPS=" << throughput_ips << std::endl;

    return 0;
}
