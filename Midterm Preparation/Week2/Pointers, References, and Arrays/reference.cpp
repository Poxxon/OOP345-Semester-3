#include <iostream>
int main() {
    int a = 10;
    int& ref = a;  // lvalue reference

    ref += 5;  // modifying through reference
    std::cout << "Value of a: " << a << std::endl; // a is modified

    return 0;
}
