#include <iostream>
int main() {
    bool flag = true;
    char c = 'A';
    wchar_t wc = L'A';      // wide character
    char16_t c16 = u'A';    // UTF-16 character
    char32_t c32 = U'A';    // UTF-32 character

    std::cout << "Boolean: " << flag << std::endl;
    std::cout << "Char: " << c << std::endl;
    std::wcout << L"Wide char: " << wc << std::endl;

    return 0;
}
