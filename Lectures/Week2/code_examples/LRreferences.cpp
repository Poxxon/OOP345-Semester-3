#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Playdoh {
  char* colour;
public:
  Playdoh(const char* value = nullptr) : colour(nullptr) {
    if (value) {
      colour = new char[strlen(value) + 1];
      strcpy(colour, value);
    }
  }
  ostream& display(ostream& os)const {
    if (colour) os << colour;
    return os;
  }
  ~Playdoh() {
    delete[] colour;
  }
};
ostream& operator<< (ostream& os, const Playdoh& P) {
  os << "lvalue: ";
  return P.display(os);
}
ostream& operator<< (ostream& os,  Playdoh&& P) {
  os << "rvalue: ";
  return P.display(os);
}
int main() {
  Playdoh A("Red");
  //cout << A << endl;
  cout << std::move(A) << endl;
  cout << Playdoh("Blue") << endl;
  return 0;
}