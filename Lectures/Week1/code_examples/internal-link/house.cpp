// house.cpp

#include <iostream>
#include "house.h"

void display(int key){

  std::cout << "displaying key: " << key << std::endl;
}

void foo(int key){
  display(key);
}
