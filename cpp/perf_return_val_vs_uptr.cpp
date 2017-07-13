#include "stl_print.h"
#include "timeit.h"

#include <iostream>
#include <memory>
#include <stdlib.h>
#include <vector>

// uncomment to print out which object is destructed
// #define DESTRUCTION

class MyScreamingClass {
public:
  MyScreamingClass(const std::vector<int> &&a)
      : _a(std::move(a)), myid(vector_id++) {
    std::cout << "Created id" << myid << '\n';
  }
  ~MyScreamingClass() { std::cout << "I'm dying, id:" << myid << '\n'; }

private:
  static int vector_id;
  const int myid;
  std::vector<int> _a;
};

int MyScreamingClass::vector_id = 0;
#ifdef DESTRUCTION

using MyType = MyScreamingClass;
// using MyType = int;
static const int N = 5;
static const int ITERS = 1;
#else
using TheDataType = int;
using MyType = std::vector<TheDataType>;
static const int N = 1000;
static const int ITERS = 30000;
#endif

// TODO copy settings from workpc, + snippets
std::vector<MyType> *return_ptr(const std::vector<MyType> &vec) {
  auto newvec = new std::vector<MyType>();
  newvec->reserve(vec.size());
  for (int i = 0; i < N; ++i) {
    newvec->emplace_back(vec[i]);
  }
  return newvec;
}
std::unique_ptr<std::vector<MyType>>
return_unique(const std::vector<MyType> &vec) {
  auto newvec = std::make_unique<std::vector<MyType>>();
  newvec->reserve(vec.size());
  for (int i = 0; i < N; ++i) {
    newvec->emplace_back(vec[i]);
  }
  return newvec;
}
std::unique_ptr<std::vector<MyType>>
return_unique2(const std::vector<MyType> &vec) {
  auto newvec = std::vector<MyType>();

  newvec.reserve(vec.size());
  for (int i = 0; i < N; ++i) {
    newvec.emplace_back(vec[i]);
  }

  // if we don't have a move a copy is made
  return std::make_unique<std::vector<MyType>>(std::move(newvec));
}
std::unique_ptr<std::vector<MyType>>
return_unique3(const std::vector<MyType> &vec) {
  auto newvec = new std::vector<MyType>();
  newvec->reserve(vec.size());
  for (int i = 0; i < N; ++i) {
    newvec->emplace_back(vec[i]);
  }
  return std::unique_ptr<std::vector<MyType>>(newvec);
}

std::vector<MyType> return_by_value(const std::vector<MyType> &vec) {
  auto newvec = std::vector<MyType>();
  newvec.reserve(vec.size());
  for (int i = 0; i < N; ++i) {
    newvec.emplace_back(vec[i]);
  }
  return newvec;
}

void noreturn(const std::vector<MyType> &vec, std::vector<MyType> &out) {
  for (int i = 0; i < N; ++i) {
    out.emplace_back(vec[i]);
  }
}

int main(int argc, char **argv) {

  std::vector<MyType> vec;
  for (int i = 0; i < N; ++i) {
    vec.emplace_back(std::vector<TheDataType>{
        3,   4, 5,  6, 4,  14,  14, 1,  41, 41,  41, 4,   35,
        314, 1, 35, 1, 35, 315, 31, 51, 35, 135, 4,  134, 1});
  }

  std::vector<MyType> out;
  out.reserve(vec.size());

  auto temp_uptr =
      [&vec](const std::function<std::unique_ptr<std::vector<MyType>>(
                 const std::vector<MyType> &)> &func) {
#ifdef DESTRUCTION
        std::cout << "Starting return by unique ptr" << '\n';
#endif
        auto mobile = func(vec);
#ifdef DESTRUCTION
        std::cout << "Finished return by unique ptr" << '\n';
#endif
      };

  auto uptr = [&temp_uptr]() { temp_uptr(return_unique); };
  auto uptr2 = [&temp_uptr]() { temp_uptr(return_unique2); };
  auto uptr3 = [&temp_uptr]() { temp_uptr(return_unique3); };
  auto ptr = [&vec]() {
#ifdef DESTRUCTION
    std::cout << "Starting return by raw ptr" << '\n';
#endif
    auto *mobile = return_ptr(vec);
    delete mobile;
#ifdef DESTRUCTION
    std::cout << "End return by raw ptr" << '\n';
#endif
  };

  auto value = [&vec]() {
#ifdef DESTRUCTION
    std::cout << "Starting return by value" << '\n';
#endif
    auto mobile = return_by_value(vec);
#ifdef DESTRUCTION
    std::cout << "Finished return by value" << '\n';
#endif
  };
  auto noret = [&vec, &out]() mutable { noreturn(vec, out); };
  timeit(uptr, ITERS, "Unique PTR");
  std::cout << "End\n" << '\n';
  timeit(uptr2, ITERS, "Unique PTR 2 -- move local variable");
  std::cout << "End\n" << '\n';
  timeit(uptr3, ITERS, "Unique PTR 3 --- create with new");
  std::cout << "End\n" << '\n';
  timeit(value, ITERS, "By Value");
  std::cout << "End\n" << '\n';
  // timeit(noret, ITERS, "No Return");
  // std::cout << "End\n\n\n" << '\n';
  timeit(ptr, ITERS, "PTR return");
}