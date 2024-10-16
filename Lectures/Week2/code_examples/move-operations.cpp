#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Playdoh {
  char* colour = nullptr;
  int weight = 0;
public:
  Playdoh() {}
  Playdoh(const char* c, int w) : weight(w) {
    if (c) {
      colour = new char[strlen(c) + 1];
      strcpy(colour, c);
    }
  }
  ~Playdoh() { delete[] colour; }

  void display() const {
    if (colour)
      cout << "Colour: " << colour << " Weight: " << weight << endl;
    else
      cout << "Empty Playdoh" << endl;
  }

  // Copy constr / assign
  Playdoh(const Playdoh& src) : colour(nullptr) {
    cout << "Playdoh CopyConstr" << endl;
    *this = src;
  }

  Playdoh& operator=(const Playdoh& src) {
    cout << "Playdoh CopyA" << endl;
    if (this != &src) {
      delete[] colour;

      weight = src.weight;
      if (src.colour) {
        colour = new char[strlen(src.colour) + 1];
        strcpy(colour, src.colour);
      }
    }
    return *this;
  }

  // Move constr / assign
  Playdoh(Playdoh&& src) {
    cout << "Playdoh MoveConstr" << endl;
    *this = std::move(src); // note the move call
  }

  Playdoh& operator=(Playdoh&& src) {
    cout << "Playdoh MoveA" << endl;
    if (this != &src) {
      delete[] colour;
      colour = src.colour;
      src.colour = nullptr;
      weight = src.weight;
      src.weight = 0;
    }
    return *this;
  }

};

int main() {
  
  Playdoh p1("Red", 100), p2("Blue", 200);

  // Copy Constr
  Playdoh p3 = p1;
  p3.display();
  p1.display();
  cout << "************************" << endl;

  // Copy Assign
  p3 = p2;
  p3.display();
  p2.display();
  cout << "************************" << endl;

  // Move Constr
  Playdoh p4 = std::move(p1);
  p4.display();
  p1.display();
  cout << "************************" << endl;
  
  // Move Assign
  p4 = std::move(p2);
  p4.display();
  p2.display();

}