// Playdoh-FunSyntax.cpp
#include <iostream>
using namespace std;

class Playdoh{
public:
  enum class Colour {Red, Blue, Green}; // 0 = Red, 1 = Blue...
  void setColour(Colour col);
  Colour getColour() const;
  void display() const;
private:
  Colour colour;
  unsigned weight;
};

void Playdoh::setColour(Colour col) { colour = col; }

//Colour Playdoh::getColour() const { return colour; }
//Playdoh::Colour Playdoh::getColour() const { return colour; }
auto Playdoh::getColour() const -> Colour { return colour; }

void Playdoh::display() const {
  switch (colour) {
  case Colour::Red:
    cout << "Red Playdoh" << endl;
    break;
  case Colour::Blue:
    cout << "Blue Playdoh" << endl;
    break;
  case Colour::Green:
    cout << "Green Playdoh" << endl;
    break;
  }
}

int main() {
  Playdoh p;
  p.setColour(Playdoh::Colour::Red);
  p.display();
}