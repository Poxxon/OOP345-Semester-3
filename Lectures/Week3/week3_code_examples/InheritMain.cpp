//InheritMain.cpp

#include <iostream>
#include <typeinfo> // typeid
#include "Compound.h"
#include "Playdoh.h"
#include "Clay.h"
using namespace std;

Compound* produce() {
  Compound* c = nullptr;
  cout << "Do you want a Playdoh or a Clay (P or C): ";
  char selection = 'X';
  cin >> selection;
  if (selection == 'P')
    c = new Playdoh();
  else
    c = new Clay();

  if (c) {
    cin >> *c;
  }

  return c;
}

//#define cloning
//#define compare
#define typeinf

int main() {

  Compound* mycomp = produce();
  cout << "***************************" << endl;
  cout << "Printing the details of the Compound: " << endl;
  cout << *mycomp << endl;

#ifdef cloning
  Compound* copy = mycomp;
  Compound* mycopy = mycomp->clone();
  cout << "***************************" << endl;
  cout << "Printing the details of the Copy: " << endl;
  cout << *mycopy << endl;
  delete mycopy;
#endif

#ifdef compare
  Compound* mycomp2 = produce();
  cout << "***************************" << endl;
  if (*mycomp2 == *mycomp)
    cout << "They're the same" << endl;
  else
    cout << "They're different" << endl;
  delete mycomp2;
#endif

#ifdef typeinf
  int i;
  int * ptr;
  cout << "i is: " << typeid(i).name() << endl;
  cout << "ptr is: " << typeid(ptr).name() << endl;

  Playdoh play;
  Clay clay;
  cout << "play is: " << typeid(play).name() << endl;
  cout << "clay is: " << typeid(clay).name() << endl;
  cout << "mycomp is: " << typeid(*mycomp).name() << endl;

#endif

  delete mycomp;
}