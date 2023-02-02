#include <iostream>

using std::cout;
using std::cin;
using std::endl;

float procent(float num) 
{
    float proc = 13;
    float result = (num * proc) / 100;
    return result;
}
int main()
{
    setlocale(LC_CTYPE, "Russian");
    
    float num = 15269;
    float result = procent(15269);
    std::cout << "13% от " << num << " = " << result << endl;

    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
}