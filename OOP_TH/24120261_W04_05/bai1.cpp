#include <iostream>
#include <cstring>
using namespace std;

class Cstring
{
private:
    char *_mang;

public:
    Cstring();
    Cstring(const char *);
    ~Cstring();

    char &operator[](const int &);
    friend ostream &operator<<(ostream &, const Cstring &);
};
Cstring::Cstring()
{
    _mang = nullptr;
}
Cstring::Cstring(const char *_string)
{
    _mang = new char[strlen(_string) + 1];
    strcpy(_mang, _string);
}
Cstring::~Cstring()
{
    delete[] _mang;
}

char &Cstring::operator[](const int &index)
{
    if (index < 0 || index > strlen(_mang))
    {
        throw exception("out of range");
    }
    return _mang[index];
}
ostream &operator<<(ostream &out, const Cstring &_string)
{
    out << _string._mang;
    return out;
}
int main()
{
    const int iN = 2;
    Cstring cs1("conten_cs1");
    cout << cs1 << endl;
    cout << "cs1[" << iN << "] = " << cs1[iN] << endl;
    cs1[iN] = 'N';
    cout << cs1 << endl;
    system("pause");
    return 0;
}