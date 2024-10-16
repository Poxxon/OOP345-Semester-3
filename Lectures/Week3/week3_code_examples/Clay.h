// Clay.h
//#pragma once

#ifndef CLAY_H 
#define CLAY_H

#include <iostream>
#include "Compound.h"

class Clay : public Compound {

  double hardness{ 0.5 };
public:
  Clay();
  Clay(int wei, double har);

  std::ostream& display(std::ostream& os) const;
  std::istream& write(std::istream& is);

  Compound* clone() const;

  bool operator==(Compound& c) const;
};

#endif
