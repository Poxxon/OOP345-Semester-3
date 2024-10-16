#include <iostream>
using namespace std;

class Duck {
public:
  virtual void fly() { cout << "Flap Flap" << endl; }
  virtual void noise() { cout << "Quack" << endl; }
};

class RobotDuck : public Duck {
  int battery{ 10 };
public:
  void fly() {
    if (battery > 0)
      cout << "Flap Flap Mechanical" << endl;
    battery -= 10;
  }
  void noise() {
    if (battery > 0)
      cout << "Quack Mechanical" << endl;
    battery -= 10;
  }
};

void foo(Duck& d) {
  d.fly();
}

int main() {
 
  Duck* d = new Duck;
  foo(*d);

  Duck* d2 = new RobotDuck;
  foo(*d2);
  foo(*d2);
}