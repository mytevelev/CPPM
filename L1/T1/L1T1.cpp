// L1T1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <string>

enum Months 
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

std::string getMonthName(int month)
{
    switch (month) {
    case January:   return "Январь";
    case February:  return "Февраль";
    case March:     return "Март";
    case April:     return "Апрель";
    case May:       return "Май";
    case June:      return "Июнь";
    case July:      return "Июль";
    case August:    return "Август";
    case September: return "Сентябрь";
    case October:   return "Октябрь";
    case November:  return "Ноябрь";
    case December:  return "Декабрь";
    default:        return "Неправильный номер!";
    };
};
int main( void )
{
    SetConsoleOutputCP(CP_UTF8);

    int month=0;
    do 
    {
        std::cout << "Введите номер месяца: ";
        std::cin >> month;

        if ( !month ) 
        {
            std::cout << "До свидания" << std::endl;
            break;
        }

        std::string monthName = getMonthName( month ); // в строку месяц
        std::cout << monthName << std::endl;    // выводим

    } while ( month );

    return 0;


};
