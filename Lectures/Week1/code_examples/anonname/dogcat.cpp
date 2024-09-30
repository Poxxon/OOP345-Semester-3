#include <iostream>
#include "dogcat.h"

namespace {

  void potato() {
    std::cout << "potato" << std::endl;
  }
}

namespace dog{
  void display() {
    std::cout << "dog ";
    potato(); 
  }
}

namespace cat{
  void display() {
    std::cout << "cat ";
    potato(); 
  }
}
