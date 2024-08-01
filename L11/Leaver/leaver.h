#pragma once

#include <string>
#ifdef LEAVER_EXPORTS  //Макрос экспорта
#define LEAVER_API __declspec(dllexport)
#else 
#define LEAVER_API __declspec(dllimport)
#endif

class Leaver 
{
public:
    
     std::string LEAVER_API leave(const std::string& name);

};


