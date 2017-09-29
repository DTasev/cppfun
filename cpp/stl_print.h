#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

template <template <typename, typename> class Container, typename Value,
          typename Allocator = std::allocator<Value>>
void print(Container<Value, Allocator> &cont,
           const std::string &separator = " ", const std::string &end = "\n") {
  std::for_each(cont.begin(), cont.end(), [&separator, &end](const Value &n) {
    std::cout << n << separator;
  });
  std::cout << end;
}