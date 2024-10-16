#include <iostream>

bool isPrimeIter(int num) {
    if (num == 1)
        return false; // 1 is not a prime number
    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return false; // not prime if divisible
    }
    return true;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    if (isPrimeIter(number))
        std::cout << number << " is a prime number.\n";
    else
        std::cout << number << " is not a prime number.\n";
    return 0;
}
