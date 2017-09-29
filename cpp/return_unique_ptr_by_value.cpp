#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

template <class T> std::unique_ptr<std::vector<T>> unique_vector(int size) {
  auto vec = std::make_unique<std::vector<T>>(size);
  return vec;
}

int main(int argc, char **argv) {
  auto out = unique_vector<int>(3);

  std::cout << typeid(out).name() << "\n";
}

/*
------Output
g++ main.cpp --std=c++11 && ./ a.out
We got this output 1
We got this output word1


>> more info http://thbecker.net/articles/auto_and_decltype/section_05.html
>> even more info >>
http://www.cprogramming.com/c++11/c++11-auto-decltype-return-value-after-function.html
*/
