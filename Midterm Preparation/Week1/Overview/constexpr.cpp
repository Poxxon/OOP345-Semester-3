#include <iostream>
using namespace std;

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    constexpr int result = factorial(5);
    cout << "Factorial of 5 is: " << result << endl;

    return 0;
}
