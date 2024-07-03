#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>


using namespace std;

class Counter 
{
private:
    int count;      // недоступно всем

public:
    // Конструктор по умолчанию
    Counter() { count = 0; }; // без параметров 0

    // Конструктор с инициализирующим значением
    Counter(int initial) { count = initial; };  // с вводом конструктор

    // Метод для увеличения значения на 1
    void increment() 
    {
        count++;
    }

    // Метод для уменьшения значения на 1
    void decrement() 
    {
        count--;
    }

    // Метод для получения текущего значения
    int get_value()  
    {
        return count;
    }
};

int main( void ) 
{
    Counter counter;  // объект
    string userInput;
    int initialValue;

    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);

    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> userInput;

    if (userInput == "да") 
    {
        cout << "Введите начальное значение счётчика: ";
        cin >> initialValue;
        counter = Counter( initialValue );
    }

  //  cout << counter.get_value() << endl;

    while (true) 
    {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> userInput;

        if (userInput == "+") {
            counter.increment();
        }
        else if (userInput == "-") 
        {
            counter.decrement();
        }
        else if (userInput == "=") 
        {
            cout << counter.get_value() << endl;
        }
        else if (userInput == "x") 
        {
            cout << "До свидания!" << endl;
            break;
        }
        else 
        {
            cout << "Неверная команда!" << endl;
        }
    }

    return 0;
}
