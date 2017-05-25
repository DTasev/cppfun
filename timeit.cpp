#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

static const int iters = 100;
static const int N = 1000000;

class MyClass {
public:
  MyClass(int d) : _d(d) {}
  int _d = 0;
};

void timeit(const std::function<void()> &to_be_timed, const size_t iterations,
            const std::string &name) {
  std::cout << "Iterations: " << iterations << '\n';
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::vector<double> times;

  for (int i = 0; i < iterations; ++i) {
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

int main(int argc, char **argv) {
  std::vector<std::string> v1, v2;
  v1.reserve(N * iters);
  v2.reserve(N * iters);
  auto push = [&v1]() mutable {
    for (int i = 0; i < N; ++i) {
      v1.push_back("test");
    }
  };

  auto emplace = [&v2]() mutable {
    for (int i = 0; i < N; ++i) {
      v2.emplace_back("boop");
    }
  };

  timeit(push, iters, "(push_back)");
  timeit(emplace, iters, "(emplace_back)");
}