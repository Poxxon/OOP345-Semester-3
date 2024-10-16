#include "ToyBox.h"
#include "PlaydohAssoc.h"

ToyBox::ToyBox() {}

ToyBox::ToyBox(const char* nm, const char* mat, int wei) : name(nm), material(mat), weight(wei) {
}

ToyBox::~ToyBox() {
  if (doh) doh->disassociate();
}

void ToyBox::put(PlaydohAssoc& src) {
  if (doh) doh->disassociate();
  doh = &src;
  weight += doh->getWeight();
}

void ToyBox::takeout() {
  weight -= doh->getWeight();
  doh = nullptr;
}

void ToyBox::setName(const char* nm) {
  name = nm;
}

void ToyBox::setMaterial(const char* mat) {
  material = mat;
}

const char* ToyBox::getName() const {
  return name.c_str();
}

const char* ToyBox::getMaterial() const {
  return material.c_str();
}

std::ostream& ToyBox::display(std::ostream& os) const {
  os << "ToyBox Name: " << name << std::endl;
  os << "Material: " << material << std::endl;
  os << "Weight: " << weight << std::endl;

  if (doh)
    os << "Contains: " << doh->getColour() << " playdoh "<< std::endl;
  else
    os << "Is empty" << std::endl;
  return os;
}

std::ostream& operator<<(std::ostream& os, const ToyBox& t) {
  return t.display(os);
}
