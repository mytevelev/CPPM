#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std; //---------------- 

class Figure {
protected:
    int sides_count;
    string name;
    int sideA = 100, sideB = 200, sideC = 300,sideD =400,
        angleA = 60, angleB = 60, angleC = 60,angleD = 60;

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
    // getters ----------------------------------------
    int get_sA() const
    {
        return sideA;
    }
    int get_sB() const
    {
        return sideB;
    }
    int get_sC() const
    {
        return sideC;
    }
    int get_sD() const
    {
        return sideD;
    }
    int get_aA() const
    {
        return angleA;
    }
    int get_aB() const
    {
        return angleB;
    }
    int get_aC() const
    {
        return angleC;
    }
    int get_aD() const
    {
        return angleD;
    }

};

class Triangle : public Figure { //----------- TRAINGLE
protected:

public:
    //  конструктор с параметрами
    Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC )
        : Figure(3, "Треугольник")
    {
       
		this->sideA = sideA; this->sideB = sideB; this->sideC = sideC;
        this->angleA = angleA; this->angleC = angleC; this->angleB = angleB;
        if (sideA<=0 || sideB <= 0 || sideC <= 0 )
        {
            cerr << "Неверно задвны стороны треугольника " << endl;
            
        }
        if ( (angleA <= 0 || angleB <= 0 || angleC <= 0) || (angleA+ angleB+ angleC) != 180 )
        {
            cerr << "Неверно заданы углы треугольника " << endl;

        }

    };

    // Конструктор по умолчанию
    Triangle() : Figure(3, "Треугольник") {}

};

class rightTriangle : public Triangle
{
private:

public:
    //  конструктор с параметрами

    rightTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC ) : /// тут вызвается конструктор родителя с параметрами
    Triangle(sideA, sideB, sideC, angleA, angleB, 90 ) 
    {
        if (angleC != 90)
            cerr << "Неверно задан угол С треугольника. C = 90 now." << endl;

    }; /// вот тут объект создан

    rightTriangle() : Triangle(1, 1, 1, 45, 45, 90) {};


};


class eqTriangle : public Triangle
{
private:

public:
    //  конструктор с параметрами

    eqTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : /// тут вызвается конструктор родителя с параметрами
        Triangle(sideA, sideB, sideC, 60, 60, 60)
    {
        if ( !((sideA == sideB) && (sideC == sideB )) )
            cerr << "Неверно заданы стороны треугольника. " << endl;

    }; /// вот тут объект создан

    eqTriangle() : Triangle(1, 1, 1, 60, 60, 60) {};


};


class Quadrangle : public Figure { //------------------------------ Quadrangle
public:
    // Конструктор по умолчанию
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

void print_info( Figure *f )  //---------------------------------------------------------
{
    switch (f->get_sides_count())
    {
    case 3:
        cout << "Треугольник" << endl;
        cout << f->get_name() << ": " << f->get_sides_count()
            << " side A: " << f->get_sA() << " side B: " << f->get_sB() << " side C: " << f->get_sC()
            << " angle A: " << f->get_aA() << " angle B: " << f->get_aB() << " angle C: " << f->get_aC()
            << endl;

        break;
    case 4:
        cout << "Четырёхугольник" << endl;
        cout << f->get_name() << ": " << f->get_sides_count()
            << " side A: " << f->get_sA() << " side B: " << f->get_sB() << " side C: " << f->get_sC() << " side d: " << f->get_sD()
            << " angle A: " << f->get_aA() << " angle B: " << f->get_aB() << " angle C: " << f->get_aC() << " angle D: " << f->get_aD()
            << endl;

        break;

    };


}////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);
    Figure baseFigure;
    Triangle triangle( 10,11,12,60,60,60);
    Quadrangle quadrangle;

    rightTriangle rt(30, 31, 32, 45, 45, 90);

    eqTriangle et(300, 300, 300, 60, 60, 60);

    print_info(&et);
    print_info(&quadrangle);

    cout << "Количество сторон:" << endl;
    cout << baseFigure.get_name() << ": " << baseFigure.get_sides_count() << endl;
    cout << triangle.get_name() << ": " << triangle.get_sides_count()
        << " side A: " << triangle.get_sA() << " side B: " << triangle.get_sB() << " side C: " << triangle.get_sC()
        << " angle A: " << triangle.get_aA() << " angle B: " << triangle.get_aB() << " angle C: " << triangle.get_aC()
        << endl;
    ///----------прямоугольный треугольник
    cout << rt.get_name() << ": " << rt.get_sides_count()
        << " side A: " << rt.get_sA() << " side B: " << rt.get_sB() << " side C: " << rt.get_sC()
        << " angle A: " << rt.get_aA() << " angle B: " << rt.get_aB() << " angle C: " << rt.get_aC()
        << endl;

    ///----------равносторонний треугольник (все стороны равны, все углы равны 60)
    cout << et.get_name() << ": " << et.get_sides_count()
        << " side A: " << et.get_sA() << " side B: " << et.get_sB() << " side C: " << et.get_sC()
        << " angle A: " << et.get_aA() << " angle B: " << et.get_aB() << " angle C: " << et.get_aC()
        << endl;


    cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << endl;




}
