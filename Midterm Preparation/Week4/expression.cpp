#include <iostream>

int foo() {
    return 10; // prvalue: this value will be copied
}

int& bar() {
    static int x = 100; 
    return x; // lvalue: this can be assigned to
}

int main() {
    int a = foo();  // foo() is prvalue
    std::cout << "a = " << a << std::endl;

    int& b = bar(); // bar() returns lvalue reference
    std::cout << "b = " << b << std::endl;

    b = 200; // modify lvalue
    std::cout << "New b = " << b << std::endl;
    
    int&& c = foo(); // rvalue reference, foo() is prvalue
    std::cout << "c = " << c << std::endl;

    return 0;
}
