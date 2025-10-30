#include <iostream>
#include <math.h>
#include <cstring>
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
    ~ThoiGian();
    void chuanhoa();
    void Xuat();
};
void ThoiGian::chuanhoa()
{
    if (giay < 0)
        giay = 0;
    phut = abs(phut);
    gio = abs(gio);
    int phut_du = giay / 60;
    phut += phut_du;
    giay = giay % 60;
    int gio_du = phut / 60;
    gio += gio_du;
    phut = phut % 60;
    while (gio > 24)
    {
        gio = gio / 24;
    }
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
void ThoiGian::Xuat()
{
    if (gio < 10)
        cout << "0" << gio;
    else
        cout << gio;
    if (phut < 10)
        cout << ":" << "0" << phut;
    else
        cout << ":" << phut;
    if (giay < 10)
        cout << ":" << "0" << giay;
    else
        cout << ":" << giay;
    cout << endl;
}
ThoiGian::~ThoiGian()
{
}
int main()
{
    ThoiGian tg1;
    tg1.Xuat(); // 00:00:00
    ThoiGian tg2(1212);
    tg2.Xuat(); // 00:20:12
    ThoiGian tg3(125, 45);
    tg3.Xuat(); // 02:05:45
    ThoiGian tg4(12, 239, -78);
    tg4.Xuat(); // 15:59:00
}