#include <iostream>
using namespace std;

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

int main() {
    cout << "Int multiplication: " << multiply(5, 10) << endl;
    cout << "Float multiplication: " << multiply(2.5, 4.0) << endl;
    return 0;
}
