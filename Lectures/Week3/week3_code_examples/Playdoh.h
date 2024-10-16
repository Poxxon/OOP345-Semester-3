// Playdoh.h
//#pragma once

#ifndef PLAYDOH_H
#define PLAYDOH_H

#include <iostream>
#include "Compound.h"

class Playdoh : public Compound {
  char colour{ 'R' };
public:
  Playdoh();
  Playdoh(int wei, char col);

  Playdoh(const Playdoh& src);

  std::ostream& display(std::ostream& os) const;
  std::istream& write(std::istream& is);

  Compound* clone() const;

  bool operator==(Compound& c) const;
};

#endif
