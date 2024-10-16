// Templates and Inheritance
// tempinherit.cpp
#include <iostream>

template<typename T>
class Base {
  T value;
public:
  T getValue() { return value; }
  void set(const T& v) { value = v; }
  void display() const { std::cout << value << std::endl; }
};

template<typename T, typename S>
class Derived : public Base<T> {
  S value2;
public:
  void set(const T& v) { Base<T>::set(v); }
};

int main() {
     Derived<double, int> d;
     d.set(12);
     d.display();
     std::cout << d.getValue() << std::endl; // we call the function getValue() -> get result -> dislay the result
}