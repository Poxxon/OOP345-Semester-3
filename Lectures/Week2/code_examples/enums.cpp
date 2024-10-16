#include <iostream>
using namespace std;

enum Traffic_light { red, yellow, green};
//enum Warning_level { green, blue, yellow, orange, red};

Traffic_light& operator++(Traffic_light& traf) {

  switch (traf) {
    case red: return traf = green;
    case yellow: return traf = red;
    case green: return traf = yellow;
  }

}

int main() {

  Traffic_light signal = red;
  //int temp = red; // can assign to an enum
  int count = 0;
  cout << "Enter the number to change the traffic light: ";
  cin >> count;

  for (int x = 0; x < count; ++x) {
    ++signal; // call the ++ operator on Traffic_light
  }

  switch (signal) {
    case red: 
      cout << "Red Light" << endl;
      break;
    case yellow:
      cout << "Yellow Light" << endl;
      break;
    case green:
      cout << "Green Light" << endl;
      break;
  }
  
}