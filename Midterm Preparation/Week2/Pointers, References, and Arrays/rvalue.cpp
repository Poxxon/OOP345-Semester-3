#include <iostream>
void process(int&& x) {  // rvalue reference
    std::cout << "Rvalue: " << x << std::endl;
}

int main() {
    int x = 10;
    process(20);  // passes rvalue

    return 0;
}
