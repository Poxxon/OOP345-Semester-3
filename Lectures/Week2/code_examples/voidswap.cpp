#include <iostream>
using namespace std;

void myswap(void** a, void** b) {

  std::cout << "In Swap" << endl;
  cout << "Address of a: " << a << endl;
  cout << "Address of b: " << b << endl;
  cout << "Address of *a: " << *a << endl;
  cout << "Address of *b: " << *b << endl;

  void* c = *a;
  *a = *b;
  *b = c;

  std::cout << "After Swap" << endl;
  cout << "Address of a: " << a << endl;
  cout << "Address of b: " << b << endl;
  cout << "Address of *a: " << *a << endl;
  cout << "Address of *b: " << *b << endl;
}

int main() {

//#define ex1

#ifdef ex1
  int* a = new int; *a = 3;
  int* b = new int; *b = 6;
#else
  double* a = new double; *a = 4.5;
  double* b = new double; *b = 9.5;
#endif

  cout << "a : " << *a << endl;
  cout << "b : " << *b << endl;
  myswap(reinterpret_cast<void**>(&a), reinterpret_cast<void**>(&b));
  cout << "a : " << *a << endl;
  cout << "b : " << *b << endl;

  delete a, b;
}
