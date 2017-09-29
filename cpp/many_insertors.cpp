#include "stl_print.h"
#include <algorithm>
#include <deque>
#include <iterator>
#include <vector>

class MyClass {
public:
  MyClass(int n) : _n(n) {}
  friend std::ostream &operator<<(std::ostream &os, const MyClass &dt) {
    os << dt._n;
    return os;
  }

  inline bool operator==(const MyClass &rhs) const { return _n == rhs._n; }

private:
  int _n;
};

int main() {

  std::vector<MyClass> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Before:" << '\n';
  print(vec);

  // removes in place
  std::remove_if(vec.begin(), vec.end(),
                 [](const MyClass &n) { return n == 3; });
  print(vec);

  // remove_copy_if does NOT modify the original container!
  // it produces a copy that has the function applied to it

  // declare variable of the same type as vec
  decltype(vec) newvec_backinserter;

  std::deque<MyClass> deque;
  std::remove_copy_if(vec.begin(), vec.end(), std::back_inserter(deque),
                      [](const MyClass &n) { return n == 5; });

  std::deque<MyClass> deque_fr;
  std::remove_copy_if(vec.begin(), vec.end(), std::front_inserter(deque_fr),
                      [](const MyClass &n) { return n == 5; });

  std::cout << "The old vec is unchanged:" << '\n';
  print(vec);
  std::cout << "And deque front inserter:" << '\n';
  print(deque_fr);
  std::cout << "And deque back inserter:" << '\n';
  print(deque);

  return 0;
}