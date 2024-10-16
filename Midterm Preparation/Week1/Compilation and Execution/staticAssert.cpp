#include <iostream>
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    static_assert(factorial(5) == 120, "Factorial is incorrect!"); // Compile-time check
    std::cout << "Factorial of 5 is correct!" << std::endl;
    return 0;
}
