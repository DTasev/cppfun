#include <algorithm>
#include <chrono>
#include <stdexcept>
#include <stdlib.h>
#include <vector>

int main() {
  int n = 10000000;
  std::vector<double> input(n);
  for (int i = 0; i < n; ++i) {
    input[i] = i;
  }

  std::vector<float> X(n);
  const auto start1 = std::chrono::system_clock::now();
  for (int i = 0; i < X.size(); ++i) {
    X[i] = static_cast<float>(input[i]);
  }

  const auto end1 = std::chrono::system_clock::now();

  std::vector<float> X1(n);
  const auto start2 = std::chrono::system_clock::now();

  std::transform(input.cbegin(), input.cend(), X1.begin(),
                 [](double x) { return static_cast<float>(x); });

  const auto end2 = std::chrono::system_clock::now();

  std::vector<float> X2(n);
  const auto start3 = std::chrono::system_clock::now();
  for (auto &i : X2) {
    i = static_cast<float>(input[i]);
  }
  const auto end3 = std::chrono::system_clock::now();

  printf("with for   : %12lu\n", (end1 - start1).count());
  printf("with trans : %12lu\n", (end2 - start2).count());
  printf("with ranged: %12lu\n", (end3 - start3).count());
}