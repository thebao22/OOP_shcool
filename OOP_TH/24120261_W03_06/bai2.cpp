#include <iostream>
using namespace std;

class SoPhuc
{
private:
    int _thuc, _ao;

public:
    SoPhuc();
    SoPhuc(const int &, const int &);
    SoPhuc(const int &);
    SoPhuc operator+(const SoPhuc &);
    void operator<<(ostream &);
};

SoPhuc::SoPhuc() : _thuc(0), _ao(0) {}
SoPhuc::SoPhuc(const int &t, const int &a)
{
    _thuc = t;
    _ao = a;
}
SoPhuc::SoPhuc(const int &t) : SoPhuc()
{
    _thuc = t;
}
SoPhuc SoPhuc::operator+(const SoPhuc &sp)
{
    SoPhuc temp = *this;
    temp._thuc += sp._thuc;
    temp._ao += sp._ao;
    return temp;
}
void SoPhuc::operator<<(ostream &out)
{
    out << _thuc;
    if (_ao != 0)
    {
        out << ((_ao < 0) ? "-" : " +") << _ao << "*i";
    }
}
int main()
{
    SoPhuc sp1(3, 5);
    SoPhuc sp3 = sp1 + 10;
    sp1.operator<<(cout);
    cout << endl;
    sp3.operator<<(cout);
    cout << endl;
    system("pause");
    return 0;
}