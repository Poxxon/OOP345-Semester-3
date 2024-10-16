#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }
};

int main() {
    Shape* shapes[2];

    shapes[0] = new Rectangle(5.0, 3.0);
    shapes[1] = new Circle(7.0);

    for (int i = 0; i < 2; ++i) {
        cout << "Area: " << shapes[i]->area() << endl;
    }

    // Clean up memory
    delete shapes[0];
    delete shapes[1];

    return 0;
}
