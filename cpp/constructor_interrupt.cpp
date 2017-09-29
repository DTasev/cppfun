#include <memory>
#include <stdio.h>

struct A {

  A(int *ff) {
    ff = new int(300);
    some_memory = ff;
    throw new std::runtime_error("omg");
  }

  ~A() {
    delete some_memory;
    printf("I have been destroyed");
  }
  int *some_memory = nullptr;
};

int main() {
  int *ff = nullptr;
  try {
    A a(ff);
  } catch (...) {
    printf("we leaked\n%d", *ff);
  }
  printf("we didnt throw\n%d", *ff);
}