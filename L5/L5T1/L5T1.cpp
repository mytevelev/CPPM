#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Figure {
protected:
    int sides_count;
    string name;

    // Защищённый конструктор с параметром
    Figure(int sides_count, string name) : sides_count(sides_count), name(name) {}

public:
    // Публичный конструктор без параметров
    Figure() : sides_count(0), name("Фигура") {}

    // Публичный метод для получения количества сторон
    int get_sides_count() const {
        return sides_count;
    }

    // Публичный метод для получения имени фигуры
    string get_name() const {
        return name;
    }
};

class Triangle : public Figure {
public:
    // Конструктор по умолчанию
    Triangle() : Figure(3, "Треугольник") {}
};

class Quadrangle : public Figure {
public:
    // Конструктор по умолчанию
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};


int main()
{
    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);
    Figure baseFigure;
    Triangle triangle;
    Quadrangle quadrangle;

    cout << "Количество сторон:" << endl;
    cout << baseFigure.get_name() << ": " << baseFigure.get_sides_count() << endl;
    cout << triangle.get_name() << ": " << triangle.get_sides_count() << endl;
    cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << endl;




}
