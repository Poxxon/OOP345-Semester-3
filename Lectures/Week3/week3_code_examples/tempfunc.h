// template.h
//#pragma once

#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <cstring>
#include <iostream>
using namespace std;

template <typename T>
void temp_swap(T& a, T& b){
  T c;
  c = a;
  a = b;
  b = c;
}

template <class T>
T maximum(T a, T b) {
  cout << "Generic max" << endl;
  return a > b ? a : b;
}

// specialization for const char* types
template <> // denotes specialization
const char* maximum(const char* a, const char* b) {
  cout << "Specialized max" << endl;
  return std::strcmp(a, b) > 0 ? a : b; 
}

template <> // denotes specialization
double maximum(double a, double b) {
  cout << "Double max" << endl;
  return a > b ? a : b;
}

template <> // denotes specialization
float maximum(float a, float b) {
  cout << "Float max" << endl;
  return a > b ? a : b;
}
#endif
