#include <iostream>
#include <utility> // for std::move

class Resource {
public:
    int* data;

    // Constructor
    Resource(int size) {
        data = new int[size];
        std::cout << "Resource allocated!" << std::endl;
    }

    // Move Constructor
    Resource(Resource&& other) noexcept : data(other.data) {
        other.data = nullptr;  // nullify the source
        std::cout << "Resource moved!" << std::endl;
    }

    // Destructor
    ~Resource() {
        delete[] data;
        std::cout << "Resource deallocated!" << std::endl;
    }
};

int main() {
    Resource res1(10);       // allocate resource
    Resource res2(std::move(res1)); // move resource

    return 0;
}
