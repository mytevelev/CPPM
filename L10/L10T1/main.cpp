#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
<<<<<<< HEAD
    // ��������� ��������� ������� �� UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // ������ ����� ������������
    string name;
    cout << "������� ���: ";
    getline(cin, name);

    // ����������� ������������
    cout << "������������, " << name << "!" << endl;
=======
    // Установка кодировки консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Запрос имени пользователя
    string name;
    cout << "Введите имя: ";
    getline(cin, name);

    // Приветствие пользователя
    cout << "Здравствуйте, " << name << "!" << endl;
>>>>>>> 3195b580a1c0b895cc74c05c2b45532fe70f1f50

    return 0;
}
