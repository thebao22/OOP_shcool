#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#define PI 3.14
using namespace std;

class Hinh
{
protected:
public:
    virtual ~Hinh() {}
    virtual void xuat(ostream &os) const = 0;
    friend ostream &operator<<(ostream &os, const Hinh &data)
    {
        data.xuat(os);
        return os;
    }
};

class Hinh2D : public Hinh
{
public:
    virtual double tinhDienTich() const = 0;
    virtual double tinhChuVi() const = 0;
};

class Hinh3D : public Hinh
{
public:
    virtual double tinhSxq() const = 0;
    virtual double tinhTheTich() const = 0;
};

class HinhChuNhat : public Hinh2D
{
private:
    double chieudai, chieurong;

public:
    HinhChuNhat();
    HinhChuNhat(double cd, double cr);
    double tinhChuVi() const override;
    double tinhDienTich() const override;
    void xuat(ostream &os) const override;
};

class HinhTamGiacDeu : public Hinh2D
{
private:
    double dodai;

public:
    HinhTamGiacDeu();
    HinhTamGiacDeu(double _dodai);
    double tinhChuVi() const override;
    double tinhDienTich() const override;
    void xuat(ostream &os) const override;
};

class HinhTron : public Hinh2D
{
private:
    double bankinh;

public:
    HinhTron();
    HinhTron(double bk);
    double tinhChuVi() const override;
    double tinhDienTich() const override;
    void xuat(ostream &os) const override;
};

class HinhVuong : public Hinh2D
{
private:
    double canh;

public:
    HinhVuong();
    HinhVuong(double _canh);
    double tinhChuVi() const override;
    double tinhDienTich() const override;
    void xuat(ostream &os) const override;
};

class HinhCau : public Hinh3D
{
private:
    double bankinh;

public:
    HinhCau();
    HinhCau(double bk);
    double tinhSxq() const override;
    double tinhTheTich() const override;
    void xuat(ostream &os) const override;
};

class HinhLapPhuong : public Hinh3D
{
private:
    double canh;

public:
    HinhLapPhuong();
    HinhLapPhuong(double c);
    double tinhSxq() const override;
    double tinhTheTich() const override;
    void xuat(ostream &os) const override;
};

class HinhHop : public Hinh3D
{
private:
    double chieudai, chieurong, chieucao;

public:
    HinhHop();
    HinhHop(double cs, double cr, double cc);
    double tinhSxq() const override;
    double tinhTheTich() const override;
    void xuat(ostream &os) const override;
};

class HinhTru : public Hinh3D
{
private:
    double chieucao, bankinh;

public:
    HinhTru();
    HinhTru(double cc, double bk);
    double tinhSxq() const override;
    double tinhTheTich() const override;
    void xuat(ostream &os) const override;
};

class HinhNon : public Hinh3D
{
private:
    double bankinh, chieucao;

public:
    HinhNon();
    HinhNon(double bk, double cc);
    double tinhSxq() const override;
    double tinhTheTich() const override;
    void xuat(ostream &os) const override;
};

//====================== Hinh Tron =====================
HinhTron::HinhTron() : bankinh(0) {}
HinhTron::HinhTron(double bk) : bankinh(bk) {}
double HinhTron::tinhDienTich() const { return PI * bankinh * bankinh; }
double HinhTron::tinhChuVi() const { return 2 * PI * bankinh; }
void HinhTron::xuat(ostream &os) const
{
    os << "Hinh Tron [P = " << tinhChuVi() << ", S = " << tinhDienTich() << "]";
}

//=========== Hinh Chu Nhat ===============
HinhChuNhat::HinhChuNhat() : chieudai(0), chieurong(0) {}
HinhChuNhat::HinhChuNhat(double cd, double cr) : chieudai(cd), chieurong(cr) {}
double HinhChuNhat::tinhDienTich() const { return chieudai * chieurong; }
double HinhChuNhat::tinhChuVi() const { return (chieudai + chieurong) * 2; }
void HinhChuNhat::xuat(ostream &os) const
{
    os << "Hinh Chu Nhat [P = " << tinhChuVi() << ", S = " << tinhDienTich() << "]";
}

