// calculator.cpp

#include <iostream>
#include "calculator.h"
using namespace std;

int main() {

  int iarr1[]{ 1,2,3 };
  int iarr2[]{ 3,4,5 };

  Calculator<int, 3> c1;
  c1.add(iarr1, iarr2);
  cout << "Adding iarr1 and iarr2:" << endl;
  cout << c1 << endl;

  Calculator<int, 3> c3;
  c3.add(iarr1, iarr2);
  cout << "Adding iarr1 and iarr2:" << endl;
  cout << c3 << endl;

  double darr1[]{ 1.1,2.2,3.3 };
  double darr2[]{ 1.1,2.2,3.3 };
  Calculator<double, 3> d1;
  d1.add(darr1, darr2);
  cout << "Adding darr1 and darr2:" << endl;
  cout << d1 << endl;

  Calculator<int, 1> c2;
  int iarr3[]{ 1 };
  int iarr4[]{ 3 };
  c2.add(iarr3, iarr4);

  cout << "Number of times c1 calc used: " << c1.used() << endl;
  cout << "Number of times d1 calc used: " << d1.used() << endl;

  Calculator<float, 10> f1;
  cout << "Number of times f1 calc used: " << f1.used() << endl;

}