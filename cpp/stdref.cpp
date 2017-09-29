#include <functional>
#include <iostream>

template <class T> void print(T &i, const std::string &s) {
  std::cout << i << ' ' << s << '\n';
}

int main() {
  int i = 5;
  const auto f = [](const std::string &&arg1, auto &&arg2, auto &&...) {
    print(arg2, arg1);
  };
  //   const auto f = std::bind(&print<int>, std::ref(i),
  //   std::placeholders::_1);
  i = 6;
  f("Hello", 3, 3, 3, 3);
}