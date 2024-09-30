// main.cpp

#include <iostream>
#include "house.h"

void display(int key){
  std::cout << "display from main: " << key << std::endl;
}

int main(){

  int mykey = 15;
  display(mykey);
  std::cout << "****" << std::endl; 
  foo(mykey); 
}
