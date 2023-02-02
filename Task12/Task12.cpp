#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

float cylinderVolume(float r, float h) 
{
    return M_PI * pow(r, 2) * h;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    // ввод вывод с клавиатуры сделаешь сам

    float V = cylinderVolume(6.5, 15.0);
    cout << "Объем целиндра равен: " << V;

    cout << endl << "для завершения нажмите Enter..." << endl;
    cin.get();
}