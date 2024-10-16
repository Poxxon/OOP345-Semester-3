// Lambda.cpp
#include <iostream>
using namespace std;

int value(const char* c) {

  int ret = 0;
  int temp = 0;
  int temp2 = 0;

  auto check_consonant = [temp, temp2](char c) mutable -> bool {
  c = toupper(c);
  temp += 2;
  temp2 += 2;
  cout << "temp: " << temp << " temp2: " << temp2 << endl;
  return c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U';
  };

  for (int i = 0; c[i]; ++i) {
    ret += check_consonant(c[i]);
  }
  cout << "temp: " << temp << " temp2: " << temp2 << endl;
  return ret;
}

void display(const char* prompt, void (*funcX)() ) {
  cout << prompt << " ";
  funcX();
}

int main() {

  display("Prompt1", []() { cout << "Hello from lambda1" << endl; });
  display("Prompt2", []() { cout << "Hello from lambda2" << endl; });
  display("Prompt3", []() { cout << "Hello from lambda3" << endl; });

  const char* str{ "Apples" };
  int v = value(str);
  cout << "V: " << v << endl;

}