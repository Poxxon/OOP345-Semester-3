#include <iostream>
using namespace std;

int main() {

  int x[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

//#define regfor

#ifdef regfor
  for (int i = 0; i < sizeof(x) / sizeof(int); ++i) {
    cout << "reg-item: " << x[i] << endl;
  }
#else
  for (int& item : x) { // for each item in the array called x
    cout << "range-item: " << item << endl;
  }
#endif
}