//=========== Hinh Tam Giac Deu =============
HinhTamGiacDeu::HinhTamGiacDeu() : dodai(0) {}
HinhTamGiacDeu::HinhTamGiacDeu(double _dodai) : dodai(_dodai) {}
double HinhTamGiacDeu::tinhChuVi() const { return dodai * 3; }
double HinhTamGiacDeu::tinhDienTich() const { return (dodai * dodai * sqrt(3)) / 4; }
void HinhTamGiacDeu::xuat(ostream &os) const
{
    os << "Hinh Tam Giac Deu [P = " << tinhChuVi() << ", S = " << tinhDienTich() << "]";
}

//=========== Hinh Vuong ====================
HinhVuong::HinhVuong() : canh(0) {}
HinhVuong::HinhVuong(double canh) : canh(canh) {}
double HinhVuong::tinhChuVi() const { return canh * 4; }
double HinhVuong::tinhDienTich() const { return canh * canh; }
void HinhVuong::xuat(ostream &os) const
{
    os << "Hinh Vuong [P = " << tinhChuVi() << ", S = " << tinhDienTich() << "]";
}

//========== Hinh Cau =======================
HinhCau::HinhCau() : bankinh(0) {}
HinhCau::HinhCau(double bk) : bankinh(bk) {}
double HinhCau::tinhSxq() const { return 4 * PI * bankinh * bankinh; }
double HinhCau::tinhTheTich() const { return (4 * (PI * pow(bankinh, 3))) / 3; }
void HinhCau::xuat(ostream &os) const
{
    os << "Hinh Cau [Sxq = " << tinhSxq() << ", V = " << tinhTheTich() << "]";
}

//=========== Hinh Lap Phuong =================
HinhLapPhuong::HinhLapPhuong() : canh(0) {}
HinhLapPhuong::HinhLapPhuong(double canh) : canh(canh) {}
double HinhLapPhuong::tinhSxq() const { return 4 * canh * canh; }
double HinhLapPhuong::tinhTheTich() const { return pow(canh, 3); }
void HinhLapPhuong::xuat(ostream &os) const
{
    os << "Hinh Lap Phuong [Sxq = " << tinhSxq() << ", V = " << tinhTheTich() << "]";
}

//============= Hinh Hop ======================
HinhHop::HinhHop() : chieudai(0), chieurong(0), chieucao(0) {}
HinhHop::HinhHop(double a, double b, double h) : chieudai(a), chieurong(b), chieucao(h) {}
double HinhHop::tinhSxq() const { return 2 * chieucao * (chieudai + chieurong); }
double HinhHop::tinhTheTich() const { return chieudai * chieurong * chieucao; }
void HinhHop::xuat(ostream &os) const
{
    os << "Hinh Hop [Sxq = " << tinhSxq() << ", V = " << tinhTheTich() << "]";
}

//============ Hinh Tru ====================
HinhTru::HinhTru() : chieucao(0), bankinh(0) {}
HinhTru::HinhTru(double h, double r) : chieucao(h), bankinh(r) {}
double HinhTru::tinhSxq() const { return 2 * PI * bankinh * chieucao; }
double HinhTru::tinhTheTich() const { return PI * pow(bankinh, 2) * chieucao; }
void HinhTru::xuat(ostream &os) const
{
    os << "Hinh Tru [Sxq = " << tinhSxq() << ", V = " << tinhTheTich() << "]";
}

//================= Hinh Non ===================
HinhNon::HinhNon() : bankinh(0), chieucao(0) {}
HinhNon::HinhNon(double r, double h) : bankinh(r), chieucao(h) {}
double HinhNon::tinhSxq() const
{
    double duongsinh = sqrt(bankinh * bankinh + chieucao * chieucao);
    return 2 * PI * bankinh * duongsinh;
}
double HinhNon::tinhTheTich() const { return (PI * pow(bankinh, 2) * chieucao) / 3; }
void HinhNon::xuat(ostream &os) const
{
    os << "Hinh Non [Sxq = " << tinhSxq() << ", V = " << tinhTheTich() << "]";
}