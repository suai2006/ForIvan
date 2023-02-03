#include <iostream>
#include <string>
#include <windows.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

auto printData(string field)
{

    string output = "";
    cout << field << ": ";
    getline(cin, output);
    return output;
}

void printLine(string text)
{
    cout << text << endl;
}

void printKeyEnter(string text)
{
    cout << endl << text << endl;
    cin.get();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str1 = printData("Введите первую строку");
    string str2 = printData("Введите вторую строку");

    string result = str1.append(str2);
    printLine(result);

    printKeyEnter("для завершения нажмите Enter...");
}