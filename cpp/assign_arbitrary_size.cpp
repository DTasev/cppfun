#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  std::vector<int> assignee = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> assigned = {0}; 

  std::cout << assigned.size() << '\n';
  assigned.assign(assignee.begin(), assignee.end());
  std::cout << assigned.size() << '\n';

  for (const auto &elem : assigned) {
    std::cout << elem << '\n';
  }
}