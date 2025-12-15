#include <iostream>
#include <string>
using namespace std;

class HinhHocPhang
{
public:
    HinhHocPhang() {}
    virtual float TinhDienTich()
    {
        return 0;
    }
};
class HinhChuNhat : public HinhHocPhang
{
private:
    float chieudai, chieurong;

public:
    HinhChuNhat();
    HinhChuNhat(const float cd, const float cr);

    float TinhDienTich();
};
HinhChuNhat::HinhChuNhat()
{
    chieudai = chieurong = 0;
}
HinhChuNhat::HinhChuNhat(const float cd, const float cr)
{
    chieudai = (cd == 0) ? 1 : abs(cd);
    chieurong = (cr == 0) ? 1 : abs(cr);
}
float HinhChuNhat::TinhDienTich()
{
    return chieudai * chieurong;
}

#define Pi 3.14
class HinhTron : public HinhHocPhang
{
private:
    float bankinh;

public:
    HinhTron();
    HinhTron(const float bankinh);

    float TinhDienTich();
};

HinhTron::HinhTron() : bankinh(0) {}
HinhTron::HinhTron(const float bankinh)
{
    this->bankinh = (bankinh == 0) ? 1 : abs(bankinh);
}
float HinhTron::TinhDienTich()
{
    return Pi * bankinh * bankinh;
}

int main()
{
    HinhHocPhang *hhp = new HinhHocPhang();
    HinhChuNhat *hcn = new HinhChuNhat(34, 56.8);
    HinhTron *htr = new HinhTron(73.9);
    cout << hhp->TinhDienTich() << "\t" << hcn->TinhDienTich() << "\t" << htr->TinhDienTich() << "\t";
    cout << endl;
    delete hhp;
    hhp = hcn;
    cout << hhp->TinhDienTich() << endl;
    cout << endl
         << endl;
    delete hcn;
    delete htr;
    cout << endl
         << endl;
    system("pause");
    return 0;
}