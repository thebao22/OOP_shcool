#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
    string street, city, state;

public:
    Address() = default;
    Address(string street, string city, string state) : street(street), city(city), state(state) {}
    void print();
};

class Student
{
protected:
    string name;
    string studentID;
    float GPA;
    Address address;

public:
    Student() = default;
    Student(string name, string studentID, float GPA, string street, string city, string state);
    char getGrade();
    void printInfo();
};

class ExchangeStudent : public Student
{
private:
    string homecountry;
    int exchange_duration;

public:
    ExchangeStudent() = default;
    ExchangeStudent(
        string name, string studentID, float GPA, string street, string city, string state, string homecountry, int exchange_duration);
    void updateDuration(int months);
    void display();
};