#include <iostream>

int main() {
int arr[5];
    // This file has incredibly messy indentation to test clang-format
      arr[10] = 5; // Out of bounds array access! (cppcheck should catch this)
      
      int uninitialized_var;
      if (uninitialized_var == 5) { // Using an uninitialized variable! (cppcheck should catch this)
          std::cout << "Hello" << std::endl;
      }
      
return 0;
}
