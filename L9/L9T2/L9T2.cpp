#include <iostream>
#include <windows.h>

using namespace std;

class Fraction
{
private:
    int numerator_=1;
    int denominator_=1;
    // Функция для нахождения наибольшего общего делителя (НОД)
    int gcd(int a, int b) const
    {
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // Функция для сокращения дроби
    void reduce()
    {
        int divisor = gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

public:

    Fraction() {};
    Fraction(int numerator, int denominator)
    {
        if (denominator == 0) 
        {
            throw invalid_argument("Ноль в знаменателе!");
        }
        numerator_ = numerator;
        denominator_ = denominator;
        reduce();
    }
    // Метод для вывода дроби на экран
    void Print() const
    {
        cout << numerator_ << "/" << denominator_;
        // вывод дроби
    }
    //---------------- reloading ------------------------
    // определяем равенство и меньше. остальное вытекает из этих двух сравнений
    // в эти два случаю атомарны
    bool Compare(Fraction other) const /// equality
    {
        return numerator_ * other.denominator_ == other.numerator_ * denominator_;
    }

    bool operator==(Fraction other) const
    {
        return Compare(other);
    }

    bool operator!=(Fraction other) const
    {
        return !(*this == other);
    }

    bool operator<(Fraction other) const ///  comparison
    {
        return numerator_ * other.denominator_ < other.numerator_ * denominator_;
    }

    bool operator>(Fraction other) const
    {
        return other < *this;
    }

    bool operator<=(Fraction other) const
    {
        return !(other < *this);
    }

    bool operator>=(Fraction other) const
    {
        return !(*this < other);
    }
    //---------------- бинарные операторы ---------  

    Fraction operator*(Fraction other) const
    {
        //Fraction result(numerator_ * other.numerator_, denominator_ * other.denominator_);
        int nden = numerator_ * other.numerator_; 
        int nnum = denominator_ * other.denominator_;

        Fraction result( nden, nnum );
        return result;

       // return Fraction(nden, nnum);
    }

    Fraction& operator++ ()  /// prefix ++
    {
         numerator_ += denominator_;  //// todo : simplify
         //denominator_ += denominator_;
         return *this;

    }

    Fraction operator++ (int)  /// posfix ++
    {
        Fraction temp = *this;
        numerator_ += denominator_;  //// todo : simplify
        return temp;

    }

    // Перегрузка оператора +
    Fraction operator+(const Fraction& other) const
    {
        int new_numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int new_denominator = denominator_ * other.denominator_;
        Fraction result(new_numerator, new_denominator);
        return result;
    }

    // Define copy assignment operator.
    Fraction& operator=(const Fraction& other) //-------------- оператор =
    {
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;

        return *this;
    }


};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    try {
        int num1, den1, num2, den2;
        Fraction r;

        cout << "Введите числитель дроби 1: ";
        cin >> num1;
        cout << "Введите знаменатель дроби 1: ";
        cin >> den1;

        Fraction f1(num1, den1);

        cout << "Введите числитель дроби 2: ";
        cin >> num2;
        cout << "Введите знаменатель дроби 2: ";
        cin >> den2;

        Fraction f2(num2, den2);
        // Вывод дробей
        cout << "Первая дробь: ";
        f1.Print();
        cout << endl;

        cout << "Вторая дробь: ";
        f2.Print();
        cout << endl;

        //--------------------------------++3/4 * 4/5 = 7/5
        
        r = ++f1 * f2;

        f1.Print();
        cout << endl;

        r.Print();
        cout << endl;
        //-------------------------- присвоение
        r = f1 + f2;
        r.Print();
        cout << endl;
 
    }
    catch (const invalid_argument& e) 
    {
        cerr << "Ошибка: " << e.what() << endl;
    }


    return 0;
}
