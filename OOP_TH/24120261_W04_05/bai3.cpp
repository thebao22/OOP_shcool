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

    Cstring &operator++();
    Cstring operator++(int);
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
Cstring::~Cstring()
{
    delete[] _mang;
}
Cstring &Cstring::operator++()
{
    if (_mang != nullptr)
        _mang[strlen(_mang) - 1]++;
    return *this;
}
Cstring Cstring::operator++(int)
{
    Cstring temp = *this;
    if (_mang != nullptr)
    {
        _mang[strlen(_mang) - 1]++;
    }
    return temp;
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
    cout << cs1 << endl;
    cout << "cs1++" << cs1++ << endl
         << cs1 << endl;
    cout << "++ ++cs1: " << ++ ++cs1 << endl
         << cs1 << endl;
    system("pause");
    return 0;
}