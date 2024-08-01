// L11T2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <string>
#include "leaver.h"

using namespace std;

int main() 
{
    // Установка кодировки консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Запрос имени пользователя   ----------
    string name;
    cout << "Введите имя: ";
    getline(cin, name);

    // Создание объекта класса Greeter и вызов метода greet
    Leaver l;
    string greeting = l.leave(name);

    // Вывод приветствия
    cout << greeting << endl;

    return 0;
}
