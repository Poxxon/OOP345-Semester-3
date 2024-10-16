// PlaydohAssoc.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Toybox.h"
#include "PlaydohAssoc.h"

PlaydohAssoc::PlaydohAssoc() {}

PlaydohAssoc::PlaydohAssoc(const char* col, int wei) {
  setColour(col);
  setWeight(wei);
}

void PlaydohAssoc::associate(ToyBox& src) {
  if (box) box->takeout();
  box = &src;
}

void PlaydohAssoc::disassociate() {
  box = nullptr;
}

std::ostream& PlaydohAssoc::display(std::ostream& os) const {
  if (colour) {
    os << "Playdoh Colour: " << colour << " Weight: " << weight << std::endl;
  }
  else
    os << "Empty Playdoh" << std::endl;

  if (box) os << "In " << box->getName() << std::endl;
   
  return os;
}

void PlaydohAssoc::setColour(const char* col) {
  if (colour) {
    delete[] colour;
    colour = nullptr;
  }
  if (col) {
    colour = new char[strlen(col) + 1];
    strcpy(colour, col);
  }
}

void PlaydohAssoc::setWeight(int wei) {
  weight = wei > 0 ? wei : 0;
}

const char* PlaydohAssoc::getColour() const {
  return colour;
}

int PlaydohAssoc::getWeight() const {
  return weight;
}

PlaydohAssoc::~PlaydohAssoc() {
  if (box) box->takeout();
  delete[] colour;
}

std::ostream& operator<<(std::ostream& os, const PlaydohAssoc& p) {
  return p.display(os);
}
