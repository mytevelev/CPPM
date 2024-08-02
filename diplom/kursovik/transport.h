#pragma once
#include <string>

class Transport {
protected:
    bool type;  // false для наземного транспорта, true для воздушного транспорта
    std::string name; // Имя транспортного средства

public:
    virtual double calculateTotalTime(double distance) const = 0;
    virtual std::string getName() const {
        return name;
    }
    virtual bool getType() const {
        return type;
    }
    virtual ~Transport() = default;
};