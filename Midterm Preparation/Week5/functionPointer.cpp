#include <iostream>

void funcA() {
    std::cout << "I am Function A" << std::endl;
}

void funcB() {
    std::cout << "I am Function B" << std::endl;
}

int main() {
    void (*ptrToFunc)(); // function pointer
    ptrToFunc = funcA; // point to funcA
    ptrToFunc(); // call funcA through pointer

    ptrToFunc = funcB; // change to funcB
    ptrToFunc(); // call funcB through pointer
    return 0;
}
