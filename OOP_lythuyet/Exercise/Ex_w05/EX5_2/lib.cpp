#include "lib.h"

//---IMPLEMENT CLASS CLIENT---
Client::Client(string name, string ClientID) : name(name), clientID(ClientID) {}
void Client::printInfo()
{
    cout << "name: " << name << endl;
    cout << "ClientID: " << clientID << endl;
}

//---IMPLEMENT CLASS ACCOUNT---
Account::Account(Client a, string account_num, double _balance) : client(a), account_number(account_num), balance(_balance) {}
double Account::getBalance()
{
    return balance;
}
void Account::deposit(double amount)
{
    balance += amount;
}
void Account::withdraw(double amount)
{
    if (balance <= 0)
    {
        cout << "Can't draw!!" << endl;
        return;
    }
    balance -= amount;
}
void Account::printInfo()
{
    client.printInfo();
    cout << "Account number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
}

//---IMPLEMENT CLASS SAVINGACCOUNT---
SavingAccount::SavingAccount(Client a, string account_num, double _balance, double rate) : Account(a, account_num, _balance), interest_rate(rate) {}
void SavingAccount::applyInterestRate()
{
    balance += balance * interest_rate;
}
void SavingAccount::display()
{
    printInfo();
    cout << "Interest Rate: " << interest_rate * 100 << "%" << endl;
}