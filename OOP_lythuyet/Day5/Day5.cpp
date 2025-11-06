#include <iostream>
using namespace std;

/*syntax: <" "> replace by name of class
    class <base>{};
    class <dirived> : <base>{};

    class <divired>: private / public / protected <base>{};
*/
class Student
{
protected:
    string name;
    int id;
    float gpa;

public:
    Student() = default;
    Student(string name, int id, float gpa) : name(name), id(id), gpa(gpa) {}
    string getGrade();
    void display(){
        cout << "Name: " << name <<", ID: " << id << ", gpa: " << gpa << endl;
    }
};

class ExchangeStusent : public Student
{
private:
    string country;
    int duration;

public:
    ExchangeStusent() = default;
    ExchangeStusent(string name, int id, float gpa, string country, int duration) : 
        Student(name, id, gpa), country(country), duration(duration) {}
    void setDuration(int duration);
    void display(){
         cout << "Name: " << name <<", ID: " << id << ", gpa: " << gpa;
         cout << ", country: " << country << ", Duration: " << duration << " months" << endl;
    }
    
};
string Student::getGrade()
{
    if (gpa > 3)
        return "A";
    else if (gpa > 2)
        return "B";
    else if (gpa > 1)
        return "C";
    return "D";
}
int main()
{
    Student a("xxxxx", 33113, 0.1);
    cout << a.getGrade();
    ExchangeStusent b("aaaaaaa", 33114, 3.5, "Germany", 5);
    a.display();
    b.display();
}