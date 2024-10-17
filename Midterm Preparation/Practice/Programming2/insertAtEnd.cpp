#include <iostream>
#include <cstring> // For strcpy in specialization for char

template <typename T>
T* insertAtEnd(T* array, size_t size, const T& element)
{
    // Create a new array with one extra slot for the new element
    T* newArray = new T[size + 1];

    // Copy the old elements to the new array
    for (size_t i = 0; i < size; ++i)
    {
        newArray[i] = array[i];
    }

    // Insert the new element at the end
    newArray[size] = element;

    // Free the old array
    delete[] array;

    // Return the new resized array
    return newArray;
}

// Specialization for char array
template <>
char* insertAtEnd<char>(char* array, size_t size, const char& element)
{
    // Create a new array with one extra slot for the new element and null terminator
    char* newArray = new char[size + 2]; // +1 for the element and +1 for null terminator

    // Copy the old elements to the new array
    if (array != nullptr) {
        std::strncpy(newArray, array, size); // Use strncpy to copy up to 'size' chars
    }

    // Insert the new element and the null terminator
    newArray[size] = element;
    newArray[size + 1] = '\0';

    // Free the old array
    delete[] array;

    // Return the new resized array
    return newArray;
}

int main()
{
    {
        int* arrI = nullptr;
        arrI = insertAtEnd(arrI, 0, 1); // 1
        arrI = insertAtEnd(arrI, 1, 5); // 1, 5
        arrI = insertAtEnd(arrI, 2, -3);// 1, 5, -3
        for (size_t i = 0; i < 3; ++i)
            std::cout << arrI[i] << " ";
        std::cout << std::endl;
        delete[] arrI;
    }
    {
        double* arrD = nullptr;
        arrD = insertAtEnd(arrD, 0, 1.2);// 1.2
        arrD = insertAtEnd(arrD, 1, 2.3);// 1.2, 2.3
        arrD = insertAtEnd(arrD, 2, 3.4);// 1.2, 2.3, 3.4
        for (size_t i = 0; i < 3; ++i)
            std::cout << arrD[i] << " ";
        std::cout << std::endl;
        delete[] arrD;
    }
    {
        char* arrC = nullptr;
        arrC = insertAtEnd(arrC, 0, 'a');// a\0
        arrC = insertAtEnd(arrC, 1, 'b');// ab\0
        arrC = insertAtEnd(arrC, 2, 'c');// abc\0
        std::cout << arrC << std::endl;
        delete[] arrC;
    }
    return 0;
}
