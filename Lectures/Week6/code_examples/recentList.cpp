#include <iostream>
#include "recentList.h"
using namespace std;

int main() {

  RecentList<int> rl;
  rl.insert(1);
  rl.insert(5);
  rl.insert(10);

  int arr[3];
  rl.copyToArray(arr, 3);

  for (auto x : arr) {
    cout << x << endl;
  }
}