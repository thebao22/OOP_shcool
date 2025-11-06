#include <iostream>
using namespace std;

class ThoiGian
{
private:
    int gio;
    int phut;
    int giay;

public:
    ThoiGian();
    ThoiGian(int value);
    ThoiGian(int value_1, int value_2);
    ThoiGian(int gio, int phut, int giay);
    void chuanhoa();

    ThoiGian &operator=(const ThoiGian &tg);
    ThoiGian operator+(ThoiGian);
    ThoiGian operator-(ThoiGian);
    bool operator<=(ThoiGian);

    friend bool operator<=(int, ThoiGian);
    friend ThoiGian operator+(int, ThoiGian);
    friend ThoiGian operator-(int, ThoiGian);
    friend ostream &operator<<(ostream &out, ThoiGian);
};
void ThoiGian::chuanhoa()
{
    giay = abs(giay);
    phut = abs(phut);
    gio = abs(gio);
    int phut_du = giay / 60;
    phut += phut_du;
    giay = giay % 60;
    int gio_du = phut / 60;
    gio += gio_du;
    phut = phut % 60;
    gio %= 24;
}
ThoiGian::ThoiGian()
{
    gio = 0;
    phut = 0;
    giay = 0;
}
ThoiGian::ThoiGian(int value)
{
    // value tuong ung voi giay.
    giay = value;
    phut = gio = 0;
    chuanhoa();
}
ThoiGian::ThoiGian(int value_1, int value_2)
{
    // value_1 tuong ung voi giay, value_2 tuong ung voi phut.
    giay = value_2;
    phut = value_1;
    gio = 0;
    chuanhoa();
}
ThoiGian::ThoiGian(int gio_1, int phut_1, int giay_1)
{
    giay = giay_1;
    phut = phut_1;
    gio = gio_1;
    chuanhoa();
}
ThoiGian &ThoiGian::operator=(const ThoiGian &tg)
{
    if (this != &tg)
    {
        gio = tg.gio;
        phut = tg.phut;
        giay = tg.giay;
    }
    return *this;
}
ThoiGian ThoiGian::operator+(ThoiGian tg) {
    ThoiGian temp;
    temp.giay = giay + tg.giay;
    temp.phut = phut + tg.phut;
    temp.gio = gio + tg.gio;
    temp.chuanhoa();
    return temp;
}
ThoiGian ThoiGian::operator-(ThoiGian tg)
{
    ThoiGian temp;
    temp.giay = giay - tg.giay;
    temp.phut = phut - tg.phut;
    temp.gio = gio - tg.gio;
    temp.chuanhoa();
    return temp;
}
bool ThoiGian::operator<=(ThoiGian tg)
{
    int giay1 = gio * 3600 + phut * 60 + giay;
    int giay2 = tg.gio * 3600 + tg.phut * 60 + tg.giay;
    return (giay1 <= giay2);
}

bool operator<=(int a, ThoiGian tg)
{
    ThoiGian temp(a);
    return temp <= tg;
}
ThoiGian operator+(int a, ThoiGian tg)
{
    ThoiGian temp(a);
    return temp + tg;
}
ThoiGian operator-(int a, ThoiGian tg)
{
    ThoiGian temp(a);
    return temp - tg;
}
ostream &operator<<(ostream &out, ThoiGian tg)
{
    if (tg.gio < 10)
        out << "0" << tg.gio;
    else
        out << tg.gio;
    if (tg.phut < 10)
        out << ":" << "0" << tg.phut;
    else
        out << ":" << tg.phut;
    if (tg.giay < 10)
        out << ":" << "0" << tg.giay;
    else
        out << ":" << tg.giay;
    return out;
}

int main()
{
    ThoiGian tg1;               // 00:00:00
    ThoiGian tg2(1212);         // 00:20:12
    ThoiGian tg3(125, 45);      // 02:05:45
    ThoiGian tg4(12, 239, -78); // 16:00:18
    ThoiGian tg5 = tg2 + tg3;   // 02:25:57
    ThoiGian tg6 = 5000 + tg2;  // 01:43:32
    ThoiGian tg7 = tg4 - tg6;   // 14:16:46
    ThoiGian tg8 = 12300 - tg4; // 00:00:00
    ThoiGian tg9, tg10;
    if (tg8 <= tg3)
    {
        tg9 = tg1 + tg2 + 36000; // 10:20:12
    }
    if (12345 <= tg5)
    {
        tg10 = tg5 + 12345; // 05:51:42
    }
    cout << tg1 << endl
         << tg2 << endl
         << tg3 << endl
         << tg4 << endl;
    cout << tg5 << endl
         << tg6 << endl
         << tg7 << endl
         << tg8 << endl;
    cout << tg9 << endl
         << tg10 << endl;
}