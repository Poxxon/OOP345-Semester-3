// farmMain.cpp

#include <iostream>

int shared_butter = 50;

void useButterA();
void useButterB();

int main(){
  useButterA();
  useButterB();
  std::cout << "****" << std::endl; 
  useButterB();
  useButterA();
}
