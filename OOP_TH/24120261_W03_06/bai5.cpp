#include <algorithm> // Thêm thư viện để dùng std::max
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int do_dai(long long);

class SoNguyenLon
{
private:
    char *value;
    static SoNguyenLon MAX;
    void CapnhatMAX();

public:
    SoNguyenLon();
    SoNguyenLon(const char *);
    SoNguyenLon(int, int);
    SoNguyenLon(long long);
    SoNguyenLon(int);

    ~SoNguyenLon();

    SoNguyenLon(const SoNguyenLon &other);
    SoNguyenLon &operator=(const SoNguyenLon &other);

    SoNguyenLon operator-(SoNguyenLon);
    SoNguyenLon operator+(SoNguyenLon);
    friend SoNguyenLon operator+(long long, SoNguyenLon);
    friend SoNguyenLon operator-(long long, SoNguyenLon);

    static SoNguyenLon SNLMax();
    int SosanhSoNguyenLon(SoNguyenLon);

    friend ostream &operator<<(ostream &out, SoNguyenLon snl);
};
int do_dai(long long value)
{
    if (value == 0)
        return 1;
    int count{};
    while (value > 0)
    {
        value /= 10;
        count++;
    }
    return count;
}
SoNguyenLon SoNguyenLon::MAX;

void SoNguyenLon::CapnhatMAX()
{
    if (this->SosanhSoNguyenLon(MAX) > 0)
    {
        MAX = *this;
    }
}

SoNguyenLon::SoNguyenLon()
{
    value = new char[2];
    strcpy(value, "0");
    CapnhatMAX();
}
SoNguyenLon::SoNguyenLon(const char *_value)
{
    int len = strlen(_value);
    value = new char[len + 1];
    strcpy(value, _value);
    CapnhatMAX();
}
SoNguyenLon::SoNguyenLon(int number, int sl)
{
    if (number < 0 || number > 9)
        number = 0;
    char h = number + '0';
    value = new char[sl + 1];
    memset(value, h, sl);
    value[sl] = '\0';
    CapnhatMAX();
}
SoNguyenLon::SoNguyenLon(long long a)
{
    int len = do_dai(a);
    value = new char[len + 1];
    value[len] = '\0';
    for (int i = len - 1; i >= 0; --i)
    {
        value[i] = (a % 10) + '0';
        a /= 10;
    }
}
SoNguyenLon::SoNguyenLon(int a)
{
    int len = do_dai(a);
    value = new char[len + 1];
    value[len] = '\0';
    for (int i = len - 1; i >= 0; --i)
    {
        value[i] = (a % 10) + '0';
        a /= 10;
    }
}
SoNguyenLon::~SoNguyenLon() { delete[] value; }

SoNguyenLon::SoNguyenLon(const SoNguyenLon &other)
{
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}

SoNguyenLon &SoNguyenLon::operator=(const SoNguyenLon &other)
{
    if (this != &other)
    {
        delete[] value;
        value = new char[strlen(other.value) + 1];
        strcpy(value, other.value);
    }
    return *this;
}

int SoNguyenLon::SosanhSoNguyenLon(SoNguyenLon other)
{
    int len1 = strlen(value);
    int len2 = strlen(other.value);

    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return 0;

    int cmp = strcmp(value, other.value);
    if (cmp > 0)
        return 1;
    if (cmp < 0)
        return 0;

    return -1;
}

SoNguyenLon SoNguyenLon::operator-(SoNguyenLon other)
{
    if (SosanhSoNguyenLon(other) <= 0)
        return SoNguyenLon("0");

    int len1 = strlen(value);
    int len2 = strlen(other.value);
    int max_len = (len1 > len2) ? len1 : len2;

    char *result = new char[max_len + 1];
    result[max_len] = '\0';

    int carry = 0;
    int i = len1 - 1, j = len2 - 1, k = max_len - 1;

    while (i >= 0 || j >= 0)
    {
        int digit1 = (i >= 0) ? value[i--] - '0' : 0;
        int digit2 = (j >= 0) ? other.value[j--] - '0' : 0;
        int sub = digit1 - digit2 - carry;
        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result[k--] = sub + '0';
    }

    int start = 0;
    while (result[start] == '0' && result[start + 1] != '\0')
    {
        start++;
    }

    SoNguyenLon temp(result + start);
    delete[] result;
    return temp;
}

SoNguyenLon SoNguyenLon::operator+(SoNguyenLon other)
{
    int len1 = strlen(value);
    int len2 = strlen(other.value);
    int max_len = (len1 > len2 ? len1 : len2);

    // +1 để dự trù nếu có nhớ cuối cùng (carry)
    char *result = new char[max_len + 2];
    result[max_len + 1] = '\0';

    int i = len1 - 1;
    int j = len2 - 1;
    int k = max_len;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = (i >= 0) ? value[i--] - '0' : 0;
        int digit2 = (j >= 0) ? other.value[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // Nếu còn nhớ, thêm vào đầu
    if (k != 0)
        result[0] = carry + '0';
    else
        for (int m = 0; m <= max_len; ++m)
            result[m] = result[m + 1]; // Dịch trái để bỏ phần trống đầu

    SoNguyenLon temp(result);
    delete[] result;
    return temp;
}
SoNguyenLon operator+(long long a, SoNguyenLon snl)
{
    SoNguyenLon temp(a);
    return temp + snl;
}
SoNguyenLon operator-(long long a, SoNguyenLon snl)
{
    SoNguyenLon temp(a);
    return temp - snl;
}
ostream &operator<<(ostream &out, SoNguyenLon snl)
{
    out << snl.value;
    return out;
}
SoNguyenLon SoNguyenLon::SNLMax() { return MAX; }
int main()
{
    SoNguyenLon snl1;
    SoNguyenLon snl2(1234567);
    SoNguyenLon snl3(3, 14);
    SoNguyenLon snl4(9, 20);
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 45678910 - snl2;
    SoNguyenLon snl7 = snl4 - snl3 + 123456789;

    cout << snl1 << endl
         << snl2 << endl
         << snl3 << endl;
    cout << snl4 << endl
         << snl5 << endl
         << snl6 << endl;
    cout << snl7 << endl
         << endl;

    cout << "SoNguyenLon Max:" << endl;
    cout << SoNguyenLon::SNLMax() << endl;
    system("pause");
    return 0;
}