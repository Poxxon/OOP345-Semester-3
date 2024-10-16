// Cube.h
#include "Shape.h"

class Cube : public Shape {
    double len;
public:
    Cube(double l) : len(l) {}
    double volume() const override {
        return len * len * len;
    }
};

