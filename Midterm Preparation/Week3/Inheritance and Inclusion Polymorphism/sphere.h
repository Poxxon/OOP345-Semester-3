// Sphere.h
#include "Shape.h"

class Sphere : public Shape {
    double rad;
public:
    Sphere(double r) : rad(r) {}
    double volume() const override {
        return (4.0/3.0) * 3.14159 * rad * rad * rad;
    }
};