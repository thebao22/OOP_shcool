#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class HinhHocPhang
{
protected:
    int type;// 1.hcn, 2.htron, 3.hinhthangvuong, 4.hinhtamgiac
    double chuvi;
    double dientich;

public:
    virtual void tinhChuvi() = 0;
    virtual void tinhDientich() = 0;
    virtual void nhap(istream &in) = 0;
    virtual void xuat(ostream &out) = 0;
    friend istream &operator>>(istream &in, HinhHocPhang &data)
    {
        data.nhap(in);
        return in;
    }
    friend ostream &operator<<(ostream &out, HinhHocPhang &data)
    {
        data.xuat(out);
        return out;
    }
    int getType() {return type;}
    double getDientich(){return dientich;}
    double getChuvi(){return chuvi;}
};
class HinhChuNhat : public HinhHocPhang
{
private:
    double chieudai, chieurong;

public:
    HinhChuNhat() : chieudai(0), chieurong(0) {type = 1;}
    HinhChuNhat(double cd, double cr) : chieudai(cd), chieurong(cr) {type = 1;}
    void tinhChuvi() override;
    void tinhDientich() override;
    void nhap(istream &in) override;
    void xuat(ostream &out) override;
};
class HinhTron : public HinhHocPhang
{
private:
    double bankinh;
    const double pi = 3.14;

public:
    HinhTron() : bankinh(0) {type = 2;}
    HinhTron(double r) : bankinh(r) {type = 2;}
    void tinhChuvi() override;
    void tinhDientich() override;
    void nhap(istream &in) override;
    void xuat(ostream &out) override;
};
class HinhThangVuong : public HinhHocPhang
{
private:
    double daylon, daybe, chieucao;

public:
    HinhThangVuong() : daylon(0), daybe(0), chieucao(0) { type = 3;}
    HinhThangVuong(double lon, double be, double cc) : daylon(lon), daybe(be), chieucao(cc) {type = 3;}
    void tinhChuvi() override;
    void tinhDientich() override;
    void nhap(istream &in) override;
    void xuat(ostream &out) override;
};
class HinhTamGiac : public HinhHocPhang
{
private:
    double canh1, canh2, canh3;

public:
    HinhTamGiac() : canh1(0), canh2(0), canh3(0) {type = 4;}
    HinhTamGiac(double a, double b, double c) : canh1(a), canh2(b), canh3(c) {type = 4;}
    void tinhChuvi() override;
    void tinhDientich() override;
    void nhap(istream &in) override;
    void xuat(ostream &out) override;
};

class QuanLyHinhHocPhang
{
private:
    vector<HinhHocPhang *> danhsach;

public:
    void taodanhsach(string filename);
    bool ThemHinhHoc(HinhHocPhang *data);
    void XuatDS();
};

//============ Hinh Chu Nhat ==============
void HinhChuNhat::tinhChuvi()
{
    chuvi = (chieudai + chieurong) * 2;
}

void HinhChuNhat::tinhDientich()
{
    dientich = chieudai * chieurong;
}

void HinhChuNhat::nhap(istream &in)
{
    string temp;
    char _temp;
    getline(in, temp, ':');
    in >> ws;

    in >> chieudai;
    in >> _temp;
    in >> ws;

    in >> chieurong;

    getline(in, temp);
}

void HinhChuNhat::xuat(ostream &out)
{
    tinhChuvi();
    tinhDientich();
    out << "Hinh Chu Nhat:" << chieudai << ", " << chieurong << endl;
    out << "Chu vi: " << chuvi << endl;
    out << "Dien tich: " << dientich << endl;
}
//================== Hinh Tron =====================
void HinhTron::tinhChuvi()
{
    chuvi = 2 * pi * bankinh;
}

void HinhTron::tinhDientich()
{
    dientich = pi * pow(bankinh, 2);
}

void HinhTron::nhap(istream &in)
{
    string temp;
    getline(in, temp, ':');
    in >> ws;

    in >> bankinh;
    getline(in, temp);
}

void HinhTron::xuat(ostream &out)
{
    tinhChuvi();
    tinhDientich();
    out << "Hinh Tron:" << "ban kinh: " << bankinh << endl;
    out << "Chu vi: " << chuvi << endl;
    out << "Dien tich: " << dientich << endl;
}
//================== Hinh Thang Vuong ===============

