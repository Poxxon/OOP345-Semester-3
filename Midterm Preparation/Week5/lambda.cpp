#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string sentence = "hello world";
    std::for_each(sentence.begin(), sentence.end(), [](char &c) {
        c = toupper(c);
        if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            std::cout << c;
        }
    });
    return 0;
}
