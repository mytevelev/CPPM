/*
[Section1]
; комментарий о разделе
var1=11.0 ; иногда допускается комментарий к отдельному параметру
var2=какая-то строка

[Section2]
var1=21
var2=значение_2

; Иногда значения отсутствуют, это означает, что в Section3 нет переменных
[Section3]
[Section4]
Mode=
Vid=true

; Секции могут повторяться
[Section1]
var3=значение
var1=111.0 ; переприсваиваем значение
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <Windows.h>
#include <iomanip> // For std::fixed and std::setprecision

using namespace std;

class ini_parser 
{
public:
    // Конструктор принимает имя файла и сразу загружает его содержимое
    ini_parser(const  string& filename)
    {
         ifstream file(filename);
        if (!file.is_open())
        {
            throw  runtime_error("Failed to open INI file: " + filename);
        }
        parse(file);
    }

    // Шаблонная функция для получения значения из секции
    template <typename T>
    T get_value(const  string& key) const 
    {
        auto pos = key.find('.'); 
        if (pos ==  string::npos) 
        {
            pos = key.find(',');
            if (pos == string::npos)
                 throw  invalid_argument("Invalid key format. Use 'section.value'.");
        }

         string section = key.substr(0, pos);
         string name = key.substr(pos + 1);

        auto section_it = data.find(section);
        if (section_it == data.end()) 
        {
            throw  runtime_error("Section '" + section + "' not found.");
        }

        auto value_it = section_it->second.find(name);
        if (value_it == section_it->second.end()) 
        {
            throw  runtime_error("Key '" + name + "' not found in section '" + section + "'.");
        }

        return convert<T>(value_it->second);
    }

private:
    // Структура данных для хранения значений INI-файла
     unordered_map< string,  unordered_map< string,  string>> data;  // секции с данными

    // Функция для парсинга содержимого INI-файла
    void parse( ifstream& file) 
    {
         string line;
         string current_section;

        while ( getline(file, line)) 
        {
            // Удаление пробелов с начала и конца строки
            trim(line);
           // cout << line << endl;
            // Игнорируем пустые строки и комментарии
            if (line.empty() || line[0] == ';' || line[0] == '#') 
            {
                continue;
            }

            // Если строка представляет собой секцию
            if (line.front() == '[' && line.back() == ']') 
            {
                current_section = line.substr(1, line.size() - 2);
                trim(current_section);
            }
            else 
            {
                // Парсим ключ-значение в текущей секции
                auto delimiter_pos = line.find('=');
                if (delimiter_pos ==  string::npos) 
                {
                    throw  runtime_error("Invalid line in INI file: " + line);
                }

                 string key = line.substr(0, delimiter_pos);
                 string value = line.substr(delimiter_pos + 1);

                trim(key);
                trim(value);

                if (current_section.empty()) 
                {
                    throw  runtime_error("Key-value pair outside of any section: " + line);
                }

                data[current_section][key] = value;
            }
        }
//---------------------------------------------------------------------------------------------------
        cout << "--------------Parsed INI---------------------" << endl;
            // Iterate over each section in the outer map
        for (const auto& section_pair : data) 
        {
            const std::string& section = section_pair.first;
            const auto& inner_map = section_pair.second;

            std::cout << "[" << section << "]" << std::endl;

            // Iterate over each key-value pair in the inner map
            for (const auto& key_value_pair : inner_map) {
                const std::string& key = key_value_pair.first;
                const std::string& value = key_value_pair.second;

                std::cout << key << " = " << value << std::endl;
            }

            std::cout << std::endl; // Print a blank line between sections for readability
        }
        cout << "-----------------------------------" << endl;
//--------------------------------------------------------------------------------------------------
    }

    // Функция для удаления пробелов с начала и конца строки
    static void trim( string& str) {
        size_t first = str.find_first_not_of(" \t");
        size_t last = str.find_last_not_of(" \t");
        if (first ==  string::npos || last ==  string::npos) 
        {
            str.clear();
        }
        else 
        {
            str = str.substr(first, last - first + 1);
        }
    }

    // Шаблонная функция для конвертации строки в нужный тип
    template <typename T>
    T convert(const  string& value) const;

    // Специализации для разных типов
    template <>
    int convert<int>(const  string& value) const 
    {
        return  stoi(value);
    }

    template <>
    double convert<double>(const  string& value) const 
    {
        return  stod(value);
    }

    template <>
     string convert< string>(const  string& value) const 
    {
        return value;
    }

    template <>
    bool convert<bool>(const string& value) const 
    {
        if (value == "true" || value == "1") 
        {
            return true;
        }
        else if (value == "false" || value == "0") 
        {
            return false;
        }
        throw invalid_argument("Invalid boolean value: " + value);
    }
};

int main() 
{

    // Установка кодировки консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    try 
    {
        ini_parser parser("s.ini");
        int int_value = parser.get_value<int>("Section2.var1");
        double double_value = parser.get_value<double>("Section1.var1");
        string string_value = parser.get_value<string>("Section1.var2");
        bool bool_value = parser.get_value<bool>("Section4.Vid");

        cout << "Int value: " << int_value << endl;
        cout << fixed << setprecision(5);
        cout << "Double value: " << double_value << endl;
        cout << "String value: " << string_value << endl;
        cout << "Bool value: " << bool_value << endl;
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
