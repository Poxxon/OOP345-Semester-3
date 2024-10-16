#include <iostream>
#include <string>

class Teacher {
    std::string name;

public:
    Teacher(const std::string& n) : name(n) {}
    const std::string& getName() const {
        return name;
    }
};

class Classroom {
    const Teacher* teacher;

public:
    void assignTeacher(const Teacher& t) {
        teacher = &t; // Association: Classroom uses Teacher, but doesn’t own it
    }
    void showTeacher() const {
        if (teacher) {
            std::cout << "Teacher assigned: " << teacher->getName() << std::endl;
        } else {
            std::cout << "No teacher assigned yet." << std::endl;
        }
    }
};

int main() {
    Teacher teacher("Mr. Smith");
    Classroom room;

    room.assignTeacher(teacher);
    room.showTeacher();

    return 0;
}
