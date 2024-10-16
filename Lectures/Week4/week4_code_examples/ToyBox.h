// ToyBox.h
#pragma once

#include <iostream>

class PlaydohAssoc;

class ToyBox {
  
  std::string name;
  std::string material;
  int weight{ 0 };
  PlaydohAssoc* doh{ nullptr };
public:

  ToyBox();
  ToyBox(const char* nm, const char* mat, int wei);
  ~ToyBox();

  // Associate
  void put(PlaydohAssoc& src);
  void takeout();

  void setName(const char* nm);
  void setMaterial(const char* mat);
  const char* getName() const;
  const char* getMaterial() const;

  std::ostream& display(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const ToyBox& t);
