#include <iostream>
using namespace std;

class Ngay
{
private:
    int ngay, thang, nam;

public:
    Ngay();
    Ngay(int _ngay, int _thang, int _nam);
    Ngay(int value);
    Ngay(const Ngay &temp);

    Ngay operator+(Ngay);
    friend Ngay operator+(int x, Ngay other);
    Ngay operator-(Ngay);
    friend Ngay operator-(int x, Ngay other);
    Ngay &operator++();
    Ngay operator++(int);
    bool operator>(Ngay);
    Ngay &operator=(Ngay &);
    friend ostream &operator<<(ostream &out, const Ngay &other);
    int ktra_Nhuan();
    void chuanhoa();
    static int Ngay_cua_thang[][12];
};
int Ngay::Ngay_cua_thang[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int Ngay::ktra_Nhuan()
{
    if (nam % 400 == 0)
        return 1;
    return 0;
}
void Ngay::chuanhoa()
{
    ngay = abs(ngay);
    thang = abs(thang);
    nam = abs(nam);

    while (thang > 12)
    {
        thang -= 12;
        nam++;
    }

    int check = ktra_Nhuan();

    while (ngay > Ngay_cua_thang[check][thang - 1])
    {
        ngay -= Ngay_cua_thang[check][thang - 1];
        thang++;
        if (thang > 12)
        {
            thang -= 12;
            nam++;
            check = ktra_Nhuan();
        }
    }
    while (thang > 12)
    {
        thang -= 12;
        nam++;
    }
}
Ngay::Ngay()
{
    ngay = thang = nam = 1;
}
Ngay::Ngay(int _ngay, int _thang, int _nam) : ngay(_ngay), thang(_thang), nam(_nam)
{
    chuanhoa();
}
Ngay::Ngay(int value) : Ngay()
{
    ngay = value;
    chuanhoa();
}
Ngay::Ngay(const Ngay &temp)
{
    ngay = temp.ngay;
    thang = temp.thang;
    nam = temp.nam;
    chuanhoa();
}
Ngay Ngay::operator+(Ngay other)
{
    Ngay temp;
    other.chuanhoa();
    temp.ngay = ngay + other.ngay;
    temp.thang = thang + other.thang;
    temp.nam = nam + other.nam;
    temp.chuanhoa();
    return temp;
}
Ngay operator+(int x, Ngay other)
{
    Ngay temp(x);
    return temp + other;
}
Ngay Ngay::operator++(int)
{
    Ngay temp(*this);
    (*this)++;
    return temp;
}
Ngay &Ngay::operator++()
{
    this->ngay += 1;
    this->chuanhoa();
    return *this;
}
Ngay Ngay::operator-(Ngay other)
{
    Ngay temp;
    other.chuanhoa();
    temp.ngay = ngay - other.ngay;
    temp.thang = thang - other.thang;
    temp.nam = nam - other.nam;
    temp.chuanhoa();
    return temp;
}
Ngay operator-(int x, Ngay other)
{
    Ngay temp(x);
    return temp - other;
}
Ngay &Ngay::operator=(Ngay &other)
{
    other.chuanhoa();
    if (ngay == other.ngay && thang == other.thang && nam == other.nam)
        return *this;
    ngay = other.ngay;
    thang = other.thang;
    nam = other.nam;
    return *this;
}
ostream &operator<<(ostream &out, const Ngay &other)
{
    out << other.ngay << "/" << other.thang << "/" << other.nam;
    return out;
}
int main()
{
    Ngay n1;
    Ngay n2(2, 10, 2014);
    Ngay n3(-10, 16, 2000);
    Ngay n4(1000);
    Ngay n5 = n2 + n3;
    Ngay temp(5000);
    cout << temp << "???" << endl;
    Ngay n6 = n1 + 5000;
    Ngay n7 = 1234 + n4;
    Ngay n8 = 190 + n6 + n7;
    Ngay n9 = n8 - n6;
    Ngay n10 = 12000 - n9;
    cout << n1 << endl
         << n2 << endl
         << n3 << endl
         << n4 << endl;

    cout << n5 << endl
         << n6 << endl
         << n7 << endl
         << n8 << endl;
    cout << n9 << endl
         << n10 << endl;
    system("pause");
}