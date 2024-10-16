#include <iostream>
using namespace std;

class Ship {
  string name { "Fair Maiden" }; // using default initializer
  int fuel{ 100 };
  int distanceTraveled{ 0 };

  class { // anon class
    double efficiency;
  public:
    void setEfficiency(double e) { efficiency = e; }
    int fuelCost(int distance) {
      return distance * efficiency;
    }
  } engine;

public: 

  Ship() { engine.setEfficiency(1); }
  Ship(const char* n, int f) : name{ n }, fuel{ f } { // initializers list
    engine.setEfficiency(0.5);
  }; 
  void setSail(int distance) {
    fuel -= engine.fuelCost(distance);
    if (fuel > 0)
      distanceTraveled += distance;
  }
  void display() const {
    cout << "Ship: " << name << endl;
    cout << "Remaining Fuel: " << fuel << endl;
    cout << "Distance Traveled " << distanceTraveled << endl;
  }
};

int main() {
  Ship s1;
  s1.display();
}