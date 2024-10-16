#include <iostream>

enum class TrafficLight { Red, Yellow, Green };

int main() {
    TrafficLight light = TrafficLight::Green;

    if (light == TrafficLight::Red) {
        std::cout << "Stop!" << std::endl;
    } else if (light == TrafficLight::Green) {
        std::cout << "Go!" << std::endl;
    }

    return 0;
}
