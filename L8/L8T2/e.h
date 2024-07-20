#pragma once
#include <string>
#include <iostream>



class BadF : public std::runtime_error
{
private:
    std::string fname;

public:
    
    BadF(std::string fname, std::string text) : std::runtime_error(fname + " " + text) { this->fname = fname; };
    std::string get_fname() const
    {
        return this->fname;
    }
};

