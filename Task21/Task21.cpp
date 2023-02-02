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

struct PERSON {
    string Name;
    string Group;
    string Birthday;
    string Achievement; // влом делать сейчас массив
} person_type;

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
float getBall(vector<string> marks) 
{
   
    int summ = 0;
    for (string mark : marks)
    {
        summ += stoi(mark);
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
        cout << "Студент №" << studentNum <<endl << endl;
        student.Name = printData("Введите ФИО");
        student.Group = printData("Введите номер группы");
        student.Birthday = printData("Введите дату рождения");
        student.Achievement = printData("Введите успеваемость");

        studentsList.push_back(student);
        std::cout << "2. size: " << studentsList.size() << '\n';
        count++;
    }

    cout << endl << "для выводы списка студентов, нажмите Enter..." << endl;
    cin.get();

    cout << endl << "Список студентов, чей проходной балл выше 4,0" << endl << endl;

    cout << left << setw(6) << "ID# " << left << setw(22) << "FIO "  << std::setw(12) << "Group" << endl;

    int num = 1;
    for (auto& student : studentsList)
    {
        
        vector <string> marks = split(student.Achievement, ',');
        float ball = getBall(marks);
        if (ball < 4.0) continue;

        cout << left << setw(6) << num << left << setw(22) << student.Name << std::setw(12) << student.Group << endl;
        num++;
    }    

    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
}