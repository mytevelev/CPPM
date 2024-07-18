#include <iostream>
#include <string>
#include <exception>

#include <windows.h>

// Определяем исключение bad_length
class bad_length : public std::exception 
{
public:
    const char* what() const noexcept override 
    {
        return "bad_length";
    }
};

// Функция, проверяющая длину строки
int function(std::string str, int forbidden_length) 
{
    if (str.length() == forbidden_length) 
    {
        throw bad_length();
    }
    return str.length();
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    std::cin.ignore(); // Игнорируем оставшийся символ новой строки после ввода числа

    while (true) {
        std::string word;
        std::cout << "Введите слово: ";
        std::getline(std::cin, word);

        try 
        {
            int length = function(word, forbidden_length);
            std::cout << "Длина слова \"" << word << "\" равна " << length << std::endl;
        }
        catch (const bad_length&) 
        {
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
            break;
        }
    }

    return 0;

}
