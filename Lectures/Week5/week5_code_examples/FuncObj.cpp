// FuncObj.cpp
#include <iostream>
using namespace std;

enum class Order { min, max};

template <typename T>
class Compare {
  Order ord;
  static unsigned uses;
public:
  Compare(Order o) : ord(o) {}
  bool operator() (T& a, T& b) const { // func call operator ()
    uses++;
    return ord == Order::min ? a < b : a > b;
  }
  void operator() () const{
    cout << "Nothing happens" << endl;
  }
  static unsigned getUses() { return uses; };
};

template <typename T>
unsigned Compare<T>::uses = 0;


template <typename T>
bool compareTwoArrays(T arr1[], T arr2[], int len, const Compare<T>& comp) {

  int a1results = 0;
  int a2results = 0;

  for (int i = 0; i < len; ++i) {
    a1results += comp(arr1[i], arr2[i]);
    a2results += comp(arr2[i], arr1[i]);
  }

  return a1results > a2results;
}

int main() {

  int arr1[]{ 1, 2, 3 };
  int arr2[]{ 1, 3, 3 };

  Compare<int> c1(Order::min);
  Compare<int> c2(Order::max);
  c1();
  c2(arr1[0], arr2[0]);

  if (compareTwoArrays(arr1, arr2, 3, c2)) {
    cout << "Arr1 is smaller than Arr2" << endl;
  }
  else {
    cout << "Arr2 is smaller than Arr1" << endl;
  }

  cout << "Uses: " << c1.getUses() << endl;
}
