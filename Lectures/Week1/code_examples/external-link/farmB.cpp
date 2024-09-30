// farmB.cpp

#include <iostream>

extern int shared_butter; // externally linked

void useButterB(){
  shared_butter -= 5;
  std::cout << "butter B route" << std::endl;
  std::cout << "amount of butter left: " << shared_butter << std::endl;
  std::cout << "address of butter: " << &shared_butter << std::endl;
}
