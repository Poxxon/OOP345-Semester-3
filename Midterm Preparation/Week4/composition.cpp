#include <iostream>
#include <string>

class Engine {
    std::string type;

public:
    Engine(const std::string& t) : type(t) {
        std::cout << "Engine created: " << type << std::endl;
    }
    ~Engine() {
        std::cout << "Engine destroyed: " << type << std::endl;
    }
    void start() const {
        std::cout << "Engine " << type << " started." << std::endl;
    }
};

class Car {
    Engine engine;

public:
    Car(const std::string& engineType) : engine(engineType) {
        std::cout << "Car created." << std::endl;
    }
    ~Car() {
        std::cout << "Car destroyed." << std::endl;
    }
    void drive() const {
        engine.start();
        std::cout << "Car is driving." << std::endl;
    }
};

int main() {
    Car car("V8");
    car.drive();
    return 0;
}
