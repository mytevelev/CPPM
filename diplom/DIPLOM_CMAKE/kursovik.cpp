// kursovik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <windows.h>
#include <algorithm>

using namespace std;
#include <iostream>
#include <cmath>

#include <string>
#include "racers.h"
using namespace std;

struct Result /// для вывода на экран
{
    string name;  // кто
    double time;    // время
    int inRace ;    // участник гонки
};

void bubbleSort(Result* results, int size)      // сортируем структуры
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (results[j].time > results[j + 1].time) {
                // Swap results[j] and results[j + 1]
                Result temp = results[j];
                results[j] = results[j + 1];
                results[j + 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создаем массив указателей на базовый класс Transport, содержащий различные ТС
    Transport* transports[] = 
    {
        new Camel(),
        new SpeedCamel(),
        new Centaur(),
        new AllTerrainBoots(),
        new MagicCarpet(),
        new Eagle(),
        new Broom()
    };


    cout << "Добро пожаловать в гоночный симулятор!\n"
        << "1. гонка для наземного транспорта \n"
        << "2. гонка для воздушного транспорта\n"
        << "3. гонка для наземного и воздушного транспорта\n"
        << "0. выход\n"
        << "Выберите тип гонки : ";
        int raceType = 0;
        cin >> raceType;
        if (!raceType) { cout << "Пока!\n"; return 0; };

    const int numTransports = sizeof(transports) / sizeof(transports[0]);
    Result results[numTransports]; /// количество структур для вывода
    double distance;
    do 
    {
        cout << "Укажите длину дистанции (должна быть положительная): ";
        cin >> distance;
        if (distance > 0) break; 
        else cout << "Неверная длина!\n";
    } while (1);

    //------------------------------------------------------------------------------------
    for (int i = 0; i < numTransports; ++i) 
    {   //           считаем время всем ВСЕГДА!!!!
        double time = transports[i]->calculateTotalTime(distance);
        string typeString = "   ";
        //transports[i]->getType() ? "Воздушный" : "Наземный";
        results[i].name = typeString + " " + transports[i]->getName();
        results[i].time = time;
        results[i].inRace = 0; // not in race by default
    }


    cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства\n" 
         << "1. зарегистрировать транспорт\n" 
         << "0. выйти из программы\n" 
        << "Выберите действия : ";
    int reg = 0;
    cin >> reg;
    if ( !reg ) { cout << "Пока!\n"; return 0; };

    string RaceBound[] = {""," в гонке"};
    int racer = 0;
    do {

        int i = 0;
        if (raceType == 1)
        { // земля
            cout << "Гонка для наземного транспорта." << "Расстояние: " << distance << endl;
            for (i = 0; i < numTransports; ++i)
            {
                if (!transports[i]->getType())
                    cout << i + 1 << ". " << results[i].name << RaceBound[results[i].inRace] << endl;
            }
        }
        else if (raceType == 2) // воздух
        {
            cout << "Гонка для воздушного транспорта." << "Расстояние: " << distance << endl;
            for (i = 0; i < numTransports; ++i)
            {

                if (transports[i]->getType())
                    cout << i + 1 << ". " << results[i].name << RaceBound[results[i].inRace] << endl;
            }
        }
        else
        {// все
            cout << "Гонка транспорта." << "Расстояние: " << distance << endl;
            for (i = 0; i < numTransports; ++i)
                cout << i + 1 << ". " << results[i].name << RaceBound[results[i].inRace] << endl;
        };
        
        cout << "Выберите номер ТС или 0 для начала гонки: ";
        cin >> racer; 
        if (!racer) /// ГОНКА!!
        {
            cout << "-----------Гонка!---------\n "; break;
        };
        results[racer-1].inRace = 1;

    } while (1);

    // Сортировка результатов по времени
    bubbleSort(results, numTransports);
        // Вывод результатов
    for (int i = 0; i < numTransports; ++i) 
    {
                if(results[i].inRace)
        cout << results[i].name << " пройдёт дистанцию " << distance << " км за " << results[i].time << " ч." << endl;
    }




    // Освобождаем память
    for (int i = 0; i < numTransports; ++i) 
    {
        delete transports[i];
    }

    return 0;
}
