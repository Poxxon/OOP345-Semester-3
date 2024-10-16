#include <iostream>

// Recursive function to check for prime numbers
bool isPrime(int num, int recur) {
    if (num == 1 || recur == 1)
        return true; // base case
    else if ((num % recur) == 0)
        return false; // not prime if divisible
    else
        return isPrime(num, recur - 1); // recursive case
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    if (isPrime(number, number - 1))
        std::cout << number << " is a prime number.\n";
    else
        std::cout << number << " is not a prime number.\n";
    return 0;
}
