// Shape.h (Abstract base class)
#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual double volume() const = 0;  // Pure virtual function
    virtual ~Shape() {}  // Virtual destructor
};

#endif
