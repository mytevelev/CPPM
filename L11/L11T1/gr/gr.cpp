#include <iostream>
#include <windows.h>
#include <string>
#include "Greeter.h"

using namespace std;

int main() {
    // Установка кодировки консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Запрос имени пользователя
    string name;
    cout << "Введите имя: ";
    getline(cin, name);

    // Создание объекта класса Greeter и вызов метода greet
    Greeter greeter;
    string greeting = greeter.greet(name);

    // Вывод приветствия
    cout << greeting << endl;

    return 0;
}
