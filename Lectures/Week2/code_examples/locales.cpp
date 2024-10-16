#include <iostream>
#include <fcntl.h> // provides setmode
#include <io.h> // provides the _O_U16TEXT constant
using namespace std;
int main()
{
    // the following line is required to print wide
    // characters to Windows Console
    _setmode(_fileno(stdout), _O_U16TEXT);
  
    wchar_t w = L'\x30A2';
    wstring ws = L"\x30CF\x30ED\x30FC \x30EF\x30FC\x30EB\x30C9";

    wcout << 'a' << endl;
    wcout << "w : " << w << endl;

    wcout << "Hello World" << endl;
    wcout << "ws : " << ws << endl;
}