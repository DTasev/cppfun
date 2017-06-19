#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<int *> a = std::make_unique<int *>(new int(3));

  if (!a) {
    std::cout << "The unique ptr is nullptr!" << std::endl;
  }
  a.reset();
  if (!a) {
    std::cout << "2 :: The unique ptr is nullptr!" << '\n';
  }
}