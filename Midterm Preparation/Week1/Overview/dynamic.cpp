#include <iostream>
using namespace std;

int main() {
    // Static memory allocation
    int staticArray[5] = {1, 2, 3, 4, 5};
    cout << "Static Array: ";
    for (int i = 0; i < 5; ++i) {
        cout << staticArray[i] << " ";
    }
    cout << endl;

    // Dynamic memory allocation
    int* dynamicArray = new int[5];
    for (int i = 0; i < 5; ++i) {
        dynamicArray[i] = i + 6;
    }

    cout << "Dynamic Array: ";
    for (int i = 0; i < 5; ++i) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    // Deallocate dynamic memory
    delete[] dynamicArray;

    return 0;
}
