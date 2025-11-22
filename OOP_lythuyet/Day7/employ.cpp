#include "employLib.h"
double Company::calcTotalSalary()
{
    double total = 0;
    for (int i = 0; i < employList.size(); i++)
    {
        total += employList[i]->getSalary();
    }
    return total;
}

Employee::Employee() : baseSalary(0) {}
Employee::Employee( double baseSa) : baseSalary(baseSa) {}

Engineer::Engineer() : Employee(),  overtime(0), bonus_rate(0) {}
Engineer::Engineer(double base, int time, double bonus_rate) : Employee(base), overtime(time), bonus_rate(bonus_rate) {}
void Engineer::describeWork(){
    cout << "I'm a app engineer";
}
string Engineer::getRole(){
    return "Engineer";
}

double Engineer::getSalary()
{
    return baseSalary + overtime * bonus_rate;
}
void Engineer::print(){
    cout << "Role: " << getRole() << endl;
    cout << "Base Salary: " << baseSalary << endl; 
    describeWork();
}

Manager::Manager() : Employee(), teamsize(0), bonus_rate(0){}
Manager::Manager(double base, int size, double bonus_rate): Employee(base), teamsize(size), bonus_rate(bonus_rate){}

void Manager::describeWork(){
    cout << "I'm a app Manager";
}
string Manager::getRole(){
    return "Manager";
}

double Manager::getSalary()
{
    return baseSalary + teamsize * bonus_rate;
}
void Manager::print(){
    cout << "Role: " << getRole() << endl;
    cout << "Base Salary: " << baseSalary << endl; 
    describeWork();
}