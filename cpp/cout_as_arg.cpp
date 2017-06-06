#include <iostream>
void func(std::ostream &out) { out << "I am writing directly\n"; }
int main() { func(std::cout); }