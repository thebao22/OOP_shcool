#include <iostream>
using namespace std;

class NhanVien
{
private:
    string Hoten, Diachi;

public:
    NhanVien();
    NhanVien(string Hoten, string Diachi);
    ~NhanVien();
    friend ostream &operator<<(ostream &out, const NhanVien &data);
};

NhanVien::NhanVien() : Hoten(""), Diachi("") {}
NhanVien::NhanVien(string Hoten, string Diachi) : Hoten(Hoten), Diachi(Diachi) {}
NhanVien::~NhanVien()
{
}
ostream &operator<<(ostream &out, const NhanVien &data)
{
    out << data.Hoten << "(" << data.Diachi << ")";
    return out;
}

class NhanVienKiThuat : public NhanVien
{
private:
    string chungchinganh;

public:
    NhanVienKiThuat() : NhanVien(), chungchinganh("") {}
    NhanVienKiThuat(string ten, string dc, string chungchinganh) : NhanVien(ten, dc), chungchinganh(chungchinganh) {}
    ~NhanVienKiThuat();
    friend ostream &operator<<(ostream &out, const NhanVienKiThuat &data);
};
NhanVienKiThuat::~NhanVienKiThuat() {}
ostream &operator<<(ostream &out, const NhanVienKiThuat &data)
{
    out << (NhanVien)data;
    out << " [" << data.chungchinganh << "]";
    return out;
}
int main()
{
    NhanVienKiThuat nvkt("Nguyen Van A", "Nguyen Van Cu, Q.5", "CNTT");
    cout << nvkt << endl
         << endl;
    system("pause");
    return 0;
}