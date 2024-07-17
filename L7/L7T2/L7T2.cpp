
#include <windows.h>
#include <iostream>
using namespace std;

// Определение макроса SUB для вычитания чисел
#define SUB(x, y) ((x) - (y)) //скобки!

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int a = 6;
    int b = 5;
    int c = 2;

    std::cout << SUB(a, b) << std::endl;            // Ожидается 1
    std::cout << SUB(a, b) * c << std::endl;        // Ожидается 2
    std::cout << SUB(a, b + c) * c << std::endl;    // Ожидается -2

    return 0;
}
