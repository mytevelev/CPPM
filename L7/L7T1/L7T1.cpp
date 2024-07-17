
#include <windows.h>
#include <iostream>
using namespace std;

// Объявляем символьную константу MODE
#define MODE 1

// Проверяем, что MODE определена
#ifndef MODE
#error "Необходимо определить MODE"
#endif


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#if MODE == 0
    cout << "Работаю в режиме тренировки" << endl;
#elif MODE == 1
    cout << "Работаю в боевом режиме" << endl;

    // Определяем функцию add только если MODE равен 1
    auto add = [](int a, int b) {
        return a + b;
        };

    // Просим пользователя ввести два числа
    int num1, num2;
    cout << "Введите число 1: ";
    cin >> num1;
    cout << "Введите число 2: ";
    cin >> num2;

    // Выводим результат сложения
    cout << "Результат сложения: " << add(num1, num2) << endl;
#else
    cout << "Неизвестный режим. Завершение работы" << endl;
#endif

    return 0;
}
