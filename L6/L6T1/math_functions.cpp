
#include <iostream>
#include <cmath>

using namespace std;

double add(double a, double b) 
{
    return a + b;
}

double subtract(double a, double b) 
{
    return a - b;
}

double multiply(double a, double b) 
{
    return a * b;
}

double divide(double a, double b) 
{
    if (b == 0) {
        cerr << "������: ������� �� ����!" << endl;
        return 0;
    }
    return a / b;
}

double power(double a, double b) 
{
    return pow(a, b);
}
