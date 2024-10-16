#include <iostream>
constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int value = square(5); // Compile-time evaluation
    std::cout << "Square of 5: " << value << std::endl;
    return 0;
}
