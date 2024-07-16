﻿#pragma once
#include <string>
#include <iostream>


#include <windows.h>
#include <locale.h>
#include <fstream>

using namespace std; //---------------- 


class Quadrangle : public Figure //------------------------------ Quadrangle
{
public:
	Quadrangle() : Figure(4, "Четырёхугольник");

	Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD)
		: Figure(4, "Четырёхугольник");
	void printinfo() override;
	bool check() override;

};