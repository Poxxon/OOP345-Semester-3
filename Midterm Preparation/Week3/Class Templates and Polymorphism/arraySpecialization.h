// ArraySpecialization.h
#ifndef ARRAYSPECIALIZATION_H
#define ARRAYSPECIALIZATION_H

#include <cstring>
#include "Array.h"

template <>
class Array<const char*> {
    const char* arr[50];
    unsigned size;
public:
    Array() : size(0) {}

    const char*& operator[](unsigned idx) {
        return (idx < 50) ? arr[idx] : arr[0];  // Return first element as dummy
    }

    void add(const char* value) {
        if (size < 50)
            arr[size++] = value;
    }

    unsigned getSize() const { return size; }

    const char* findMax() {
        const char* maxStr = arr[0];
        for (unsigned i = 1; i < size; ++i)
            if (std::strcmp(arr[i], maxStr) > 0)
                maxStr = arr[i];
        return maxStr;
    }
};

#endif
