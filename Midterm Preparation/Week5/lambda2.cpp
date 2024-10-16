#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Lambda capturing by value
    auto sumByValue = [=](int a) -> int {
        return x + y + a;  // x and y are captured by value
    };

    // Lambda capturing by reference
    auto sumByReference = [&](int a) -> int {
        x += 5;            // x is modified because it is captured by reference
        return x + y + a;
    };

    std::cout << "Sum by value: " << sumByValue(5) << std::endl;  // Output: 35
    std::cout << "Sum by reference: " << sumByReference(5) << std::endl;  // Output: 40
    std::cout << "New x: " << x << std::endl;  // Output: 15, x was changed by the reference-capturing lambda

    return 0;
}
