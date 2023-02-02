#include <iostream>

using std::cout;
using std::cin;
using std::endl;

float dohod(float summ, float stavka, float srok) 
{
    float result = summ * (stavka / 100 / 365) * srok;
    return result;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    // ввод сделаешь сам
    float srok = 365.0 * 3.0;
    float summ = 185000.0;
    float stavka = 8.5;
    
    float result = dohod(summ, stavka, srok);
    std::cout << "При вкладе суммы " << summ << " уе. со ставкой " << stavka << "%" << endl;
    std::cout << "Доход составит " << result << " уе." << endl;
}
