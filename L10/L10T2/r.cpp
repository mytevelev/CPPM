#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
#include <fstream>
#include "fig.h"
#include "q.h"
#include "r.h"
using namespace std;

Rhombus::Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : /// тут вызвается конструктор родителя с параметрами
    Quadrangle(sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD)
{
    if (!((sideA == sideB) && (sideC == sideB)))
        cerr << "Неверно заданы стороны ромба. " << endl;
    name = "Ромб";
}; /// вот тут объект создан

Rhombus::Rhombus() : Quadrangle(1, 1, 1, 1, 80, 100, 80, 100) { name = "Ромб"; }; // простой конструктор
bool Rhombus::check()   ///// checking angles
{
    if (Quadrangle::check()) return true;
    if ((get_aA() != get_aC()) || (get_aB() != get_aD())) return true;

    return false;
};