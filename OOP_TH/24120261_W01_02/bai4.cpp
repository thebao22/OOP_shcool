#include <iostream>
#include <cstring>
using namespace std;

//class Ngaythang
class Ngaythang
{
private:
    int ngay, thang, nam;

public:
    Ngaythang();
    Ngaythang(int _ngay, int _thang, int _nam);
    Ngaythang(const Ngaythang &new_ngaythang);
    void Xuat();
};

class Sinhvien
{
private:
    char MSSV[8];
    char *HoTen;
    float DLT, DTH;
    Ngaythang ngaysinh;

public:
    Sinhvien();
    Sinhvien(const char *_MSSV);
    Sinhvien(const char *_MSSV, const char *_HoTen, float _DLT, int _DTH);
    Sinhvien(const char *_MSSV, const char *_HoTen, float _DLT, int _DTH, int ngay, int thang, int nam);
    Sinhvien(const char *_MSSV, const char *_HoTen, float _DLT, int _DTH, const Ngaythang ntn);
    Sinhvien(const Sinhvien &old);
    ~Sinhvien();
    void xuat();
};

// dinh nghia cac ham trong class Ngaythang:
Ngaythang::Ngaythang()
{
    ngay = thang = nam = 1;
}
Ngaythang::Ngaythang(int _ngay, int _thang, int _nam)
{
    ngay = _ngay;
    thang = _thang;
    nam = _nam;
}
Ngaythang::Ngaythang(const Ngaythang &new_ngaythang)
{
    ngay = new_ngaythang.ngay;
    thang = new_ngaythang.thang;
    nam = new_ngaythang.nam;
}
void Ngaythang::Xuat(){
    cout << ngay << "/" << thang << "/" << nam << endl;
}

// dinh nghia cac ham trong class Sinhvien:
Sinhvien::Sinhvien()
{
    strcpy(MSSV, "xxxxxxx");
    HoTen = new char[5];
    strcpy(HoTen, "xxxx");
    DLT = DTH = 10;
    ngaysinh = Ngaythang();
}
Sinhvien::Sinhvien(const char *_MSSV)
{
    strcpy(MSSV, _MSSV);
    HoTen = new char[5];
    strcpy(HoTen, "xxxx");
    DLT = DTH = 10;
    ngaysinh = Ngaythang();
}
Sinhvien::Sinhvien(const char *_MSSV, const char *_HoTen, float _DLT, int _DTH)
{
    strcpy(MSSV, _MSSV);
    int len = strlen(_HoTen);
    HoTen = new char[len + 1];
    strcpy(HoTen, _HoTen);
    DLT = _DLT;
    DTH = _DTH;
    ngaysinh = Ngaythang();
}
Sinhvien::Sinhvien(const char *_MSSV, const char *_HoTen, float _DLT, int _DTH, int ngay, int thang, int nam)
{
    strcpy(MSSV, _MSSV);
    int len = strlen(_HoTen);
    HoTen = new char[len + 1];
    strcpy(HoTen, _HoTen);
    DLT = _DLT;
    DTH = _DTH;
    ngaysinh = Ngaythang(ngay, thang, nam);
}
Sinhvien::Sinhvien(const char *_MSSV, const char *_HoTen, float _DLT, int _DTH, const Ngaythang ntn)
{
    strcpy(MSSV, _MSSV);
    int len = strlen(_HoTen);
    HoTen = new char[len + 1];
    strcpy(HoTen, _HoTen);
    DLT = _DLT;
    DTH = _DTH;
    ngaysinh = Ngaythang(ntn);
}
Sinhvien::Sinhvien(const Sinhvien &old){
    strcpy(MSSV, old.MSSV);
    int len = strlen(old.HoTen);
    HoTen = new char[len + 1];
    strcpy(HoTen, old.HoTen);
    DLT = old.DLT;
    DTH = old.DTH;
    ngaysinh = Ngaythang(old.ngaysinh);
}
void Sinhvien::xuat(){
    cout << "MSSV: " << MSSV << endl;
    cout << "Ho va Ten: " << HoTen << endl;
    cout << "DLT: " << DLT << endl;
    cout << "DTH: " << DTH << endl;
    cout << "Ngay sinh: ";
    ngaysinh.Xuat();
    cout << endl;
}
Sinhvien::~Sinhvien(){
    delete[] HoTen;
}
int main()
{
    //MSSV: "xxxxxxx", HoTen: "xxxx", NgaySinh: xx/xx/xxxx, DLT: 10, DTH: 10.
    Sinhvien sv1;
    sv1.xuat();
    Sinhvien sv2("1363001");
    sv2.xuat();
    Sinhvien sv3("1363002", "Nguyen Van A", 7, 8.5);
    sv3.xuat();
    Sinhvien sv4("1363003", "Tran Thi B", 8, 9.5, 12, 3, 1996);
    sv4.xuat();
    Ngaythang n(30, 2, 1996);
    Sinhvien sv5("1363004", "Ngo Van C", 5, 6, n);
    sv5.xuat();
    Sinhvien sv6(sv5);
    sv6.xuat();

    // giai phong bo nho.
    sv1.~Sinhvien(); 
    sv2.~Sinhvien();
    sv3.~Sinhvien();
    sv4.~Sinhvien();
    sv5.~Sinhvien();
    sv6.~Sinhvien();
    
    return 0;
}