#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    // Установка кодировки консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Запрос имени пользователя
    string name;
    cout << "Введите имя: ";
    getline(cin, name);

    // Приветствие пользователя
    cout << "Здравствуйте, " << name << "!" << endl;

    return 0;
}
