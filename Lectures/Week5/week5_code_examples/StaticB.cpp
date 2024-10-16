// StaticB.cpp

#include <iostream>

static std::ostream& display(std::ostream& os) {
  os << "Hello From World B" << std::endl;
  return os;
}

void otherworldlyportal() {
  display(std::cout);
}