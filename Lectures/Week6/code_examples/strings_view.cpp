// strings_view.cpp

#include <iostream>
#include <cstring>
#include <string>
#include <string_view>
using std::cout;
using std::endl;
using std::string;
using std::string_view;

//#define ex1
//#define ex2
//#define ex3

#ifdef ex2
void* operator new(size_t count) {
  cout << "Num of bytes allocated: " << count << endl;
  return malloc(count);
}
#endif

int main() {

#ifdef ex1
  char str[]{ "Apples" };
  for (auto x : str) {
    cout << x << endl;
  }

  //char* strptr = new char[strlen(str) + 1];
  //strcpy(strptr, str);
  //for (auto x : strptr) {
  //  cout << x << endl;
  //}
  //delete[] strptr;
#endif

#ifdef ex2
  cout << "---------------string----------------" << endl;
  string str = "Apples";
  cout << str << endl;
  str = "Bananas";
  cout << str << endl;
  string str2 = "Coconuts";
  str == str2 ? (cout << "The same fruit" << endl) : (cout << "Diff fruits" << endl);
  for (auto x : str2)
    cout << x << endl;
#endif

#ifdef ex3
  cout << "---------------string view----------------" << endl;
  string str3{ "Apples" };
  string_view sview(str3);
  cout << sview << endl;
  string_view sview2("Bananas");
  cout << sview2 << endl;
  sview == sview2 ? (cout << "The same fruit" << endl) : (cout << "Diff fruits" << endl);
  sview2 = "Coconuts";
  cout << sview2 << endl;
#endif

}