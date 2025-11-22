#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Company;

class Employee
{
    friend Company;

protected:
    double baseSalary;

public:
    Employee();
    Employee(double _baseSa);
    virtual void describeWork() = 0;
    virtual double getSalary() = 0;
    virtual void print() = 0;
    virtual string getRole() = 0;
};



class Company
{
private:
    vector<Employee*> employList;

public:
    double calcTotalSalary();
    void addEmploy(Employee * emp){
        employList.push_back(emp);
    }
    vector<Employee*> getList(){
        return employList;
    }
};

class Engineer : public Employee
{
private:
    int overtime;
    double bonus_rate;

public:
    Engineer();
    Engineer(double base, int time, double bonus_rate);
    void describeWork() override;
    double getSalary() override;
    string getRole()  override;
    void print() override;
};

class Manager : public Employee
{
private:
    int teamsize;
    double bonus_rate;

public:
    Manager();
    Manager(double base, int size, double bonus_rate);
    void describeWork() override;
    double getSalary() override;
    string getRole() override;
    void print() override;
};
