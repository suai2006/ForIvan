#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void writeLine(int count, string const& letter) 
{
    string str = "";
    for (int i = 0; i < count; i++) str += letter;
    cout << str << endl;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    writeLine(15, "Ф");
    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
}