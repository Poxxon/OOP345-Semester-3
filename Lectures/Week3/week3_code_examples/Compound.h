// Compound.h
// #pragma once
#ifndef COMPOUND_H
#define COMPOUND_H

#include <iostream>

class Compound {
  int weight;
public:
  void setWeight(int wei);
  int getWeight() const;
  virtual std::ostream& display(std::ostream& os) const = 0;
  virtual std::istream& write(std::istream& is) = 0;

  virtual Compound* clone() const = 0;

  virtual bool operator==(Compound& c) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Compound& c);
std::istream& operator>>(std::istream& is, Compound& c);

#endif
