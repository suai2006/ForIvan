#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

auto splitStringByWord(string const& from, string const& delimer)
{
    string str = from;
    vector<string> output;
    auto pos = str.find(delimer);

    if (pos != string::npos)
    {
        output.push_back(str.substr(0, pos));
        output.push_back(str.substr(pos));
    }

    return output;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    vector<string> out = splitStringByWord("Собака ворона кошка ворона собака", "ворона");

    cout << out[0] << endl << out[1] << endl;
    
    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();

    return 0;
}