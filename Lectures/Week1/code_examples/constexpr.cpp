//constexpr.cpp

#include <iostream>

constexpr int x = 10;

constexpr long int sumUp(long int x){
  if (x > 0)
    return x + sumUp(x - 1);
  return 0;
}

constexpr int arraySize(int x){
  return x * x;
}

int main(){

  long int y = 10000;
  std::cout << "The sum up of y is: " << sumUp(y) << std::endl;

  int array[arraySize(2)];

  // static assertion
  static_assert(arraySize(2) == 4, "Squares don't work!"); 
  static_assert(arraySize(2) == 5, "Squares do work!"); 
}
