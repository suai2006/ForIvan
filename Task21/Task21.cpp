#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <limits>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::setw;
using std::left;
using std::endl;
using std::vector;
using std::stringstream;
using std::to_string;

struct STUDENT {
    string Name;
    string Group;
    string Birthday;
    vector<int> Achievement;
};

vector<STUDENT> studentsList;

auto split(string const& str, const char delim)
{
    vector<int> out;
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) {
        out.push_back(stoi(s));
    }
    return out;
}
float getBall(vector<int> marks) 
{
   
    int summ = 0;
    for (int mark : marks)
    {
        summ += mark;
    }

    float ball = summ / marks.size();
    return ball;
}

auto printData(string field)
{
    
    string output = "";
    cout << field << ": ";
    //!!! добавить валидацию, влом
    getline(cin, output);
    return output;
}

void printRow(string col1, string col2, string col3) 
{
    cout << left << setw(6) << col1 << left << setw(22) << col2 << std::setw(12) << col3 << endl;
    for (int i = 0; i < 40; i++)cout << '-';
    cout << endl;
}

void printKeyEnter(string text)
{
    cout << endl << text << endl;
    cin.get();
}

void printLine(string text)
{
    cout << endl << text << endl << endl;
}
void addStudent() {
    struct STUDENT student;

    int studentNum = studentsList.size() + 1;
    cout << "Студент №" << studentNum << endl << endl;
    student.Name = printData("Введите ФИО");
    student.Group = printData("Введите номер группы");
    student.Birthday = printData("Введите дату рождения");
    string mark = printData("Введите успеваемость");
    student.Achievement = split(mark, ',');
    studentsList.push_back(student);
}

void selectTask()
{
    string task = printData("Продолжить заполнять список [да/нет]?");
    if (task == "да")
    {
        addStudent();
        selectTask();
    }
    else if (task != "нет" && task != "да")
    {
        printLine("Ошибка: не известная команда");
        selectTask();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    addStudent();
    selectTask();

    printKeyEnter("для выводы списка студентов, нажмите Enter...");
    printLine("Список студентов, чей проходной балл выше 4,0");

    printRow("ID# ", "FIO ", "Group");
    int num = 1;
    for (auto& student : studentsList)
    {
        float ball = getBall(student.Achievement);
        if (ball < 4.0) continue;
        printRow(to_string(num), student.Name, student.Group);
        num++;
    }    

    printKeyEnter("для завершения нажмите Enter...");
}