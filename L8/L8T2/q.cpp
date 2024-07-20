#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
#include <fstream>
#include "fig.h"
#include "q.h"
#include "e.h"
using namespace std;



Quadrangle::Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD)
    : Figure(4, "Четырёхугольник")
{

    this->sideA = sideA; this->sideB = sideB; this->sideC = sideC; this->sideD = sideD;
    this->angleA = angleA;  this->angleB = angleB; this->angleC = angleC; this->angleD = angleD;
    if (sideA <= 0 || sideB <= 0 || sideC <= 0 || sideD <= 0)
    {
        
        throw BadF(this->name, "Неверно заданы стороны прямоугольника ");

    }
    if ((angleA <= 0 || angleB <= 0 || angleC <= 0 || angleD <= 0) || (angleA + angleB + angleC + angleD) != 360)
    {
        
        throw BadF(this->name, "Неверно заданы углы прямоугольника ");

    }

};

// Конструктор по умолчанию
Quadrangle::Quadrangle() : Figure(4, "Четырёхугольник") {};


bool Quadrangle::check()   ///// checking angles
{
    int angles = get_aA() + get_aB() + get_aC() + get_aD();
    if (angles != 360) return true;

    return false;
};
void Quadrangle::printinfo() 
{
    string err[] = { "OK","BAD" };

    cout << err[check()] << endl;
    cout << get_name() << ": " << get_sides_count()
        << " side A: " << get_sA() << " side B: " << get_sB() << " side C: " << get_sC() << " side D: " << get_sD()
        << " angle A: " << get_aA() << " angle B: " << get_aB() << " angle C: " << get_aC() << " angle D: " << get_aD()
        << endl;

}
