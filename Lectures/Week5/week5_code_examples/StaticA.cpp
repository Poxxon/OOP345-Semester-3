// StaticA.cpp

#include <iostream>

static std::ostream& display(std::ostream& os) {
  os << "Hello From World A" << std::endl;
  return os;
}

void otherworldlyportal();

int main() {

  display(std::cout);
  otherworldlyportal();
}
