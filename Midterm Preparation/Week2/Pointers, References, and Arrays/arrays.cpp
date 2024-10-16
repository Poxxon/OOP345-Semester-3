#include <iostream>
int main() {
    int arr[] = {1, 2, 3, 4, 5};

    for (int& element : arr) {
        element *= 2;  // modifying array elements
    }

    for (const int& element : arr) {
        std::cout << element << " ";  // displaying array elements
    }
    std::cout << std::endl;

    for (int i = 0; i < sizeof(arr); ++i) {
        std::cout << i << " ";
    }
    return 0;
}
