#pragma once

#include <string>

enum class TransType
{
    Ground, Air

};

class Transport {
protected:
    bool type;  // false для наземного транспорта, true для воздушного транспорта
    std::string name; // Имя транспортного средства

public:
    virtual double calculateTotalTime(double distance) const = 0;
    std::string getName() const
    {
        return name;
    }
    bool getType() const
    {
        return type;
    }
    virtual ~Transport() = default;
};