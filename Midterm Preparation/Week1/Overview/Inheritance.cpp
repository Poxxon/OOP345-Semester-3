#include <iostream>
using namespace std;

class Vehicle {
protected:
    int speed;

public:
    Vehicle(int sp) : speed(sp) {}

    void showSpeed() const {
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
private:
    int fuelLevel;

public:
    Car(int sp, int fuel) : Vehicle(sp), fuelLevel(fuel) {}

    void showCarInfo() const {
        showSpeed();
        cout << "Fuel Level: " << fuelLevel << "%" << endl;
    }
};

int main() {
    Car myCar(120, 80);
    myCar.showCarInfo();
    return 0;
}
