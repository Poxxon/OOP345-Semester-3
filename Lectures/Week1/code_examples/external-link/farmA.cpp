// farmA.cpp

#include <iostream>
using namespace std;

extern int shared_butter; // externally linked

void useButterA(){
  shared_butter -= 10;
  std::cout << "butter A route" << std::endl;
  std::cout << "amount of butter left: " << shared_butter << std::endl;
  std::cout << "address of butter: " << &shared_butter << std::endl;
}
