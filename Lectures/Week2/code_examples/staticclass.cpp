#include <iostream>
using namespace std;

class Playdoh {
  int weight;
  char colour;
  //static int numberMade;

public:
  static int numberMade;
 
  Playdoh(int w, char c) : weight(w), colour(c) {
    numberMade++;
  }

  ~Playdoh() {
    numberMade--;
  }

  void display() const {
    cout << "Weight: " << weight << " Colour: " << colour << endl;
  }

//#define staticfunc
#ifdef staticfunc
  static int howManyMade() {
    return numberMade;
  }
#endif
};

int Playdoh::numberMade = 0;

int main() {



  Playdoh p(5, 'R'), p2(6, 'B');
  p.display();
  p2.display();

#ifdef staticfunc
  cout << "NumberMade1: " << Playdoh::howManyMade() << endl;
#else
  cout << "NumberMade1: " << Playdoh::numberMade << endl;
#endif

  {
    Playdoh p3(7, 'G'), p4(8, 'Y');
#ifdef staticfunc
    cout << "NumberMade1: " << Playdoh::howManyMade() << endl;
#else
    cout << "NumberMade1: " << Playdoh::numberMade << endl;
#endif

  }

#ifdef staticfunc
    cout << "NumberMade1: " << Playdoh::howManyMade() << endl;
#else
    cout << "NumberMade1: " << Playdoh::numberMade << endl;
#endif
}
