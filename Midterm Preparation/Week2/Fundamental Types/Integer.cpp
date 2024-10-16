#include <iostream>
int main() {
    signed char sc = 'A';   // signed char
    unsigned int ui = 300U; // unsigned int with suffix U
    long long ll = 123456789LL; // long long with suffix LL

    std::cout << "Signed char: " << sc << std::endl;
    std::cout << "Unsigned int: " << ui << std::endl;
    std::cout << "Long long: " << ll << std::endl;

    return 0;
}
