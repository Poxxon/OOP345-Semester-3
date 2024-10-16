// Porridge.cpp
#include "Porridge.h"

const char* badIntExp::what() const noexcept {
  return message.c_str();
}

tooCold::tooCold() {
  message = " is too cold";
}

tooHot::tooHot() {
  message = " is too hot";
}

Porridge::Porridge() {
}

Porridge::Porridge(int amt, int heat) {
  amount = amt;
  this->heat = heat;
}

Porridge& Porridge::operator+=(unsigned amt) {
  amount = amount + amt;
  return *this;
}

void Porridge::warmUp() {
  heat += 10;
}

void Porridge::coolDown() {
  heat -= 10;
}

std::ostream& Porridge::display(std::ostream& os) const {
  os << "Porridge, amount: " << amount << " heat: " << heat << std::endl;
  return os;
}

std::ostream& Porridge::eat(std::ostream& os) {

  if (amount) {
    if (heat > 40)
      throw tooHot();
    if (heat < 10)
      throw tooCold();
    os << "This bowl of porridge is just right" << std::endl;
    amount = 0;
  }
  else
    os << "Empty bowl of porridge" << std::endl;
  
  return os;
}

int main() {

  //try {
  //  throw std::underflow_error("Hello");
  //}
  //catch(std::underflow_error e) {
  //  std::cout << e.what() << std::endl;
  //}


  Porridge bowl1;
  int choice = 0;
  do {
    std::cout << std::endl; 
    bowl1.display();

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Eat Porridge" << std::endl;
    std::cout << "2. Heat up Porridge" << std::endl;
    std::cout << "3. Cool down Porridge" << std::endl;
    std::cout << "4. Add more Porridge" << std::endl;
    std::cout << "Enter Choice (0 to Exit): ";
    std::cin >> choice;
    system("CLS");

    try {
      switch (choice) {
      case 1:
        bowl1.eat();
        break;
      case 2:
        bowl1.warmUp();
        break;
      case 3:
        bowl1.coolDown();
        break;
      case 4:
        bowl1 += 30;
        break;
      }
    }
    catch (tooCold e) {
      std::cout << "This porridge" << e.what() << std::endl;
    }
    catch (tooHot e) {
      std::cout << "This porridge" << e.what() << std::endl;
    }
  } while (choice != 0);

}
