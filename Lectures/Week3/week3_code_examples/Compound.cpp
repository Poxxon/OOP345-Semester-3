// Compound.cpp
#include "Compound.h"

std::ostream& operator<<(std::ostream& os, const Compound& c) {
  return c.display(os);
}

std::istream& operator>>(std::istream& is, Compound& c) {
  return c.write(is);
}

void Compound::setWeight(int wei) {
  weight = wei > 0 ? wei : 0;
}

int Compound::getWeight() const {
  return weight;
}
