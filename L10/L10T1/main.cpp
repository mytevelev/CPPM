#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    // ��������� ��������� ������� �� UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // ������ ����� ������������
    string name;
    cout << "������� ���: ";
    getline(cin, name);

    // ����������� ������������
    cout << "������������, " << name << "!" << endl;

    return 0;
}
