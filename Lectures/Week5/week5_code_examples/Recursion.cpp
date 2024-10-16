// Recursion.cpp
#include <iostream>
using namespace std;

bool isPrime(int num, int recur) {
  bool ret = false;
  if (num == 1 || recur == 1) // end cond1, prime
    ret = true;
  else if ((num % recur) == 0) // end cond2, no prime
    ret = false;
  else {
    ret = isPrime(num, recur - 1);
  }
  return ret;
}

bool isPrimeIter(int num) {
  bool ret = true;
  if (num != 1) {
    int i = num - 1;
    bool done = false;
    while (i > 1 && !done) {
      if (num % i == 0) {
        done = true;
        ret = false;
      }
      i--;
    }
  }
  return ret;
}

int main() {
  
  char decision = 'x';
  int num = 0;
  do {
    cout << "Enter a number to see if it's a prime number: ";
    cin >> num;
    //cout << num << (isPrime(num, num - 1) ? " is a prime" : " is not a prime") << endl;
    cout << num << (isPrimeIter(num) ? " is a prime" : " is not a prime") << endl;
    cout << "Want to enter another number? N to exit: ";
    cin >> decision;
  } while (decision != 'N');

}