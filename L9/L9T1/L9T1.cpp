#include <iostream>
#include <windows.h>

using namespace std;

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    //---------------- reloading ------------------------
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
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

    return 0;
}