void HinhThangVuong::tinhChuvi()
{
    double canhben = sqrt(pow(daylon - daybe, 2) + pow(chieucao, 2));
    chuvi = daylon + daybe + chieucao + canhben;
}
void HinhThangVuong::tinhDientich()
{
    dientich = 0.5 * chieucao * (daylon + daybe);
}
void HinhThangVuong::nhap(istream &in)
{
    string temp;
    char _temp;
    getline(in, temp, ':');
    in >> ws;

    in >> daylon;
    in >> _temp;
    in >> daybe;
    in >> _temp;
    in >> chieucao;
    getline(in, temp);
}

void HinhThangVuong::xuat(ostream &out)
{
    tinhChuvi();
    tinhDientich();
    out << "Hinh Thang Vuong:" << daylon << ", " << daybe << ", " << chieucao << endl;
    out << "Chu vi: " << chuvi << endl;
    out << "Dien tich: " << dientich << endl;
}
//=============== Hinh Tam Giac ==================
void HinhTamGiac::tinhChuvi()
{
    chuvi = canh1 + canh2 + canh3;
}
void HinhTamGiac::tinhDientich()
{
    double p = (canh1 + canh2 + canh3) / 2;
    dientich = sqrt(p * (p - canh1) * (p - canh2) * (p - canh3));
}
void HinhTamGiac::nhap(istream &in)
{
    string temp;
    char _temp;
    getline(in, temp, ':');
    in >> ws;

    in >> canh1;
    in >> _temp;
    in >> canh2;
    in >> _temp;
    in >> canh3;
    getline(in, temp);
}
void HinhTamGiac::xuat(ostream &out)
{
    tinhChuvi();
    tinhDientich();
    out << "Hinh Tam Giac:" << canh1 << ", " << canh2 << ", " << canh3 << endl;
    out << "Chu vi: " << chuvi << endl;
    out << "Dien tich: " << dientich << endl;
}

//================= Quan Ly ====================
bool QuanLyHinhHocPhang::ThemHinhHoc(HinhHocPhang *data)
{
    if (!data)
        return false;
    danhsach.push_back(data);

    return true;
}

void QuanLyHinhHocPhang::taodanhsach(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "ERROR!";
        return;
    }
    string temp;

    while (getline(file, temp))
    {
        
        string loai = temp.substr(0, temp.find(':'));
        HinhHocPhang *data = nullptr;

        if (loai == "hcn")
        {
            data = new HinhChuNhat();
        }
        else if (loai == "htr")
        {
            data = new HinhTron();
           }
        else if (loai == "hthv")
        {
            data = new HinhThangVuong();
        }
        else if (loai == "htg")
        {
            data = new HinhTamGiac();
        }
        stringstream ss(temp);  
        ss >> *data;
        data->tinhChuvi();
        data->tinhDientich();

        ThemHinhHoc(data);
    }
    file.close();
}  
void QuanLyHinhHocPhang::XuatDS(){
    vector<int> soluong{0};
    vector<double> dientich{0};
    vector<double> chuvi{0};
    soluong.resize(5);
    dientich.resize(5);
    chuvi.resize(5);
    for(HinhHocPhang *temp : danhsach){
        soluong[temp->getType()] += 1;
        dientich[temp->getType()] += temp->getDientich();
        chuvi[temp -> getType()] += temp->getChuvi();
    }
    cout << "So hinh chu nhat: " << soluong[1] << ", Tong dien tich: " << dientich[1] << ", tong chu vi: " << chuvi[1] << endl;
    cout << "So hinh chu nhat: " << soluong[2] << ", Tong dien tich: " << dientich[2] << ", tong chu vi: " << chuvi[2] << endl;
    cout << "So hinh chu nhat: " << soluong[3] << ", Tong dien tich: " << dientich[3] << ", tong chu vi: " << chuvi[3] << endl;
    cout << "So hinh chu nhat: " << soluong[4] << ", Tong dien tich: " << dientich[4] << ", tong chu vi: " << chuvi[4] << endl;
}

int main (){
    QuanLyHinhHocPhang ql;
    ql.taodanhsach("hhp.txt");
    ql.XuatDS();
}