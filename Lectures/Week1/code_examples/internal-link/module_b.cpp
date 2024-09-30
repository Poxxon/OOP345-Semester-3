// module_b.cpp

#include <iostream>
void display();
static int local = 2;

int main() {
  display();
  display();

  std::cout << "****************************" << std::endl;

  std::cout << "local is at " << &local << '\n'; 
  std::cout << "local is " << local++ << '\n';
}
