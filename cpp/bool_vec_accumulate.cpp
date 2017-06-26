#include <numeric>
#include <stdio.h>
#include <vector>

int main() {
  std::vector<bool> vec = {true, true, true};

  printf("%d\n", std::accumulate(vec.begin(), vec.end(), 0));
}