#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class NhanVien
{
protected:
    string name;
    string address;

public:
    NhanVien() : name(""), address("") {};
    NhanVien(string name, string address) : name(name), address(address) {};
    virtual void xuat(ostream &os) = 0;
    virtual void nhap(istream &in) = 0;
    virtual int KPI() = 0;
    virtual string typeKPI() = 0;

    friend istream &operator>>(istream &in, NhanVien &data)
    {
        data.nhap(in);
        return in;
    }
    friend ostream &operator<<(ostream &os, NhanVien &data)
    {
        data.xuat(os);
        return os;
    }
};

class NhanVienThuKi : public NhanVien
{
private:
    string ngoai_ngu;
    int number_report;

public:
    NhanVienThuKi() : NhanVien(), ngoai_ngu(""), number_report(0) {};
    NhanVienThuKi(string name, string address, string ngoaingu, int num) : NhanVien(name, address), ngoai_ngu(ngoaingu), number_report(num) {};
    void xuat(ostream &os) override;
    void nhap(istream &in) override;
    int KPI() override;
    string typeKPI() override { return "report"; }
};

class NhanVienKiThuat : public NhanVien
{
private:
    string chungchinganh;
    int num_create;

public:
    NhanVienKiThuat() : NhanVien(), chungchinganh(""), num_create(0) {};
    NhanVienKiThuat(string name, string address, string nganh, int num) : NhanVien(name, address), chungchinganh(nganh), num_create(num) {};
    void xuat(ostream &os) override;
    void nhap(istream &in) override;
    int KPI() override;
    string typeKPI() override { return "create"; }
};

class CongTy
{
private:
    vector<NhanVien *> DSnhanvien;

public:
    void taoDanhSach(string filename);
    bool themNhanvien(NhanVien *);
    void xuatDS();
    void dsSinhVienXuatSac();
};

//================class NhanVienThuKi===============
void NhanVienThuKi::nhap(istream &in)
{
    string temp;
    getline(in, temp, ':');
    in >> ws;

    getline(in, name, '(');
    getline(in, address, ')');
    in >> ws;

    getline(in, temp, '[');
    getline(in, ngoai_ngu, ']');
    in >> ws;

    getline(in, temp, '<');
    in >> number_report;
    getline(in, temp);
}

void NhanVienThuKi:: xuat(ostream &os)
{
    os << "Loai Nhan Vien: Nhan vien thu ki" << endl;
    os << "Ho va ten: " << name << endl;
    os << "Dia chi: " << address << endl;
    os << "Chung chi ngoai ngu: " << ngoai_ngu << endl;
    os << "So luong bao cao da hoan thanh: " << number_report << endl;
}

int NhanVienThuKi::KPI()
{
    return number_report;
}
//============ Class NhanVienKiThuat =================
void NhanVienKiThuat::nhap(istream &in)
{
    string temp;
    getline(in, temp, ':');
    in >> ws;

    getline(in, name, '(');
    getline(in, address, ')');
    in >> ws;

    getline(in, temp, '[');
    getline(in, chungchinganh, ']');
    in >> ws;

    getline(in, temp, '<');
    in >> num_create;
    getline(in, temp);
}
void NhanVienKiThuat:: xuat(ostream &os)
{
    os << "Loai Nhan Vien: Nhan vien ki thuat" << endl;
    os << "Ho va ten: " << name << endl;
    os << "Dia chi: " << address << endl;
    os << "Chung chi ngoai ngu: " << chungchinganh << endl;
    os << "So luong bao cao da hoan thanh: " << num_create << endl;
}

int NhanVienKiThuat::KPI() { return num_create; }

//============== Class CongTy===================
bool CongTy::themNhanvien(NhanVien *data)
{
    if (!data)
        return false;
    DSnhanvien.push_back(data);
    return true;
}
void CongTy::taoDanhSach(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "ERROR!";
        return;
    }
    string line;
    while (getline(file, line))
    {
        string loai = line.substr(0, line.find(':'));
        NhanVien *data = nullptr;
        if (loai == "nvtk")
        {
            data = new NhanVienThuKi();
        }
        else if (loai == "nvkt")
        {
            data = new NhanVienKiThuat();
        }
        else
            continue;
        stringstream ss(line);
        ss >> *data;
        themNhanvien(data);
    }
    file.close();
}

void CongTy::xuatDS()
{
    for (NhanVien *temp : DSnhanvien)
    {
        cout << *temp << endl;
    }
}

void CongTy::dsSinhVienXuatSac()
{
    for (NhanVien *temp : DSnhanvien)
    {
        if ((temp->typeKPI() == "report" && temp->KPI() >= 12) || (temp->typeKPI() == "create" && temp->KPI() >= 6))
        {
            cout << *temp << endl;
        }
    }
}

int main()
{
    CongTy ct;

    ct.taoDanhSach("input.txt");

    cout << "\n===== DANH SACH NHAN VIEN =====\n";
    ct.xuatDS();

    cout << "\n===== DANH SACH NHAN VIEN XUAT SAC =====\n";
    ct.dsSinhVienXuatSac();

    return 0;
}
