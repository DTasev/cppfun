#include "stl_print.h"
#include <stdio.h>

struct A {
  A() = default;
  A(A &&a) { std::printf("I've been moved"); }
  void func() {}
};

int myfunc(A &&a) {
  std::printf("Im here");
  std::printf("Im here");
  std::printf("Im here");
  std::printf("Im here");
}

int main() {
  A mytype;
  myfunc(std::move(mytype));
  mytype.func();
}