// Array.h
#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
    T arr[50];    // Fixed-size array
    unsigned size;
    T dummy;      // Dummy return for invalid index
public:
    Array() : size(0), dummy(0) {}
    
    T& operator[](unsigned idx) {
        return (idx < 50) ? arr[idx] : dummy;
    }

    void add(const T& value) {
        if (size < 50)
            arr[size++] = value;
    }

    unsigned getSize() const { return size; }
};

#endif
