#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>

using namespace std;

// Определение структуры для хранения информации об адресе
struct Address 
{
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;
    int postalCode;
};

// Функция для вывода информации об адресе на консоль
void printAddress( const Address& address ) 
{
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;
    std::cout << "Номер дома: " << address.houseNumber << std::endl;
    std::cout << "Номер квартиры: " << address.apartmentNumber << std::endl;
    std::cout << "Индекс: " << address.postalCode << std::endl;
}

int main( void ) 
{

    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);

    // Создание и инициализация экземпляров структуры Address
    Address address1 = { "Москва", "Арбат", 12, 8, 123456 };
    Address address2 = { "Ижевск", "Пушкина", 59, 143, 953769 };

    // Вывод информации об адресах на консоль
    printAddress(address1);
    std::cout << std::endl;
    printAddress(address2);

    return 0;
}
