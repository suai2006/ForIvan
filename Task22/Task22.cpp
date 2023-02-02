#include <iostream>
#include <map>
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
using std::map;
using std::vector;
using std::stringstream;
using std::to_string;

struct PERSON {
    string Name;
    string Group;
    string Birthday;
    vector<int> Achievement;
} person_type;

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

bool getMarksCount(vector<int> marks)
{

    int cnt1 = 0;
    int cnt2 = 0;
    bool flag = false;
    for (int mark : marks)
    {
        if (mark == 5) cnt1++;
        if (mark == 4) cnt2++;
    }

    int count = cnt1 + cnt2;
    if (count == marks.size()) flag = true;

    return flag;
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

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int count = 0;

    vector<PERSON> studentsList;
    while (true)
    {
        if (count == 10)
        {
            cout << "Список студентов заполнен" << endl;
            break;
        }

        struct PERSON student;

        int studentNum = count + 1;
        cout << "Студент №" << studentNum << endl << endl;
        student.Name = printData("Введите ФИО");
        student.Group = printData("Введите номер группы");
        student.Birthday = printData("Введите дату рождения");
        string mark = printData("Введите успеваемость");
        student.Achievement = split(mark, ',');
        studentsList.push_back(student);
        std::cout << "2. size: " << studentsList.size() << '\n';
        count++;
    }

    cout << endl << "для выводы списка студентов, нажмите Enter..." << endl;
    cin.get();

    cout << endl << "Список студентов, чей проходной балл выше 4,0" << endl << endl;

    printRow("ID# ", "FIO ", "Group");

    int num = 1;
    for (auto& student : studentsList)
    {
        bool ball = getMarksCount(student.Achievement);
        if (!ball) continue;

        printRow(to_string(num), student.Name, student.Group);
        num++;
    }

    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
}