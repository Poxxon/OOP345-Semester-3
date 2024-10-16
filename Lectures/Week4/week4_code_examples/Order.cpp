// Order.cpp
#include <iostream>
#include <typeinfo>
using namespace std;

//#define order
//#define prepost
//#define szof
//#define dtype
//#define confusing
#define ternary

#ifdef szof
struct temp {
  int thing; // 4
  char stuff; // 1
};

void foosize(int arr[]) {
  cout << "sizeof arr in function: " << sizeof arr << endl;
}
#endif


#ifdef order

struct Box {
  int weight{  };
  int items[5]{ 1, 2, 3, 4, 5};

  void display() const {
    cout << "Box Weight: " << weight<< endl;

    for (int i = 0; i < 5; ++i) {
      int temp = *this.items[i]; // *(this.items[i])
      cout << i + 1 << ": " << temp << endl;
    }
  }
};

#endif

int main() {

#ifdef order
  Box b;
  b.display();
#endif order

#ifdef prepost
  int i = 0;
  //(i++)++; // i++ as an expression is a prvalue - (i++)++ -> (1)++
  ++(++i); // ++i as an expression is a lvalue - ++(++i) -> ++(i)

  unsigned y = 0u;
  --y; // ???
  cout << "value of underflowed unsigned y: " <<  y << endl;
  ++y;
  cout << "value of overflowed unsigned y: " <<  y << endl;
  //cout << "value of y negated: " <<  -y << endl;

  int z = INT_MAX;
  cout << "value of max int z: " << z << endl;
  ++z;
  cout << "value of max int z overflowed: " << z << endl;
  --z;
  cout << "value of max int z overflowed: " << z << endl;
  cout << "value of max int z overflowed negated: " << -z << endl;
#endif

#ifdef szof
  int x = 4, y = 2;
  cout << "sizeof int: " << sizeof(int) << endl;
  cout << "sizeof double: " << sizeof(double) << endl;
  cout << "sizeof char: " << sizeof(char) << endl;
  cout << "sizeof x: " << sizeof(x) << endl;
  cout << "sizeof y: " << sizeof(y) << endl;
  cout << "sizeof an expression1:" << sizeof x + y << endl;
  cout << "sizeof an expression2: " << sizeof(x + y) << endl;

  cout << "sizeof an temp struct: " << sizeof(temp) << endl;

  int iarr[5]{ 1, 2, 3, 4, 5 };
  cout << "sizeof iarr: " << sizeof(iarr) << endl;
  foosize(iarr);

  char carr[5]{ 'a','b','c','d','e' };

  for (int i = 0; i < sizeof(carr); ++i)
    cout << carr[i] << endl;

#endif

#ifdef dtype
  int x = 10;
  double y = 5.5;
  double& z  = y;
  decltype(x) var1 = 1; // type is int
  decltype(y) var2 = 2.2; // type is double
  decltype(x + y) var3 = 3; // type is int
  decltype(z) var4 = var2; // type is double&

  cout << "Type of var1: " << typeid(var1).name() << endl;
  cout << "Type of var2: " << typeid(var2).name() << endl;
  cout << "Type of var3: " << typeid(var3).name() << endl;
  cout << "Type of var4: " << typeid(var4).name() << endl;

#endif

#ifdef confusing
  int x = 3;
  x = x + ++x;
  cout << "Val of x: " << x << endl;
#endif

#ifdef ternary
  int x = 1;
  int y = 0;
  cout << (x == 0 ? "Zero" : "Two") << endl;
#endif
}