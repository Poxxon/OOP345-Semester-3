#include <iostream>
namespace alpha {
    int value = 5;
}
namespace beta {
    int value = 10;
}

int main() {
    std::cout << "Alpha's value: " << alpha::value << std::endl;
    std::cout << "Beta's value: " << beta::value << std::endl;
    return 0;
}
