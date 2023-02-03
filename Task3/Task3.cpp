#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <ctime>

using std::string;
using std::cout;
using std::cin;
using std::setw;
using std::left;
using std::endl;
using std::vector;
using std::to_string;

auto printData(string field)
{

    string output = "";
    cout << field << ": ";
    getline(cin, output);
    return output;
}

void printKeyEnter(string text)
{
    cout << endl << text << endl;
    cin.get();
}

void printLine(string text)
{
    cout << text << endl;
}

int Random(int min, int max) {
    return min + rand() % (max - min);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    int n = stoi(printData("Введите размер массива"));
    vector<int> list;

    for (int i = 0; i < n; i++)
    {
        int a = Random(-10, 10);
        cout << a << " ";
        list.push_back(a);
    }

    cout << endl;

    int summ1 = 0;
    int summ2 = 0;
    int start = -1;
    int end = -1;

    for (int i = 0; i < list.size(); i++)
    {
        if (start != -1) break;
        if (list.at(i) < 0) start = i;
    }

    for (int i = list.size() - 1; i >= 0; i--)
    {
        if (end != -1) break;
        if (list.at(i) < 0) end = i;
    }



    for (int i = 0; i < list.size(); i++)
    {
        if (!(i % 2)) summ1 += list.at(i);
        if (i > start && i < end) summ2 += list.at(i);

    }
    cout << endl;

    printLine("Сумма нечетных элементов равно " + to_string(summ1));
    if (start == -1 && end == -1)  printLine("В массиве нет отрицательных чисел");
    if (start != -1 && end != -1 && start == end)  printLine("В массиве одно отрицательное чисело");
    if ((start == -1 || end == -1) && start != end)  printLine("В массиве одно отрицательное чисело");
    if (start != -1 && end != -1 && start != end)   printLine("Сумма элементов между отрицательными числами ровна " + to_string(summ2));

    printKeyEnter("для завершения нажмите Enter...");
}