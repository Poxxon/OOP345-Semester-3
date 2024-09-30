// module_a.cpp

#include <iostream>
static int local = 4;

void display() {
    std::cout << "local is at " << &local << '\n'; 
    std::cout << "local is " << local++ << '\n';
}
