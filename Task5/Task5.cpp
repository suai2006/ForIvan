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

float Random(float min, float max) {
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    int n = stoi(printData("Введите размер массива"));
    vector<float> list;

    for (int i = 0; i < n; i++)
    {
        float a = Random(-1.0, 1.0);
        cout << a << " ";
        list.push_back(a);
    }

    cout << endl;
    
    float summ = 0;
    int start = -1;
    int end = -1;
    int minIndex = 0;
    float min = list.at(0);

    for (int i = 0; i < list.size(); i++)
    {
        if (min > list.at(i)) 
        {
            min = list.at(i);
            minIndex = 1;
        }
    }

    for (int i = 0; i < list.size(); i++)
    {
        if (start != -1) break;
        if (list.at(i) >= 0) start = i;
    }

    for (int i = list.size() - 1; i >= 0; i--)
    {
        if (end != -1) break;
        if (list.at(i) >= 0) end = i;
    }



    for (int i = 0; i < list.size(); i++)
    {
        if (i > start && i < end) summ += list.at(i);
    }
    cout << endl;

    printLine("минимальный элемент массива равен " + to_string(min));
    if (start == -1 && end == -1)  printLine("В массиве нет положительных чисел чисел");
    if (start != -1 && end != -1 && start == end)  printLine("В массиве одно положительное чисело");
    if ((start == -1 || end == -1) && start != end)  printLine("В массиве одно положительное чисело");
    if (start != -1 && end != -1 && start != end)   printLine("Сумма положительных элементов ровна " + to_string(summ));
    
    printKeyEnter("для завершения нажмите Enter...");
}