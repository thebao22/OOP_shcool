#include <iostream>
#include <cstring>
#include <exception>
using namespace std;

class Cstring
{
private:
    char *_mang;

public:
    Cstring();
    Cstring(const char *);
    Cstring(const Cstring &);
    ~Cstring();

    char &operator[](const int &);
    Cstring &operator=(const Cstring &);
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
Cstring::Cstring(const Cstring &temp) : Cstring(temp._mang)
{
    cout << "The copy constructor was call." << endl;
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
Cstring &Cstring::operator=(const Cstring &_string)
{
    if (_mang != nullptr)
        delete[] _mang;
    _mang = new char[strlen(_string._mang) + 1];
    strcpy(_mang, _string._mang);
    return *this;
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
    cout << "cs2(cs1)" << endl;
    Cstring cs2(cs1);
    cs2[iN] = '2';
    cout << " cs3 = cs1" << endl;
    Cstring cs3 = cs1;
    cs3[iN] = '3';
    cout << cs1 << endl
         << cs2 << endl
         << cs3 << endl;
    cout << " cs3 = cs2" << endl;
    cs3 = cs2;
    cout << cs3 << endl;
    system("pause");
    return 0;
}