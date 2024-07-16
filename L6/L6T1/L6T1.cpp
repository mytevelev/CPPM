#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
#include "mheader.h"


using namespace std;

int main() 
{
    double num1, num2;
    int operation;

    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    cin >> operation;
    
    switch (operation) {
    case 1:
        cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
        break;
    case 2:
        cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
        break;
    case 3:
        cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
        break;
    case 4:
        cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
        break;
    case 5:
        cout << num1 << " в степени " << num2 << " = " << power(num1, num2) << endl;
        break;
    default:
        cout << "Неверная операция!" << endl;
    }

    return 0;
}
