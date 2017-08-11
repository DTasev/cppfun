#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

inline void timeit(const std::function<void()> &to_be_timed, const size_t iterations,
            const std::string &name = "Test") {
  std::cout << "Iterations: " << iterations << '\n';
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::vector<double> times;

  for (size_t i = 0; i < iterations; ++i) {
    start = std::chrono::system_clock::now();
    to_be_timed();
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    times.emplace_back(elapsed.count());
  }

  double result = std::accumulate(times.cbegin(), times.cend(), 0.0);

  std::cout << name << " Elapsed time: " << result << '\n';
  std::cout << name << " Average time: " << result / times.size() << '\n';
}