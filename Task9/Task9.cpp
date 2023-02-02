#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::getline;
using std::stringstream;
using std::endl;

auto split(string const& str, const char delim)
{
    vector<string> out;
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
    return out;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    vector<string> out = split("Собака ворона кошка", ' ');
    cout << out[0] << endl;

    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
}