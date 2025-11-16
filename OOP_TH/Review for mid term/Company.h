#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#define SZ 120
using namespace std;
class Company;
class Laptop
{
    friend Company;

protected:
    char *name;
    char *brand;
    char *PRD;
    long long price;
    double weightl;
    double battery;

public:
    Laptop();
    Laptop(char *name, char *brand, char *PRD, long long price, double weight, double battery);
    virtual ~Laptop(){};
    virtual void print() = 0;
    bool operator<(const char* date);
}; // virtual

class Company
{
private:
    Laptop **list_lap;
    int *type_state;
    int size;

public:
    void updateList(fstream &file);
    ~Company()
    {
        for (int i = 0; i < size; i++)
        {
            delete list_lap[i];
        }
        delete[] list_lap;
        delete[] type_state;
    }
    void printList() const;
    void printList(const char* type, const char *date) const;
};

class GamingType : public Laptop
{
private:
    char *card;
    int hz;

public:
    GamingType();
    GamingType(char *name, char *brand, char *PRD, long long price, double weight, double battery, char *card, int hz);
    void print() override;
    char *getCard();
    int getHZ();
    ~GamingType();
};

class OfficeType : public Laptop
{
private:
    char *port;
    char *monitor;

public:
    OfficeType();
    OfficeType(char *name, char *brand, char *PRD, long long price, double weight, double battery, char *port, char *monitor);
    void print() override;
    char *getPort();
    char *getMonitor();
    ~OfficeType();
};

class BusinessType : public Laptop
{
private:
    char *security;
    char *type_netW;

public:
    BusinessType();
    BusinessType(char *name, char *brand, char *PRD, long long price, double weight, double battery, char *security, char *type_netW);
    void print() override;
    char *getSecurity();
    char *getType_netW();
    ~BusinessType();
};


char* removeSpace(char* str);
long long parsePrice(char* priceStr);