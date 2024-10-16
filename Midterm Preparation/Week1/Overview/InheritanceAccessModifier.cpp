#include <iostream>

class Vehicle {
private:
    int maxSpeed;

protected:
    int wheels;

public:
    Vehicle(int w, int speed) : wheels(w), maxSpeed(speed) {}

    void showInfo() const {
    //cout << "Wheels: " << wheels << ", Max Speed: " << maxSpeed << endl;
    }
};

class Car : public Vehicle {
private:
    int fuelLevel;

public:
    Car(int w, int speed, int fuel) : Vehicle(w, speed), fuelLevel(fuel) {}

    void showCarInfo() {
        showInfo();  // Access to protected member
        //cout << "Fuel Level: " << fuelLevel << "%" << endl;
    }
};
