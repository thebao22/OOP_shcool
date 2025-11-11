

#include "Linkedlist.h"

using namespace std;

class SoNguyenLon
{
private:
    Linkedlist<int> value;
    int size = 0;

    void remove_leading_zeros()
    {
        while (size > 1 && value[0] == 0)
        {
            Node<int> *node = value.removeHead();
            delete node;
            size--;
        }
    }

    void clear()
    {
        while (size > 0)
        {
            Node<int> *node = value.removeHead();
            delete node;
            size--;
        }
        value = Linkedlist<int>();
    }

public:
    SoNguyenLon();
    SoNguyenLon(const long long &);
    SoNguyenLon(int, int);

    bool operator>=(const SoNguyenLon &) const;

    SoNguyenLon operator+(const SoNguyenLon &) const;
    SoNguyenLon operator-(const SoNguyenLon &) const;
    SoNguyenLon operator*(const SoNguyenLon &) const;
    SoNguyenLon &operator=(const SoNguyenLon &);

    friend SoNguyenLon operator+(const long long &, const SoNguyenLon &snl);
    friend SoNguyenLon operator-(const long long &, const SoNguyenLon &snl);
    friend SoNguyenLon operator+(const SoNguyenLon &snl, const long long &);
    friend SoNguyenLon operator-(const SoNguyenLon &snl, const long long &);
    friend ostream &operator<<(ostream &out, const SoNguyenLon &);
};

SoNguyenLon::SoNguyenLon()
{
    value.addHead(0);
    size = 1;
}
SoNguyenLon::SoNguyenLon(const long long &_value)
{
    size = 0;
    if (_value == 0)
    {
        value.addHead(0);
        size = 1;
        return;
    }

    long long temp = _value;

    long long divisor = 1;
    while (temp / divisor >= 10)
    {
        divisor *= 10;
    }

    while (divisor > 0)
    {

        int digit = temp / divisor;

        value.addTail(digit);
        size++;

        temp = temp % divisor;
        divisor /= 10;
    }
}
SoNguyenLon::SoNguyenLon(int num, int _size)
{
    if (num < 0 || num > 9)
        num = 0;

    size = _size;
    if (size <= 0)
    {
        value.addHead(0);
        size = 1;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        value.addTail(num);
    }
}
bool SoNguyenLon::operator>=(const SoNguyenLon &other) const
{
    if (size > other.size)
        return true;
    if (size < other.size)
        return false;
    for (int i = 0; i < size; i++)
    {
        if (value[i] != other.value[i])
            return value[i] > other.value[i];
    }
    return true;
}
SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon &other) const
{
    SoNguyenLon result;
    result.clear();
    result.size = 0;

    int i = size - 1;
    int j = other.size - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry)
    {
        int num1 = (i >= 0) ? value[i] : 0;
        int num2 = (j >= 0) ? other.value[j] : 0;
        int sum = num1 + num2 + carry;
        result.value.addHead(sum % 10);
        result.size++;
        carry = sum / 10;
        i--, j--;
    }

    result.remove_leading_zeros();
    return result;
}

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon &other) const
{
    if (!(*this >= other))
    {
        return SoNguyenLon(0);
    }
    SoNguyenLon result;
    result.clear();
    result.size = 0;

    int i = size - 1;
    int j = other.size - 1;
    int carry = 0;
    while (i >= 0)
    {
        int num1 = (i >= 0) ? value[i] : 0;
        int num2 = (j >= 0) ? other.value[j] : 0;
        int sub = num1 - num2 - carry;
        if (sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result.value.addHead(sub);
        result.size++;
        i--, j--;
    }
    result.remove_leading_zeros();
    return result;
}

SoNguyenLon SoNguyenLon::operator*(const SoNguyenLon &other) const
{
    int n = size;
    int m = other.size;
    SoNguyenLon result(0, n + m);

    for (int i = n - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            int mul = value[i] * other.value[j] + result.value[i + j + 1] + carry;
            result.value[i + j + 1] = mul % 10;
            carry = mul / 10;
        }
        result.value[i] += carry;
    }

    result.remove_leading_zeros();
    return result;
}

SoNguyenLon operator+(const long long &_value, const SoNguyenLon &snl)
{
    SoNguyenLon temp(_value);
    return temp + snl;
}
SoNguyenLon operator-(const long long &_value, const SoNguyenLon &snl)
{
    SoNguyenLon temp(_value);
    return temp - snl;
}
SoNguyenLon operator+(const SoNguyenLon &snl, const long long &_value)
{
    SoNguyenLon temp(_value);
    return temp + snl;
}
SoNguyenLon operator-(const SoNguyenLon &snl, const long long &_value)
{
    SoNguyenLon temp(_value);
    return snl - temp;
}
SoNguyenLon &SoNguyenLon::operator=(const SoNguyenLon &other)
{
    if (this == &other)
        return *this;

    this->clear();
    this->value = Linkedlist<int>();

    size = 0;
    for (int i = 0; i < other.size; i++)
    {
        value.addTail(other.value[i]);
        size++;
    }
    return *this;
}
ostream &operator<<(ostream &out, const SoNguyenLon &snl)
{
    for (int i = 0; i < snl.size; i++)
    {
        out << snl.value[i];
    }
    return out;
}
int main()
{
    SoNguyenLon snl1;
    SoNguyenLon snl2(44667733);
    SoNguyenLon snl3(5, 9);
    SoNguyenLon snl4(7, 30);
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 1098765432 - snl2;
    SoNguyenLon snl7 = snl4 - snl3 + 123456789;
    SoNguyenLon snl8 = snl2 * snl3;

    cout << snl1 << endl
         << snl2 << endl
         << snl3 << endl;
    cout << snl4 << endl
         << snl5 << endl
         << snl6 << endl;
    cout << snl7 << endl
         << snl8 << endl
         << endl;
    system("pause");
    return 0;
}