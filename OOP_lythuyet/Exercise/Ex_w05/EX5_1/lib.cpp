#include "lib.h"
//---IMPLEMENT CLASS ADDRESS---
void Address::print()
{
    cout << street << " " << city << " " << state << " ";
}

//---IMPLEMENT CLASS STUDENT---
Student::Student(string name, string studentID, float GPA, string street, string city, string state): 
    name(name), studentID(studentID), GPA(GPA), address(street, city, state) {}
char Student::getGrade()
{
    if (GPA >= 3.6)
        return 'A';
    if (GPA >= 3.2)
        return 'B';
    if (GPA >= 2.5)
        return 'C';
    if (GPA >= 2.0)
        return 'D';
    return 'E';
}
void Student::printInfo()
{
    cout << "name: " << name << endl;
    cout << "studentID: " << studentID << endl;
    cout << "GPA: " << GPA << endl;
    cout << "address: ";
    address.print();
    cout << endl;
}

//---IMPLEMENT CLASS EXCHANGE STUDENT---
ExchangeStudent::ExchangeStudent(string name, string studentID, float GPA, string street, 
    string city, string state, string homecountry, int exchange_duration): 
        Student(name,studentID,GPA, street, city, state), homecountry(homecountry), exchange_duration(exchange_duration){}

void ExchangeStudent::updateDuration(int months){
    exchange_duration = months;
}
void ExchangeStudent::display(){
    printInfo();
    cout << "homecountry: " << homecountry <<endl;
    cout << "Exchange durations: " << exchange_duration <<" months" << endl;
}