#include <iostream>
#include <vector>

template <class T>
auto function_with_some_return(const std::vector<T> &vector)
    -> decltype(vector[0]) {
  return vector[0];
}

int main(int argc, char **argv) {
  std::vector<int> vec_int = {1, 2, 3, 4, 5, 6};
  std::vector<std::string> vec_str = {"word1", "bar", "foo"};
  auto output_from_int = function_with_some_return(vec_int);
  auto output_from_str = function_with_some_return(vec_str);

  std::cout << "We got this output " << output_from_int << "\n";
  std::cout << "We got this output " << output_from_str << "\n";
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
