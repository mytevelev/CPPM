/*
Вам нужно реализовать класс для работы с большими числами, которые не помещаются в стандартные типы данных.

Для этого класса нужно определить методы:

конструктор перемещения;
перемещающий оператор присваивания;
оператор сложения двух больших чисел;
оператор умножения на число.
Для реализации этого класса можно воспользоваться std::string или std::vector.

Пример правильной работы программы
auto number1 = big_integer("114575");
auto number2 = big_integer("78524");
auto result = number1 + number2;
std::cout << result; // 193099

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class big_integer
{
private:
    string save;
    string value;

    // Helper function to add two string numbers
    string add_strings(const string& num1, const string& num2) const
    {
        string result;
        int carry = 0;

        int i = num1.size() - 1;
        int j = num2.size() - 1;

        // Loop through each digit from the end
        while (i >= 0 || j >= 0 || carry)
        {
            int digit1 = i >= 0 ? num1[i--] - '0' : 0;
            int digit2 = j >= 0 ? num2[j--] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());  /// reorder
        return result;
    }


public:
    /*

    swap(number1,number2)

    */
    big_integer(big_integer&& num) noexcept
    {
        this->save = std::move(num.save);
    };

    big_integer operator+(const big_integer& num)
    {//------------------ suum

        std::string result = add_strings(this->save, num.save);
        return big_integer(result);

    };
    string str() const { return save; };

    big_integer(std::string str)
    {
        save = str;

    }
    // big_integer number2 = move(number1);
    big_integer operator=(big_integer&& num) noexcept
    {
        this->save = std::move(num.save);
        return *this;
    };

    big_integer(const big_integer& num)
    {
        this->save = num.save;
    }

};


int main()
{
    big_integer number1 = big_integer("114575");
    big_integer number2 = big_integer("78524");
    big_integer result = number1 + number2;

    std::cout << result.str(); // 193099



}