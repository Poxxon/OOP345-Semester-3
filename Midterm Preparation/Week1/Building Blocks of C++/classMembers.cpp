#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
public:
    void setDetails(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s;
    s.setDetails("Alice", 22);
    s.display();
    return 0;
}
