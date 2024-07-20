#include "fig.h"
using namespace std; //---------------- 

// Публичный конструктор без параметров
Figure::Figure() : sides_count(0), name("Фигура") {};
// Защищённый конструктор с параметром
Figure::Figure(int sides_count, string name) : sides_count(sides_count), name(name)
{
    if (sides_count == 4) { angleA = 90, angleB = 90, angleC = 90, angleD = 90; }
}


// Публичный метод для получения количества сторон
int Figure::get_sides_count() const 
{
    return sides_count;
}

// Публичный метод для получения имени фигуры
string Figure::get_name() const 
{
    return name;
}
// getters ----------------------------------------
int Figure::get_sA() const
{
    return sideA;
}
int Figure::get_sB() const
{
    return sideB;
}
int Figure::get_sC() const
{
    return sideC;
}
int Figure::get_sD() const
{
    return sideD;
}
int Figure::get_aA() const
{
    return angleA;
}
int Figure::get_aB() const
{
    return angleB;
}
int Figure::get_aC() const
{
    return angleC;
}
int Figure::get_aD() const
{
    return angleD;
}

 void Figure::printinfo()
{
    cout << get_name() << ": " << get_sides_count() << endl;
}

 bool Figure::check()
{

    return false;
}

 //----------------------------------------------------------------

