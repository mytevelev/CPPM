#include <iostream>
#include <string>
#include <Windows.h>

// Определение структуры для хранения информации о банковском счёте
struct BankAccount 
{
    int accountNumber  ;  //номер
	std::string ownerName  ; // клиент
	double balance; ////сумма
};

// Функция для изменения баланса счёта
void updateBalance( BankAccount& account, double newBalance) 
{
    account.balance = newBalance;  // новая сумма
}

int main() 
{
    BankAccount account = { 987654321 ,"Иван Петров" ,100.11 };

    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);

    std::cout << "Было: ";
    std::cout << "Ваш счёт: " << account.ownerName << ", " << account.accountNumber << ", " << account.balance << std::endl;



    // Запрос информации о счёте у пользователя
    std::cout << "Введите номер счёта: ";
    std::cin >> account.accountNumber;
    std::cin.ignore(); // Чтобы игнорировать символ новой строки после ввода числа

    std::cout << "Введите имя владельца: ";
   // std::getline(std::cin, account.ownerName);
    std::cin >> account.ownerName;

    std::cout << "Текущий баланс: " ;
    std::cout << account.balance << std::endl;

    double newBalance =0;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;

    // Обновление баланса счёта
    updateBalance(account, newBalance);

    // Вывод обновлённой информации о счёте
    std::cout << "Ваш счёт: " << account.ownerName << ", " << account.accountNumber << ", " << account.balance << std::endl;

    return 0;
}
