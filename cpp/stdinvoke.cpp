#include <functional>
#include <iostream>

int do_some(int c) { return 5 + c; }

struct S {
  int j = 333;
  int do_some(int c) { return j + c; }
  int do_some2(int c) { return j * c; }
};

int main() {
  std::cout << std::invoke(&do_some, 12) << '\n';
  S s;
  std::cout << s.do_some(3434) << '\n';

  // function pointer
  auto fp = &S::do_some;
  int (S::*fp2)(int) = nullptr;
  if (true) {
    fp2 = &S::do_some2;
  } else {
    fp2 = &S::do_some;
  }

  std::cout << (s.*fp)(2) << '\n';
  std::cout << (s.*fp2)(3) << '\n';
}