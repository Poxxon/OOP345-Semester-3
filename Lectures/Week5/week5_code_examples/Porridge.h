// Porridge.h
#pragma once
#include <string>
#include <exception>
#include <iostream>

class badIntExp : public std::exception {
protected:
  std::string message = "Bad Integer Number";
public:
  const char* what() const noexcept;
};

class tooCold : public badIntExp {
public:
  tooCold();
};

class tooHot : public badIntExp {
public:
  tooHot();
};

class Porridge {

  unsigned amount{};
  int heat{};
public:
  Porridge();
  Porridge(int amt, int heat);
  Porridge& operator+=(unsigned amt);
  void warmUp();
  void coolDown();

  std::ostream& display(std::ostream& os = std::cout) const;
  std::ostream& eat(std::ostream& os = std::cout);
};
