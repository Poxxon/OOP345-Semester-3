#include <iostream>
#include "Cube.h"
#include "Sphere.h"

/*This code demonstrates inheritance and inclusion polymorphism. 
The abstract class Shape serves as the interface, and derived classes like Cube and Sphere 
specialize this base class by implementing the pure virtual function volume(). 
The Liskov Substitution Principle is applied as any derived object can replace the 
base class without altering functionality.
*/

void displayVolume(const Shape* shape) {
    if (shape)
        std::cout << shape->volume() << std::endl;
    else
        std::cerr << "ERROR!" << std::endl;
}

Shape* selectShape() {
    Shape* shape = nullptr;
    double dimension;
    char type;
    std::cout << "Choose shape - s (sphere), c (cube): ";
    std::cin >> type;

    if (type == 's') {
        std::cout << "Enter radius: ";
        std::cin >> dimension;
        shape = new Sphere(dimension);
    } else if (type == 'c') {
        std::cout << "Enter length: ";
        std::cin >> dimension;
        shape = new Cube(dimension);
    }
    return shape;
}

int main() {
    Shape* shape = selectShape();
    displayVolume(shape);
    delete shape;
}
