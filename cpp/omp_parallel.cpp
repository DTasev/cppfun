#include <cmath>
#include <vector>
int main() {

  const int size = 2 << 25;
  std::vector<double> sinTable;
  sinTable.resize(size);

#pragma omp parallel for
  for (int n = 0; n < size; ++n) {
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
    sinTable[n] = std::log10(std::sin(2 * M_PI * n / size));
  }
}