#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void compareInteger(float a, float b)
{
    if (a > b) cout << a << " > " << b << endl;
    if (a < b) cout << a << " < " << b << endl;
    if (a == b) cout << a << " = " << b << endl;
}

int main()
{
    // ввод сделаешь сам
    setlocale(LC_CTYPE, "Russian");

    compareInteger(10.0, 6.0);    
    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
}