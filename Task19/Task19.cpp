#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::fstream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::stringstream;

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

    string line;
    fstream file;
    float summ = 0.0;
    int count = 0;

    file.open("C:\\Users\\slava\\Documents\\ivan\\numbers.txt", std::fstream::in);
    
    if (file.is_open())
    {       
        while (getline(file, line))
        {
            summ += stoi(line);
            count++;
        }
    }

    float srSumm = summ / count;
    cout << "Среднее арифметическое равно " << srSumm << endl;

    file.close();

    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
}