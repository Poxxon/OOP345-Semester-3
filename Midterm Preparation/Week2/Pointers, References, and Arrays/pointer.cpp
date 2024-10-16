#include <iostream>
int main() {
    int a = 10;
    int* p = &a;  // pointer to int

    std::cout << "Address of a: " << p << std::endl; // not denoting the * lets it display the actual address
    std::cout << "Value of a: " << *p << std::endl; // dereferencing

    return 0;
}
