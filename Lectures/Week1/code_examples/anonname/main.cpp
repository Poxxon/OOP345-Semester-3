#include <iostream>
#include "dogcat.h"

void potato() {

  std::cout << "xpotato" << std::endl;
}

int main(){

  dog::display(); 
  cat::display(); 
  potato();
}
