// Clay.cpp
#include <iostream>
#include "Clay.h"
using namespace std;

Clay::Clay() {}

Clay::Clay(int wei, double har) : hardness(har) {
  setWeight(wei);
}

std::ostream& Clay::display(std::ostream& os) const {
  return os << "Clay hardness: " << hardness << " weight: " << getWeight() << endl;
}

std::istream& Clay::write(std::istream& is) {
  cout << "Enter a value for the Clay hardness: ";
  is >> hardness;
  cout << "Enter a value for the Clay weight: ";
  int wei;
  is >> wei;
  setWeight(wei);
  return is;
}

Compound* Clay::clone() const {
  return new Clay(*this);
}

bool Clay::operator==(Compound& c) const { // clay == compound
  const Clay* clay = dynamic_cast<Clay*>(&c);
#define ex1
#ifdef ex1
  return clay ? clay->hardness == hardness : false;
#else
  return clay->hardness == hardness;
#endif
}
