#include <iostream>

class MyObject {
public:
  MyObject() {}

  void change_not_const(int new_val) /* no const here */ {
    not_const = new_val;
  }

  int get_not_const() const { return not_const; }

private:
  int not_const = 4;
};

int main(){
  MyObject not_const_obj;

  // can access the not const function
  not_const_obj.change_not_const(69);
  std::cout << not_const_obj.get_not_const() << '\n'; // prints 69

  const MyObject const_obj;
//   const_obj.change_not_const(55); // compile error, we're trying to access a
  // non const function on a const object
  std::cout << const_obj.get_not_const()
            << '\n'; // const function is fine, prints 4
}