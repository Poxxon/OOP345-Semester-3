#include <iostream>

struct mylonglonglongtype{
  int number;
  mylonglonglongtype(){
    number = 5;
  }
};

typedef mylonglonglongtype mylt;
typedef const mylonglonglongtype cmylt;

int main(){
  mylonglonglongtype object1; // really long
  mylt object2; // much shorter
  cmylt object3;
}
