// Playdoh.h
#pragma once

#include <iostream>

class Playdoh {

  char* colour { nullptr };
  int weight { 0 };

public:
  Playdoh();
  Playdoh(const char* col, int wei);
  Playdoh(const Playdoh& src);
  Playdoh& operator=(const Playdoh& src);

  std::ostream& display(std::ostream& os) const;
  void setColour(const char* col);
  void setWeight(int wei);

  friend bool operator==(const Playdoh& p1, const Playdoh& p2);

  ~Playdoh();

};

std::ostream& operator<<(std::ostream& os, const Playdoh& p);

