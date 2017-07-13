#include <stdio.h>
#include <vector>

int main() {
  const int ROWS = 3;
  const int COLS = 3;
  std::vector<std::vector<int>> vector = {{1, 5, 8}};
  int array2d[ROWS][COLS] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
  const int first_D_vector = 0;
  const int second_D_vector = 2;
  printf("%d",
         *(    // convert the 2nd vector to rvalue from ptr
             ( // start bracket for convertion to rvalue
                 *(vector.data() + first_D_vector) // gives us the 2nd vector
                 )        // converts the vector to an rvalue
                 .data()) // end of converting the 2nd vec
         );
}