
#include "Transport.h"

class Camel : public Transport {
public:
    Camel() 
    {
        type = false;
        name = "Верблюд";
    }

    double calculateTotalTime(double distance) const override 
    {
        double speed = 10;  // скорость
        double travelTime = 30;  // до отдыха
        double totalTravelTime = distance / speed; // за сколько пройдет без остановки
        int restCount = static_cast<int>(totalTravelTime / travelTime); // сколько отдыхов
        double restCountFull = (totalTravelTime / travelTime); // сколько отдыхов c остатком

        if ( restCountFull == static_cast<double>(restCount) ) restCount--;
 
        double totalTime = totalTravelTime;     
        for (int i = 1; i <= restCount; ++i) 
        {
            if (i == 1) 
            {
                totalTime += 5;
            }
            else 
            {
                totalTime += 8;
            }
        }
        return totalTime;
    }
};

class SpeedCamel : public Transport {
public:
    SpeedCamel() {
        type = false;
        name = "Верблюд-быстроход";
    }

    double calculateTotalTime(double distance) const override {
        double speed = 40;
        double travelTime = 10;
        double totalTravelTime = distance / speed;
        int restCount = static_cast<int>(totalTravelTime / travelTime);
        double restCountFull = (totalTravelTime / travelTime); // сколько отдыхов c остатком

        if (restCountFull == static_cast<double>(restCount)) restCount--;

        double totalTime = totalTravelTime;
        for (int i = 1; i <= restCount; ++i) {
            if (i == 1) {
                totalTime += 5;
            }
            else if (i == 2) {
                totalTime += 6.5;
            }
            else {
                totalTime += 8;
            }
        }
        return totalTime;
    }
};

class Centaur : public Transport {
public:
    Centaur() {
        type = false;
        name = "Кентавр";
    }

    double calculateTotalTime(double distance) const override {
        double speed = 15;
        double travelTime = 8;
        double totalTravelTime = distance / speed;
        int restCount = static_cast<int>(totalTravelTime / travelTime);

        double restCountFull = (totalTravelTime / travelTime); // сколько отдыхов c остатком

        if (restCountFull == static_cast<double>(restCount)) restCount--;
        double totalTime = totalTravelTime;
        for (int i = 1; i <= restCount; ++i) {
            totalTime += 2;
        }
        return totalTime;
    }
};

class AllTerrainBoots : public Transport {
public:
    AllTerrainBoots() {
        type = false;
        name = "Ботинки-вездеходы";
    }

    double calculateTotalTime(double distance) const override {
        double speed = 6;
        double travelTime = 60;
        double totalTravelTime = distance / speed;
        int restCount = static_cast<int>(totalTravelTime / travelTime);
        double restCountFull = (totalTravelTime / travelTime); // сколько отдыхов c остатком

        if (restCountFull == static_cast<double>(restCount)) restCount--;
        double totalTime = totalTravelTime;
        for (int i = 1; i <= restCount; ++i) {
            if (i == 1) {
                totalTime += 10;
            }
            else {
                totalTime += 5;
            }
        }
        return totalTime;
    }
};
//-------------------------------------------------- flying objects ----------------
class MagicCarpet : public Transport {
public:
    MagicCarpet() {
        type = true;
        name = "Ковёр-самолёт";
    }

    double calculateTotalTime(double distance) const override {
        double speed = 10;
        double reduction = 0;

        if (distance >= 1000 && distance < 5000) {
            reduction = 3;
        }
        else if (distance >= 5000 && distance < 10000) {
            reduction = 10;
        }
        else if (distance >= 10000) {
            reduction = 5;
        }

        double reducedDistance = distance * (1 - reduction / 100);
        return reducedDistance / speed;
    }
};

class Eagle : public Transport {
public:
    Eagle() {
        type = true;
        name = "Орёл";
    }

    double calculateTotalTime(double distance) const override {
        double speed = 8;
        double reduction = 6; // Всегда 6%
        double reducedDistance = distance * (1 - reduction / 100);
        return reducedDistance / speed;
    }
};

class Broom : public Transport {
public:
    Broom() {
        type = true;
        name = "Метла";
    }

    double calculateTotalTime(double distance) const override {
        double speed = 20;
        int reduction = static_cast<int>(distance / 1000); // Увеличивается на 1% за каждую 1000 у.е. расстояния
        double red = reduction;  // to float
        double reducedDistance = distance * (1 - red / 100);
        return reducedDistance / speed;
    }
};


