// static-duration.cpp

#include <iostream>

void foo() {
   static int a = 1;
   std::cout << a++ << std::endl;
} // a doesn't go out of scope here / memory doesn't get released

int main(){
  
  foo();
  foo();
  foo();
}
