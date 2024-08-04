#pragma once
#include "Transport.h"

class Camel : public Transport {
public:
    Camel() 
    {
        type = false;
        name = "Верблюд";
    }

    double calculateTotalTime(double distance) const override;
};

class SpeedCamel : public Transport {
public:
    SpeedCamel() {
        type = false;
        name = "Верблюд-быстроход";
    }

    double calculateTotalTime(double distance) const override;
};

class Centaur : public Transport {
public:
    Centaur() {
        type = false;
        name = "Кентавр";
    }

    double calculateTotalTime(double distance) const override;
};

class AllTerrainBoots : public Transport {
public:
    AllTerrainBoots() {
        type = false;
        name = "Ботинки-вездеходы";
    }

    double calculateTotalTime(double distance) const override;
};
//-------------------------------------------------- flying objects ----------------
class MagicCarpet : public Transport {
public:
    MagicCarpet() {
        type = true;
        name = "Ковёр-самолёт";
    }

    double calculateTotalTime(double distance) const override;
};

class Eagle : public Transport {
public:
    Eagle() {
        type = true;
        name = "Орёл";
    }

    double calculateTotalTime(double distance) const override;
};

class Broom : public Transport {
public:
    Broom() {
        type = true;
        name = "Метла";
    }

    double calculateTotalTime(double distance) const override;
};


