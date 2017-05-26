#include <string>
#include <vector>

#include "timeit.h"

static const int iters = 100;
static const int N = 100;

class MyClass {
public:
  MyClass(int d) : _d(d) {}
  int _d = 0;
};

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