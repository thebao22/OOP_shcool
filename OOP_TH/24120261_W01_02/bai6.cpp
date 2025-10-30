#include <iostream>
#include <cmath>
#include <math.h>
#include <numeric>
using namespace std;

class phanso
{
private:
    int num;
    int denom;

public:
    phanso() : num(1), denom(1) {}
    phanso(int a, int b) : num(a/gcd(a,b)), denom(b/gcd(a,b)) {}
    phanso(int a) : num(a), denom(1) {}
    // phanso(int b) : num(1), denom(b) {}
    phanso operator+(phanso);
    phanso operator+(int);
    friend phanso operator+(int, phanso);
    phanso operator++();
    phanso operator++(int);
    void xuat();
    friend ostream &operator<<(ostream &out, const phanso &ps);
    
};
phanso phanso::operator+(phanso ps)
{
    return phanso(num * ps.denom + ps.num * denom, denom * ps.denom);
}
phanso phanso::operator+(int a)
{
    phanso temp(a);
    return phanso((num * temp.denom + temp.num * denom), denom * temp.denom);
}
phanso operator+(int a, phanso ps)
{
    return ps + a;
}
phanso phanso::operator++()
{
    phanso temp(this->num, this->denom);
    return temp + 1;
}
phanso phanso::operator++(int)
{
    phanso temp(this->num, this->denom);
    num += denom;
    return temp;
}
ostream &operator<<(ostream &out, const phanso &ps)
{
    if(ps.denom == 1)
        out << ps.num << endl;
    else
        out << ps.num << "/" << ps.denom << endl;
    return out;
}
int main()
{
    phanso a(5, 6);
    phanso b(1, 6);
    phanso c = a + b;
    cout << c;
}