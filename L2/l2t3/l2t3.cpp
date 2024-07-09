#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Address {
private:
    string city;
    string street;
    int houseNumber;
    int apartmentNumber;

public:
    // Конструктор по умолчанию
    Address() : city(""), street(""), houseNumber(0), apartmentNumber(0) {}

    // Конструктор с параметрами
    Address(string city, string street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    // Методы для установки значений
    void setCity(string city) {
        this->city = city;
    }

    void setStreet(string street) {
        this->street = street;
    }

    void setHouseNumber(int houseNumber) {
        this->houseNumber = houseNumber;
    }

    void setApartmentNumber(int apartmentNumber) {
        this->apartmentNumber = apartmentNumber;
    }

    // Методы для получения значений
    string getCity() const {
        return city;
    }

    string getStreet() const {
        return street;
    }

    int getHouseNumber() const {
        return houseNumber;
    }

    int getApartmentNumber() const {
        return apartmentNumber;
    }

    // Метод для вывода полного адреса
    void printAddress() const {
        cout << "Город: " << city << ", Улица: " << street
            << ", Дом: " << houseNumber << ", Квартира: " << apartmentNumber << endl;
    }
};

// Функция для сравнения адресов по городу
bool compareByCity(const Address& a, const Address& b) {
    return a.getCity() < b.getCity();
}

// Функция для сортировки адресов по городу
void sortAddressesByCity(Address* addresses, int numberOfAddresses) {
    sort(addresses, addresses + numberOfAddresses, compareByCity);  // можно взять их метод
}
int main( int argc, char *argv[] )
{
    int numberOfAddresses;
    Address* addresses;
    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);


    if (argc < 2 ) // есть ли файл в коммандной строке
    {
        cerr << "Нет аргументов." << endl;
        return 1;
    }

    ifstream inputFile( argv[1] ); // из коммандной строки возьмем

    if (inputFile.is_open()) {
        
        inputFile >> numberOfAddresses;
        inputFile.ignore(); // Игнорируем оставшийся символ новой строки после числа

        addresses = new Address[numberOfAddresses]; /// array of classes

        for (int i = 0; i < numberOfAddresses; ++i) 
        {
            string city, street;
            int houseNumber, apartmentNumber;

            getline(inputFile, city);
            getline(inputFile, street);
            inputFile >> houseNumber;
            inputFile >> apartmentNumber;
            inputFile.ignore(); // Игнорируем оставшийся символ новой строки после номера квартиры

            addresses[i].setCity(city);
            addresses[i].setStreet(street);
            addresses[i].setHouseNumber(houseNumber);
            addresses[i].setApartmentNumber(apartmentNumber);
        }

        inputFile.close();

        for (int i = 0; i < numberOfAddresses; ++i) {
            addresses[i].printAddress();
        }

        
    }
    else 
    {
        cerr << "Не удалось открыть файл" << endl;
        return 1;
    }
    //-------------------- пишем файл в новом формате ---------
    if(  argc >= 3 ) // если нужно сортить
        sortAddressesByCity(addresses, numberOfAddresses); // сортим

    ofstream outputFile("out.txt");
    if (outputFile.is_open() )
    {
		outputFile << numberOfAddresses << endl;

        for (int i = 0; i < numberOfAddresses; ++i)
        {

            outputFile << addresses[i].getCity() << ",";
            outputFile << addresses[i].getStreet() << ",";
            outputFile << addresses[i].getHouseNumber() << "," << addresses[i].getApartmentNumber() << endl;
        };
    };

    delete[] addresses; // очистим
    return 0;

}