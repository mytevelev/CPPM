#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
#include <fstream>
#include <string>
#include <algorithm>

#include "fig.h"
using namespace std; //---------------- 
#define PRN 0


class Triangle : public Figure { //----------- TRAINGLE
protected:

public:
    //  конструктор с параметрами
    Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC)
        : Figure(3, "Треугольник")
    {

        this->sideA = sideA; this->sideB = sideB; this->sideC = sideC;
        this->angleA = angleA; this->angleC = angleC; this->angleB = angleB;
        if (sideA <= 0 || sideB <= 0 || sideC <= 0)
        {
            cerr << "Неверно задвны стороны треугольника " << endl;

        }
        if ((angleA <= 0 || angleB <= 0 || angleC <= 0) || (angleA + angleB + angleC) != 180)
        {
            cerr << "Неверно заданы углы треугольника " << endl;

        }

    };

    // Конструктор по умолчанию
    Triangle() : Figure(3, "Треугольник") {}

    void printinfo() override
    {
        string err[] = { "OK","BAD" };

        cout << err[check()] << endl;
        cout << get_name() << ": " << get_sides_count()
            << " side A: " << get_sA() << " side B: " << get_sB() << " side C: " << get_sC()
            << " angle A: " << get_aA() << " angle B: " << get_aB() << " angle C: " << get_aC()
            << endl;

    }

    bool check() override  ///// checking angles
    {
        if (get_aA() + get_aB() + get_aC() != 180) return true;

        return false;
    };

};

class rightTriangle : public Triangle
{
private:

public:
    //  конструктор с параметрами

    rightTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : /// тут вызвается конструктор родителя с параметрами
        Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
    {
        if (angleC != 90)
            cerr << "Неверно задан угол С треугольника. C = 90 now." << endl;

        name = "Прямоугольный треугольник";
    }; /// вот тут объект создан

    rightTriangle() : Triangle(1, 1, 1, 45, 45, 90) { name = "Прямоугольный треугольник"; };

    bool check() override  ///// checking angles
    {

        if (get_aC() != 90 || Triangle::check()) return true;

        return false;
    };

};


class eqTriangle : public Triangle
{
private:

public:
    //  конструктор с параметрами

    eqTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : /// тут вызвается конструктор родителя с параметрами
        Triangle(sideA, sideB, sideC, angleA, angleB, angleC)
    {
        if (!((sideA == sideB) && (sideC == sideB)))
            cerr << "Неверно заданы стороны треугольника. " << endl;
        name = "Равносторонний треугольник";
    }; /// вот тут объект создан

    eqTriangle() : Triangle(1, 1, 1, 60, 60, 60) { name = "Равносторонний треугольник"; };
    bool check() override  ///// checking angles
    {
        if (Triangle::check()) return true;
        if (!(get_aA() == 60 && get_aB() == 60 && get_aC() == 60)
            &&
            ((get_sA() == get_sB() && get_sA() == get_sC()))) return true;


        return false;
    };

};


class Quadrangle : public Figure //------------------------------ Quadrangle
{
public:

    //  конструктор с параметрами
    Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD)
        : Figure(4, "Четырёхугольник")
    {

        this->sideA = sideA; this->sideB = sideB; this->sideC = sideC; this->sideD = sideD;
        this->angleA = angleA;  this->angleB = angleB; this->angleC = angleC; this->angleD = angleD;
        if (sideA <= 0 || sideB <= 0 || sideC <= 0 || sideD <= 0)
        {
            cerr << "Неверно задвны стороны треугольника " << endl;

        }
        if ((angleA <= 0 || angleB <= 0 || angleC <= 0 || angleD <= 0) || (angleA + angleB + angleC + angleD) != 360)
        {
            cerr << "Неверно заданы углы треугольника " << endl;

        }

    };

    // Конструктор по умолчанию
    Quadrangle() : Figure(4, "Четырёхугольник") {}

    void printinfo() override
    {
        string err[] = { "OK","BAD" };

        cout << err[check()] << endl;
        cout << get_name() << ": " << get_sides_count()
            << " side A: " << get_sA() << " side B: " << get_sB() << " side C: " << get_sC() << " side D: " << get_sD()
            << " angle A: " << get_aA() << " angle B: " << get_aB() << " angle C: " << get_aC() << " angle D: " << get_aD()
            << endl;

    }

    bool check() override  ///// checking angles
    {
        int angles = get_aA() + get_aB() + get_aC() + get_aD();
        if (angles != 360) return true;

        return false;
    };




};

class Rhombus : public Quadrangle
{
public:

    Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : /// тут вызвается конструктор родителя с параметрами
        Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
    {
        if (!((sideA == sideB) && (sideC == sideB)))
            cerr << "Неверно заданы стороны ромба. " << endl;
        name = "Ромб";
    }; /// вот тут объект создан

    Rhombus() : Quadrangle(1, 1, 1, 1, 80, 100, 80, 100) { name = "Ромб"; }; // простой конструктор
    bool check() override  ///// checking angles
    {
        if (Quadrangle::check()) return true;
        if ((get_aA() != get_aC()) || (get_aB() != get_aD())) return true;

        return false;
    };

};


////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);
    Figure baseFigure;
    Triangle triangle(10, 11, 12, 60, 60, 60);
    Quadrangle quadrangle;
    Rhombus rb(77, 77, 77, 77, 60, 120, 60, 120);

    rightTriangle rt(30, 31, 32, 45, 45, 90);

    eqTriangle et(300, 300, 300, 60, 60, 60);


    baseFigure.printinfo();
    rt.printinfo();
    et.printinfo();
    rb.printinfo();

#if PRN 
    //-------------------------------------------------------
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

#endif


}
