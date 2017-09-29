#include <iostream>

// global namespace
struct SomeClass {
  SomeClass() { std::cout << "Global SomeClass" << '\n'; }
};

namespace MyApp {
struct SomeClass {
  SomeClass() { std::cout << "MyApp SomeClass" << '\n'; }
};
}

int main() {
  MyApp::SomeClass a; // refers to MyApp::SomeClass
  ::SomeClass b;      // refers to global namespace SomeClass
}