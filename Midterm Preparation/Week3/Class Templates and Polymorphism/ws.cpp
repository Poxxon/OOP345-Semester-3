#include <iostream>
#include "Array.h"
#include "ArraySpecialization.h"

/*
This code demonstrates parametric polymorphism using class templates. 
The Array class works for any data type and allows you to define generic behavior. 
The template is specialized for const char* to handle C-style strings with custom behavior 
for finding the maximum string.
*/

int main() {
    Array<int> intArray;
    intArray.add(10);
    intArray.add(20);
    intArray.add(30);

    std::cout << "Integer Array: ";
    for (unsigned i = 0; i < intArray.getSize(); ++i)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

    Array<const char*> strArray;
    strArray.add("apple");
    strArray.add("banana");
    strArray.add("cherry");

    std::cout << "Max string: " << strArray.findMax() << std::endl;

    return 0;
}
