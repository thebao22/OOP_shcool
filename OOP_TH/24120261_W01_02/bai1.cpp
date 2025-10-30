#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
static int maxNum = 0;
class Object
{
private:
    int info;
    int curNum;

public:
    Object();
    Object(int value);
    ~Object();
};
Object::Object()
{
    info = 0;
    curNum = ++maxNum;
    cout << "khoi tao (mac dinh) doi tuong " << curNum << endl;
}
Object::Object(int value)
{
    info = value;
    curNum = ++maxNum;
    cout << "khoi tao (co doi so) doi tuong " << curNum << endl;
}
Object::~Object()
{
    cout << "huy doi tuong " << curNum << endl;
}
void creat()
{
    Object obj1(5);
    Object obj2;
}
Object objglobal;
int main()
{
    Object obj1;
    creat();
    Object obj2(3);
    for (int i = 0; i < 10; i++)
    {
        cout << i;
    }
}