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
    int type;

public:
    NhanVien() : name(""), address(""), type(0) {};
    NhanVien(string name, string address) : name(name), address(address), type(0) {};
    friend istream &operator>>(istream &in, NhanVien &data)
    {
        getline(in, data.name);
        getline(in, data.address);
        return in;
    }
    friend ostream &operator<<(ostream &os, NhanVien &data)
    {
        os << "Ho va ten: " << data.name << endl;
        os << "Dia chi: " << data.address << endl;
        return os;
    }
    int getType() { return type; }
};

class NhanVienThuKi : public NhanVien
{
private:
    string ngoai_ngu;
    int number_report;

public:
    NhanVienThuKi() : NhanVien(), ngoai_ngu(""), number_report(0) {type = 2; };
    NhanVienThuKi(string name, string address, string ngoaingu, int num) : NhanVien(name, address), ngoai_ngu(ngoaingu), number_report(num) { type = 1; };
    friend istream &operator>>(istream &in, NhanVienThuKi &data);
    friend ostream &operator<<(ostream &os, NhanVienThuKi &data);
    int getNum_report();
};

class NhanVienKiThuat : public NhanVien
{
private:
    string chungchinganh;
    int num_create;

public:
    NhanVienKiThuat() : NhanVien(), chungchinganh(""), num_create(0) {type = 2; };
    NhanVienKiThuat(string name, string address, string nganh, int num) : NhanVien(name, address), chungchinganh(nganh), num_create(num) { type = 2; };
    friend istream &operator>>(istream &in, NhanVienKiThuat &data);
    friend ostream &operator<<(ostream &os, NhanVienKiThuat &data);
    int getNumCreate();
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
istream &operator>>(istream &in, NhanVienThuKi &data)
{
    string temp;
    getline(in, temp, ':');
    in >> ws;

    getline(in, data.name, '(');
    getline(in, data.address, ')');
    in >> ws;

    getline(in, temp, '[');
    getline(in, data.ngoai_ngu, ']');
    in >> ws;

    getline(in, temp, '<');
    in >> data.number_report;
    getline(in, temp);
    return in;
}

ostream &operator<<(ostream &os, NhanVienThuKi &data)
{
    os << "Loai Nhan Vien: Nhan vien thu ki" << endl;
    os << "Ho va ten: " << data.name << endl;
    os << "Dia chi: " << data.address << endl;
    os << "Chung chi ngoai ngu: " << data.ngoai_ngu << endl;
    os << "So luong bao cao da hoan thanh: " << data.number_report << endl;
    return os;
}

int NhanVienThuKi::getNum_report()
{
    return number_report;
}
//============ Class NhanVienKiThuat =================
istream &operator>>(istream &in, NhanVienKiThuat &data)
{
    string temp;
    getline(in, temp, ':');
    in >> ws;

    getline(in, data.name, '(');
    getline(in, data.address, ')');
    in >> ws;

    getline(in, temp, '[');
    getline(in, data.chungchinganh, ']');
    in >> ws;

    getline(in, temp, '<');
    in >> data.num_create;
    getline(in, temp);
    return in;
}
ostream &operator<<(ostream &os, NhanVienKiThuat &data)
{
    os << "Loai Nhan Vien: Nhan vien ki thuat" << endl;
    os << "Ho va ten: " << data.name << endl;
    os << "Dia chi: " << data.address << endl;
    os << "Chung chi ngoai ngu: " << data.chungchinganh << endl;
    os << "So luong bao cao da hoan thanh: " << data.num_create << endl;
    return os;
}

int NhanVienKiThuat::getNumCreate() { return num_create; }

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
        if (temp->getType() == 1)
            cout << *(NhanVienThuKi *)temp << endl;
        if (temp->getType() == 2)
            cout << *(NhanVienKiThuat *)temp << endl;
    }
}

void CongTy::dsSinhVienXuatSac()
{
    for (NhanVien *temp : DSnhanvien)
    {
        if (temp->getType() == 1)
        {
            NhanVienThuKi *nv = (NhanVienThuKi *)temp;
            if (nv->getNum_report() >= 12)
                cout << *nv << endl;
        }
        if (temp->getType() == 2)
        {
            NhanVienKiThuat *nv = (NhanVienKiThuat *)temp;
            if (nv->getNumCreate() >= 6)
                cout << *nv << endl;
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
