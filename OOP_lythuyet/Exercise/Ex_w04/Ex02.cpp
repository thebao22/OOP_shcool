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
    phanso(int a, int b) : num(a / gcd(a, b)), denom(b / gcd(a, b)) {}
    phanso(int a) : num(a), denom(1) {}

    phanso operator+(phanso);
    phanso operator-(phanso);
    phanso operator*(phanso);
    phanso operator/(phanso);

    phanso operator+(int);
    phanso operator-(int);
    phanso operator*(int);
    phanso operator/(int);

    phanso operator++();
    phanso operator++(int);
    phanso operator--();
    phanso operator--(int);

    bool operator==(phanso);
    bool operator!=(phanso);
    bool operator==(int);
    bool operator<(phanso);
    bool operator<=(phanso);
    bool operator>(phanso);
    bool operator>=(phanso);

    phanso &operator+=(const phanso &);
    phanso &operator-=(const phanso &);
    phanso &operator*=(const phanso &);

    operator float const();
    operator int const();

    friend ostream &operator<<(ostream &out, const phanso &ps);
    friend istream &operator>>(istream &in, phanso &ps);
};

int main()
{
    cout << "ALL TEST CASE=============" << endl;
    cout << endl;
    phanso ps1(1, 2);
    phanso ps2(3, 16);
    cout << "1st Fraction: " << ps1 << ", 2nd Fraction: " << ps2 << endl;
    cout << "Result of operator +: " << (ps1 + ps2) << endl;
    cout << "Result of operator -: " << (ps1 - ps2) << endl;
    cout << "Result of operator *: " << (ps1 * ps2) << endl;
    cout << "Result of operator /: " << (ps1 / ps2) << endl;
    cout << endl;

    //
    phanso ps3;
    cout << "3rd Fraction: " << ps3;
    cout << "Result of operator += 2nd Fraction: " << (ps3 += ps2) << endl;
    cout << "Result of operator -= 2nd Fraction: " << (ps3 -= ps2) << endl;
    cout << "Result of operator *= 2nd Fraction: " << (ps3 *= ps2) << endl;
    cout << endl;

    //
    phanso ps4(5, 8);
    cout << "4th Fraction: " << ps4 << endl;
    cout << "Result of operator ++(post): " << ps4++ << endl;
    cout << "Result of operator --(post): " << ps4-- << endl;
    cout << "Result of operator type-cast(float): " << (float)ps4 << endl;
    cout << "Result of operator type-cast(int): " << (int)ps4 << endl;
    cout << endl;

    //
    phanso ps5;
    cout << "test input operator: cin >> fraction" << endl;
    cin >> ps5;
    cout << "5th Fraction: " << ps5 << endl;
    cout << "All result of comparations with 3rd Fraction:" << endl;
    cout << "Result of operator ==: " << (ps5 == ps3) << endl;
    cout << "Result of operator !=: " << (ps5 != ps3) << endl;
    cout << "Result of operator <: " << (ps5 < ps3) << endl;
    cout << "Result of operator >: " << (ps5 > ps3) << endl;
    cout << "Result of operator <=: " << (ps5 <= ps3) << endl;
    cout << "Result of operator >=: " << (ps5 >= ps3) << endl;
}

// Implement
phanso phanso::operator+(phanso ps)
{
    return phanso(num * ps.denom + ps.num * denom, denom * ps.denom);
}
phanso phanso::operator-(phanso ps)
{
    return phanso(num * ps.denom - ps.num * denom, denom * ps.denom);
}
phanso phanso::operator*(phanso ps)
{
    return phanso(num * ps.num, denom * ps.denom);
}
phanso phanso::operator/(phanso ps)
{
    return phanso(num * ps.denom, ps.num * denom);
}
phanso phanso::operator+(int a)
{
    phanso temp(a);
    return phanso((num * temp.denom + temp.num * denom), denom * temp.denom);
}
phanso phanso::operator-(int a)
{
    phanso temp(a);
    return phanso((num * temp.denom - temp.num * denom), denom * temp.denom);
}
phanso phanso::operator*(int a)
{
    phanso temp(a);
    return phanso((num * temp.num), denom * temp.denom);
}
phanso phanso::operator/(int a)
{
    phanso temp(a);
    return phanso(num * temp.denom, temp.num * denom);
}

// Increment & Decrement: ++, --
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
phanso phanso::operator--()
{
    phanso temp(this->num, this->denom);
    return temp - 1;
}
phanso phanso::operator--(int)
{
    phanso temp(this->num, this->denom);
    num -= denom;
    return temp;
}

// Type-cast: (float), (int)
phanso::operator float const()
{
    return (float)num / (float)denom;
}
phanso::operator int const()
{
    return (int)num / (int)denom;
}

// Comparation: >, <, ==, >=, <=, !=
bool phanso::operator==(phanso ps)
{
    return (num * ps.denom == denom * ps.num);
}
bool phanso::operator==(int temp)
{
    phanso ps(temp);
    return (num * ps.denom == denom * ps.num);
}
bool phanso::operator!=(phanso ps)
{
    return (num * ps.denom != denom * ps.num);
}
bool phanso::operator<(phanso ps)
{
    return (num * ps.denom < denom * ps.num);
}
bool phanso::operator>(phanso ps)
{
    return (num * ps.denom > denom * ps.num);
}
bool phanso::operator<=(phanso ps)
{
    return (num * ps.denom <= denom * ps.num);
}
bool phanso::operator>=(phanso ps)
{
    return (num * ps.denom >= denom * ps.num);
}

// Assignment: =, +=, *=
phanso &phanso::operator+=(const phanso &ps)
{
    *this = *this + ps;
    return *this;
}
phanso &phanso::operator-=(const phanso &ps)
{
    *this = *this - ps;
    return *this;
}
phanso &phanso::operator*=(const phanso &ps)
{
    *this = *this * ps;
    return *this;
}

// Input & Output: >>, <<
ostream &operator<<(ostream &out, const phanso &ps)
{
    if (ps.denom == 1)
        out << ps.num << endl;
    else
        out << ps.num << "/" << ps.denom;
    return out;
}
istream &operator>>(istream &in, phanso &ps)
{
    cout << "nhap phan so (tu mau): ";
    in >> ps.num >> ps.denom;
    if (ps.denom == 0)
        ps.denom = 1;
    return in;
}