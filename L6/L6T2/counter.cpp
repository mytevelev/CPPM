#include "counter.h"

Counter::Counter() { count = 0; }; // без параметров 0

// Конструктор с инициализирующим значением
Counter::Counter(int initial) { count = initial; };  // с вводом конструктор

void Counter::increment()
{
    count++;
}

// Метод для уменьшения значения на 1
void Counter::decrement()
{
    count--;
}

// Метод для получения текущего значения
int Counter::get_value()
{
    return count;
}