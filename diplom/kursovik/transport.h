#pragma once

#include <string>
#ifdef TRANSP_EXPORTS  //Макрос экспорта
#define TRANSP_API __declspec(dllexport)
#else 
#define TRANSP_API __declspec(dllimport)
#endif

enum class TransType
{
    Ground, Air

};

class Transport {
protected:
    bool type;  // false для наземного транспорта, true для воздушного транспорта
    std::string name; // Имя транспортного средства

public:
    virtual double TRANSP_API calculateTotalTime(double distance) const = 0;
    std::string TRANSP_API getName() const
    {
        return name;
    }
    bool TRANSP_API getType() const
    {
        return type;
    }
    virtual ~Transport() = default;
};