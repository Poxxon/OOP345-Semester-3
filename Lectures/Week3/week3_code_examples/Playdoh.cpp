// Playdoh.cpp

#include <iostream>
#include "Playdoh.h"
using namespace std;

Playdoh::Playdoh() {}

Playdoh::Playdoh(int wei, char col) : colour(col) {
  setWeight(wei);
}

Playdoh::Playdoh(const Playdoh& src) : Compound(src) {
  cout << "In Playdoh CC" << endl;
  colour = src.colour;
}

std::ostream& Playdoh::display(std::ostream& os) const {
  return os << "Playdoh colour: " << colour << " weight: " << getWeight() << endl;
}

std::istream& Playdoh::write(std::istream& is) {
  cout << "Enter a value for the Playdoh colour: ";
  is >> colour;
  cout << "Enter a value for the Playdoh weight: ";
  int wei;
  is >> wei;
  setWeight(wei);
  return is;
}

Compound* Playdoh::clone() const {
  return new Playdoh(*this);
}

bool Playdoh::operator==(Compound& c) const { // playdoh == compound

#define ex1
#ifdef ex1
  const Playdoh* play = dynamic_cast<Playdoh*>(&c); // dynacast returns nullptr on failure of casting
  return play ? play->colour == colour : false;
#else
  return c.colour == colour;
#endif
}
