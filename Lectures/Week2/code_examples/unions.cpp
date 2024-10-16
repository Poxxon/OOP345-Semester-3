// Unions
// union.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

union Product { // some have skus, some have upcs 
    int sku;
    char upc[14];
};

int main() {
    Product cereal, tissue;

    cereal.sku = 4789;
    
    std::strcpy(tissue.upc, "0360002607555");
    //tissue.sku = 10000;

    std::cout << cereal.sku << std::endl;
    std::cout << tissue.upc << std::endl; 
}