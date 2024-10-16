#include <iostream>
#include "tempfunc.h"
using namespace std;

//#define ex1
#define ex2

int main() {

#ifdef ex1
  int a = 1, b = 2;
  temp_swap(a,b);
  cout << "a: " << a << " b: " << b << endl;

  char x = 'A', y = 'B';
  temp_swap(x,y);
  cout << "x: " << x << " y: " << y << endl;
#endif

#ifdef ex2

  int a = 55, b = 100;
  int larger = maximum(a, b);

  cout << "Between " << a << " and " << b << 
    ", the larger one is: " << larger << endl;


  const char* str1 = "apple";
  const char* str2 = "orange";
  const char* bigger = maximum(str1, str2);

  cout << "Between " << str1 << " and " << str2 << 
    ", the larger one is: " << bigger << endl;


  double c = 123.33, d = 444.44;
  float e = 777.77, f = 33.22;

  double giant = maximum<double>(c, d);
  float huge = maximum<float>(e, f);

#endif
}