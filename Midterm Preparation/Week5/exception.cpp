#include <iostream>

void divide(double a, double b) {
    if (b == 0)
        throw "Division by zero error";
    else
        std::cout << "Result: " << a / b << std::endl;
}

int main() {
    double num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    try {
        divide(num1, num2);
    }
    catch (const char* e) {
        std::cerr << "Error: " << e << std::endl;
    }

    return 0;
}
