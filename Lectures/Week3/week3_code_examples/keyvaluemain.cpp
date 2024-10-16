#include <iostream>
#include <string>
#include "keyvalue.h"
using namespace std;

int main() {

  Keyvalue<int, std::string> kv1;
  Keyvalue<int, int> kv2;

  cin >> kv1;
  cin >> kv2;
  cout << kv1;
  cout << kv2;

  Keyvalue<int, std::string> kv3(111, "Orange");
  kv1 += kv3;
  cout << kv1;
}