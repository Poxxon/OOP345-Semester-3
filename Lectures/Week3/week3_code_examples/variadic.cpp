// varidiac.cpp

#include <iostream>
using namespace std;

template <typename T>
void print(const T& t) {
  std::cout << t << std::endl;
}

template <typename T, typename... etc>
void print(const T& t, const etc&... args) { 
  cout << t << " | ";
  ((cout << " " << args << " | "), ...); // from c++17 - fold expressions
  //(cout << ... << args) << endl;
  //print(args...);
}

int main() {

  print(100);
  print(1, 2, 3, "apple", "oranges", 99);
}