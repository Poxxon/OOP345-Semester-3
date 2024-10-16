#include <iostream>
using namespace std;

int globalVar = 10; // Global scope

void demoFunction() {
    static int staticVar = 0; // Static variable
    int localVar = 5;         // Local variable

    cout << "Static Variable: " << staticVar++ << endl;
    cout << "Local Variable: " << localVar << endl;
}

int main() {
    cout << "Global Variable: " << globalVar << endl;
    
    for (int i = 0; i < 3; ++i) {
        demoFunction();
    }

    return 0;
}
