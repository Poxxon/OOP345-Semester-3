#include <iostream>
using namespace std;

//#define ex1
//#define ex2
#define ex3

int main() {

#ifdef ex1
  int w = 2;
  int x = 2.2;
  int y{ 4 }; // preferred universal method of initialization
  int z = { 4 };

  cout << "w : " << w << endl;
  cout << "x : " << x << endl;
  cout << "y : " << y << endl;
  cout << "z : " << z << endl;
#endif

#ifdef ex2
  auto p{ 1.2 };
  cout << "p : " << p << endl;

  //auto h [] { 1, 2, 3, 4, 5 }; // auto array attempt
#endif

#ifdef ex3
  int a[] = { 1,2,3 };
  int b[]{ 1,2,3.3 };
  int c[5]{ 1,2,3 };
  int d[5]{};
  const int n = 5;
  int* f = new int[n]{ 1,2,3 };
  int* g = new int[n]{};
#endif
}