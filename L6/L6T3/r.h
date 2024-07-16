#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include <locale.h>
#include <fstream>

#include "fig.h"
#include "q.h"
using namespace std; //---------------- 

class Rhombus : public Quadrangle
{
public:
	Rhombus(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD);
	Rhombus();
	bool check() override;
};