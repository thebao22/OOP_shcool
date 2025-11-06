#pragma once
#include <iostream>
#include <string>
using namespace std;

class Client
{
private:
    string name, clientID;

public:
    Client() = default;
    Client(string name, string ClientID);
    void printInfo();
};
class Account
{
protected:
    Client client;
    string account_number;
    double balance;

public:
    Account() = default;
    Account(Client a, string account_num, double _balance);
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);
    void printInfo();
};
class SavingAccount : public Account
{
private:
    double interest_rate;

public:
    SavingAccount() = default;
    SavingAccount(Client a, string account_num, double _balnce, double rate);
    void applyInterestRate();
    void display();
};