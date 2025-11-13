#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
class MainAccount
{
private:
    string AccountID;
    double balance;
    const double minBalance = 0;

public:
    MainAccount(string AccountID, double balance);
    bool with_draw(double amount);
    void deposit(double amount);
    double getBalance() const;
    string getAccountID() const;
};

class SubAccount
{
private:
    string AccountID;
    MainAccount *tklk;
    double Count_Balance;
    const double max_draw = 2000000;

public:
    SubAccount(string AccountID, MainAccount *main);
    bool with_draw(double amount);
    void deposit(double amount);
    double getBalance() const;
    string getAccountID() const;
    void resetCountBalance();
};

class Client
{
private:
    string name_Cli;
    vector<MainAccount *> list_main_account;
    vector<SubAccount *> list_sub_account;
    static const int Quantity_max_per_type = 5;

public:
    Client(string name);
    ~Client();
    bool InsertMainAcc(MainAccount *Acc);
    bool InsertSubAcc(SubAccount *Acc);
    MainAccount *getMainAccount(string AccountID);
    SubAccount *getSubAccount(string AccountID);
    string getName() const;
};

class Bank
{
private:
    string name_Bank;
    vector<Client *> list_Client;

public:
    Bank(string name);
    ~Bank();
    void InsertClient(Client *cli);
    Client *getClient(string name);
};