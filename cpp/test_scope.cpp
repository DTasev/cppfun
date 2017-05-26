#include <iostream>
#include <memory>
#include <stdio.h>

class A {
public:
  A() = delete;
  A(int abc) : _abc(abc) {}

  int _abc;
};

int main() {
  A *temp; // cannot because default deleted
  if (true) {
    temp = &A(3);
  } else {
    temp = &A(5);
  }

  std::cout << temp->_abc;
}