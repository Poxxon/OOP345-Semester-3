// scope.cpp

#include <iostream>
//using namespace std;

#define ex1
#define ex2

int main(){

  #ifdef ex1
  int x = 15;
  if (int x > 10){
  
    int x = 5;
    std::cout << x << std::endl;
  }
  std::cout << x << std::endl;
  #endif

  #ifdef ex2 
  int y;
  std::cin >> y; 
  if (int z = y / 2; z > 10){ // init in if
    std::cout << "greater" << std::endl;
  }
  else{
    std::cout << "lesser" << std::endl;
  }
  #endif
}
