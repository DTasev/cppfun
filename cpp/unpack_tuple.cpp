#include <iostream>
#include <string>
#include <tuple>
#include <utility>

std::pair<int, std::string> f() { return std::make_pair(5, "test"); }
int main() {
  decltype(f().first) first;
  decltype(f().second) second;
  std::tie(first, second) = f();

  std::cout << first << " " << second << '\n';
  return 0;
}