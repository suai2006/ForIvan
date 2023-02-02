#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string cleanStr(const int start, const int size, string const& from)
{
    string output = from;
    string replacer = ""; // на что заменяем
    output.replace(start, size, replacer);

    return output;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    string input = "Собака ворона кошка ворона собака";

    string str = cleanStr(8, 7, input);
    cout << input << endl << str << endl;

    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
}