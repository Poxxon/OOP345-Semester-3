#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int age;

public:
    // Constructor
    Employee(string n, int a) : name(n), age(a) {}

    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for name
    void setName(string n) {
        name = n;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Setter for age
    void setAge(int a) {
        age = a;
    }

    void display() const {
        cout << "Employee Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Employee e1("Alice", 30);
    e1.display();
    
    // Change name and age using setters
    e1.setName("Bob");
    e1.setAge(35);
    e1.display();
    
    return 0;
}
