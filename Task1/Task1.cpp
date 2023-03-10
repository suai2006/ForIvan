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

    int summ = 0;
    int proizv = 0;
    int minABSidx = 0;
    int maxABSidx = 0;
    int min = abs(list.at(0));
    int max = abs(list.at(0));

    for (int i = 1; i < list.size(); i++)
    {
        int num = list.at(i);
        if (min > abs(num)) 
        {
            minABSidx = i;
            min = abs(num);
        }
        if (max < abs(num)) 
        {
            maxABSidx = i;
            max = abs(num);
        }
    }

    int start = 0;
    int end = 0;
    if (minABSidx > maxABSidx) 
    {
        start = maxABSidx;
        end = minABSidx;
    }
    else 
    {
        start = minABSidx;
        end = maxABSidx;
    }

    for (int i = 0; i < list.size(); i++)
    {
        if (list.at(i) > 0) summ += list.at(i);
        if (i > start && i < end) 
        {
            if (proizv == 0) proizv = list.at(i);
            else proizv *= list.at(i);
        }
    }
    cout << endl;
    printLine("Сумма положительных элементов ровна " + to_string(summ));
    printLine("Произведение равно " + to_string(proizv));


    printKeyEnter("для завершения нажмите Enter...");
}