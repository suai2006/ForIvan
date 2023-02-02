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

auto printToList()
{
    vector<string> out;
    int count = 0;
    while (count < 5)
    {
        string num;
        cout << "Введите число: ";
        cin >> num;
        out.push_back(num);
        count++;
    }
    return out;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    string line;
    fstream file;
    int i = 0;
    int summ = 0;
    file.open("C:\\Users\\slava\\Documents\\ivan\\numbers.txt", fstream::app);

    vector<string> list = printToList();

    if (file.is_open())
    {
        for (auto& element : list) {
            file << element + "\n";
        }
    }

    file.close();

    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
    cin.get();
}