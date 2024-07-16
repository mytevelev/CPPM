#pragma once
#include <string>
#include <iostream>


class Figure {
protected:
    int sides_count;
    string name;
    int sideA = 100, sideB = 200, sideC = 300, sideD = 400,
        angleA = 60, angleB = 60, angleC = 60, angleD = 60;

    // Защищённый конструктор с параметром
    Figure(int sides_count, string name);
public:
    // Публичный конструктор без параметров
    Figure();

    // Публичный метод для получения количества сторон
    int get_sides_count() const;
     // Публичный метод для получения имени фигуры
    string get_name() const;
    // getters ----------------------------------------
    int get_sA() const;
    int get_sB() const;
    int get_sC() const;
    int get_sD() const;
    int get_aA() const;
    int get_aB() const;
    int get_aC() const;
    int get_aD() const;

    virtual void printinfo();

    virtual bool check();

};