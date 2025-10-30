#include <iostream>
#include <cstring>
using namespace std;
class Ngay
{
private:
    int ngay, thang, nam;

public:
    Ngay();
    Ngay(int _ngay, int _thang, int _nam);
    Ngay(int _ngay);
    Ngay(const char *s);
    void chuanhoa();
    void xuat();
};

void Ngay::chuanhoa()
{
    ngay = abs(ngay);
    thang = abs(thang);
    nam = abs(nam);
    int thang_du = (ngay - 1) / 30;
    thang += thang_du;
    int nam_du = (thang - 1) / 12;
    nam += nam_du;
    ngay = (ngay - 1) % 30 + 1;
    thang = (thang - 1) % 12 + 1;
}
void Ngay::xuat()
{
    cout << ngay << "/" << thang << "/" << nam;
}
Ngay::Ngay()
{
    ngay = thang = nam = 1;
}
Ngay::Ngay(int _ngay, int _thang, int _nam)
{
    ngay = _ngay;
    thang = _thang;
    nam = _nam;
    chuanhoa();
}
Ngay::Ngay(const char *s)
{
    ngay = 0;
    thang = 0;
    nam = 0;
    int len = strlen(s);
    char delimiter_1 = '-';
    char delimiter_2 = '/';
    // char *temp = new char(len + 1);
    int temp = 0;
    int count = 0;
    for (int i = 0; i <= len; i++)
    {
        count++;
        if (s[i] == delimiter_1 || s[i] == delimiter_2 || i == len)
        {
            if (ngay == 0)
                ngay = temp;
            else if (thang == 0)
                thang = temp;
            else if (nam == 0)
                nam = temp;
            temp = 0;
        }
        else
            temp = temp * 10 + (s[i] - '0');
    }

    chuanhoa();
}
int main()
{
    Ngay n5("12-12-2012");
    n5.xuat();
}