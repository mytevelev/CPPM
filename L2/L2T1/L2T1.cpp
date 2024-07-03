#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
using namespace std;

class Calculator 
{
private:
    double num1, num2;

public:
    bool set_num1(double num) 
    {
        if ( num ) 
        {
            num1 = num;
            return true;
        }
        return false;
    }

    bool set_num2( double num ) 
    {
        if (num ) 
        {
            num2 = num;
            return true;
        }
        return false;
    }

    double add() 
    {
        return num1 + num2;
    }

    double multiply() 
    {
        return num1 * num2;
    }

    double subtract_1_2() 
    {
        return num1 - num2;
    }

    double subtract_2_1() 
    {
        return num2 - num1;
    }

    double divide_1_2() 
    {
        return num1 / num2;
    }

    double divide_2_1() 
    {
        return num2 / num1;
    }
};

int main( void ) 
{
    Calculator calc;
    double num1, num2;

    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);

    while (true) 
    {
        cout << "Введите num1: ";
        cin >> num1;
        cout << "Введите num2: ";
        cin >> num2;

        if ( calc.set_num1(num1) && calc.set_num2(num2) ) 
        {
            cout << "num1 + num2 = " << calc.add() << endl;
            cout << "num1 - num2 = " << calc.subtract_1_2() << endl;
            cout << "num2 - num1 = " << calc.subtract_2_1() << endl;
            cout << "num1 * num2 = " << calc.multiply() << endl;
            cout << "num1 / num2 = " << calc.divide_1_2() << endl;
            cout << "num2 / num1 = " << calc.divide_2_1() << endl;
        }
        else 
        {
            cout << "Неверный ввод!" << endl;
        }
    }

    return 0;
}
