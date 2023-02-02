#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using std::string;
using std::fstream;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    fstream file;
    int i = 0;
    int summ = 0;
    file.open("C:\\Users\\slava\\Documents\\ivan\\phone.txt", fstream::app);
    cout << "Добавление в телефонный справчник" << endl;
    if (file.is_open())
    {
        string lastName;
        string firstName;
        string midleName;
        string phone;

        cout << "Введите Фамилию: ";
        cin >> lastName;
        file <<  "Фамилия: " + lastName + "\n";
        cout << "Введите Имя: ";
        cin >> firstName;
        file << "Имя: " + firstName + "\n";
        cout << "Введите Отчество: ";
        cin >> midleName;
        file << "Отчество: " + midleName + "\n";
        cout << "Введите телефон: ";
        cin >> phone;
        file << "Телефон: " + phone + "\n\n";
        cout << endl << "Информация добавлена" << endl;
    }

    file.close();

    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
    cin.get();
}