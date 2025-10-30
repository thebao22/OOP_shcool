#include <cstring>
#include <iostream>
using namespace std;

class HocSinh {
 private:
  char* HoTen;
  static int MSSV;
  int mssv = MSSV;
  float Toan, Van, Anh;
  float Diem_TB;
  static HocSinh* Max;
  void CapnhatMAX();

 public:
  HocSinh();
  HocSinh(const char*);
  HocSinh(float _toan, float _Van, float _Anh);
  HocSinh(const char*, float _toan, float _Van, float _Anh);
  ~HocSinh();

  void DatHoTen(const char*);
  void GanDiem(float _toan, float _Van, float _Anh);
  void SetTB();

  static HocSinh HSDiemTBCaoNhat();
  void In(ostream& out) {
    out << "HS: " << HoTen << ", MS: " << mssv << ", DTB: " << Diem_TB << endl;
  }
};
int HocSinh::MSSV = 23120001;
HocSinh* HocSinh::Max = nullptr;

int main() {
  HocSinh hs1;
  hs1.DatHoTen("Nguyen Van A");
  hs1.GanDiem(7, 8, 10);

  HocSinh hs2("Tran Thi B", 5, 8, 4.5);
  HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
  HocSinh hs4("Le Van D", 7.5, 9, -10);
  /// "HS: Nguyen Van A, MS: 23120001, DTB: 7.53"
  hs1.In(cout);
  cout << endl;

  hs2.In(cout);
  cout << endl;

  hs3.In(cout);
  cout << endl;

  hs4.In(cout);
  cout << endl;

  cout << "Hoc sinh co diem TB cao nhat:" << endl;
  HocSinh::HSDiemTBCaoNhat().In(cout);
  cout << endl;

  hs1.~HocSinh();
  hs2.~HocSinh();
  hs3.~HocSinh();
  hs4.~HocSinh();

  system("pause");
  return 0;
}

void HocSinh::CapnhatMAX() {
  if (Max == nullptr || Max->Diem_TB < this->Diem_TB) Max = this;
}
HocSinh::HocSinh() {
  HoTen = nullptr;
  MSSV++;
  Toan = Van = Anh = 0;
  SetTB();
  CapnhatMAX();
}
HocSinh::HocSinh(const char* _HoTen) {
  int len = strlen(_HoTen);
  HoTen = new char[len + 1];
  strcpy(HoTen, _HoTen);
  MSSV++;
  Toan = Van = Anh = 0;
  SetTB();
  CapnhatMAX();
}
HocSinh::HocSinh(float _toan, float _Van, float _Anh) {
  HoTen = new char[8];
  strcpy(HoTen, "*******");
  MSSV++;
  Toan = _toan < 0 ? 0 : _toan;
  Van = _Van < 0 ? 0 : _Van;
  Anh = _Anh < 0 ? 0 : _Anh;
  SetTB();
  CapnhatMAX();
}
HocSinh::HocSinh(const char* _HoTen, float _toan, float _Van, float _Anh) {
  int len = strlen(_HoTen);
  HoTen = new char[len + 1];
  strcpy(HoTen, _HoTen);
  MSSV++;
  Toan = _toan < 0 ? 0 : _toan;
  Van = _Van < 0 ? 0 : _Van;
  Anh = _Anh < 0 ? 0 : _Anh;
  SetTB();
  CapnhatMAX();
}
HocSinh::~HocSinh() { delete[] HoTen; }

void HocSinh::DatHoTen(const char* _HoTen) {
  int len = strlen(_HoTen);
  HoTen = new char[len + 1];
  strcpy(HoTen, _HoTen);
}
void HocSinh::GanDiem(float _toan, float _Van, float _Anh) {
  Toan = _toan < 0 ? 0 : _toan;
  Van = _Van < 0 ? 0 : _Van;
  Anh = _Anh < 0 ? 0 : _Anh;
  SetTB();
  CapnhatMAX();
}
void HocSinh::SetTB() { Diem_TB = (float)(Toan + Van + Anh) / (float)3; }

HocSinh HocSinh::HSDiemTBCaoNhat() { return *Max; }