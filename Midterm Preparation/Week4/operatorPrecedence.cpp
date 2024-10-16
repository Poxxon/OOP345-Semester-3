#include <iostream>

int main() {
    int a = 10, b = 20, c = 30;

    // Operator precedence demonstration
    int result = a + b * c; // multiplication has higher precedence
    std::cout << a << " " << b << " " << c << " " << std::endl;
    std::cout << "Result (a + b * c): " << result << std::endl;

    result = (a + b) * c; // parentheses override precedence
    std::cout << "Result ((a + b) * c): " << result << std::endl;

    bool condition = a > 5 && b < 25; // logical AND, relational operators
    std::cout << "Condition (a > 5 && b < 25): " << condition << std::endl;

    return 0;
}
