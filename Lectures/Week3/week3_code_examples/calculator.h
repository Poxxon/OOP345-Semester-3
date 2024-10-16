// Calc.h
#pragma once
#ifndef SDDS_CALC_H
#define SDDS_CALC_H

#include <iostream>

template <typename T = int, int N = 3> // with defaults defined
class Calculator {

  T result[N]{};
  static int uses; // class variables - static vars in a class
public:
  Calculator() {
    for (int i = 0; i < N; i++) result[i] = 0;
  }

  std::ostream& display(std::ostream& os) const {
    for (int i = 0; i < N; i++) {
      os << result[i]; if (N - i > 1) os << ",";
    }
    os << std::endl;
    return os;
  }

  void add(const T* arr1, const T* arr2) {
    for (int i = 0; i < N; i++) {
      result[i] = arr1[i] + arr2[i];
    }
    uses++;
  }

  static int used() { return uses; } // class function
};

template<typename T, int N> // not spec, generic
int Calculator<T, N>::uses{}; // 0

//spec for where T = float, N = 10
template <>
int Calculator<float, 10>::uses = 120;

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, Calculator<T, N>& calc) {
  return calc.display(os);
} 
#endif
