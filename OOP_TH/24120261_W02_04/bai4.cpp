#include <algorithm>  // Thêm thư viện để dùng std::max
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class SoNguyenLon {
 private:
  char* value;
  static SoNguyenLon MAX;
  void CapnhatMAX();

 public:
  SoNguyenLon();
  SoNguyenLon(const char*);
  SoNguyenLon(int, int);
  SoNguyenLon(long long);
  SoNguyenLon(int);

  ~SoNguyenLon();

  SoNguyenLon(const SoNguyenLon& other);
  SoNguyenLon& operator=(const SoNguyenLon& other);

  SoNguyenLon Tru(SoNguyenLon);
  SoNguyenLon Cong(SoNguyenLon);
  int SosanhSoNguyenLon(SoNguyenLon);
  static SoNguyenLon HieuVoiHangSo(SoNguyenLon, SoNguyenLon);
  static SoNguyenLon SNLMAX();
  void In(ostream& out) { out << value; }
};

SoNguyenLon SoNguyenLon::MAX;

void SoNguyenLon::CapnhatMAX() {
  if (this->SosanhSoNguyenLon(MAX) > 0) {
    MAX = *this;
  }
}

SoNguyenLon::SoNguyenLon() {
  value = new char[2];
  strcpy(value, "0");
  CapnhatMAX();
}
SoNguyenLon::SoNguyenLon(const char* _value) {
  int len = strlen(_value);
  value = new char[len + 1];
  strcpy(value, _value);
  CapnhatMAX();
}
SoNguyenLon::SoNguyenLon(int number, int sl) {
  if (number < 0 || number > 9) number = 0;
  char h = number + '0';
  value = new char[sl + 1];
  memset(value, h, sl);
  value[sl] = '\0';
  CapnhatMAX();
}
SoNguyenLon::SoNguyenLon(long long a) {
  string temp = to_string(a);
  value = new char[temp.size() + 1];
  strcpy(value, temp.c_str());
  CapnhatMAX();
}
SoNguyenLon::SoNguyenLon(int a) {
  string temp = to_string(a);
  value = new char[temp.size() + 1];
  strcpy(value, temp.c_str());
  CapnhatMAX();
}
SoNguyenLon::~SoNguyenLon() { delete[] value; }

SoNguyenLon::SoNguyenLon(const SoNguyenLon& other) {
  value = new char[strlen(other.value) + 1];
  strcpy(value, other.value);
}

SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& other) {
  if (this != &other) {
    delete[] value;
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
  }
  return *this;
}

int SoNguyenLon::SosanhSoNguyenLon(SoNguyenLon other) {
  int len1 = strlen(value);
  int len2 = strlen(other.value);

  if (len1 > len2) return 1;
  if (len1 < len2) return 0;

  int cmp = strcmp(value, other.value);
  if (cmp > 0) return 1;
  if (cmp < 0) return 0;

  return -1;
}

SoNguyenLon SoNguyenLon::Tru(SoNguyenLon other) {
  if (SosanhSoNguyenLon(other) <= 0) return SoNguyenLon("0");

  int len1 = strlen(value);
  int len2 = strlen(other.value);
  int max_len = (len1 > len2) ? len1 : len2;

  char* result = new char[max_len + 1];
  result[max_len] = '\0';

  int carry = 0;
  int i = len1 - 1, j = len2 - 1, k = max_len - 1;

  while (i >= 0 || j >= 0) {
    int digit1 = (i >= 0) ? value[i--] - '0' : 0;
    int digit2 = (j >= 0) ? other.value[j--] - '0' : 0;
    int sub = digit1 - digit2 - carry;
    if (sub < 0) {
      sub += 10;
      carry = 1;
    } else {
      carry = 0;
    }
    result[k--] = sub + '0';
  }

  int start = 0;
  while (result[start] == '0' && result[start + 1] != '\0') {
    start++;
  }

  SoNguyenLon temp(result + start);
  delete[] result;
  return temp;
}

SoNguyenLon SoNguyenLon::Cong(SoNguyenLon other) {
  string s1(value);
  string s2(other.value);
  string str = "";

  int n1 = s1.length(), n2 = s2.length();
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());

  int carry = 0;
  for (int i = 0; i < n1 || i < n2 || carry; i++) {
    int sum = carry + (i < n1 ? s1[i] - '0' : 0) + (i < n2 ? s2[i] - '0' : 0);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }

  reverse(str.begin(), str.end());
  SoNguyenLon temp(str.c_str());
  return temp;
}
SoNguyenLon SoNguyenLon::HieuVoiHangSo(SoNguyenLon a, SoNguyenLon b) {
  SoNguyenLon temp;
  temp = a.Tru(b);
  return temp;
}
SoNguyenLon SoNguyenLon::SNLMAX() { return MAX; }

int main() {
  SoNguyenLon snl1;
  SoNguyenLon snl2("1234567");
  SoNguyenLon snl3(3, 14);
  SoNguyenLon snl4(9, 20);
  SoNguyenLon snl5 = snl3.Tru(snl2);
  SoNguyenLon snl6 = SoNguyenLon::HieuVoiHangSo(45678910, snl2);
  SoNguyenLon snl7 = snl4.Tru(snl3).Cong(123456789);
  snl1.In(cout);
  cout << endl;
  snl2.In(cout);
  cout << endl;
  snl3.In(cout);
  cout << endl;
  snl4.In(cout);
  cout << endl;
  snl5.In(cout);
  cout << endl;
  snl6.In(cout);
  cout << endl;
  snl7.In(cout);
  cout << endl;

  cout << "SoNguyenLon Max:" << endl;
  SoNguyenLon::SNLMAX().In(cout);
  cout << endl;
  system("pause");
  return 0;
}