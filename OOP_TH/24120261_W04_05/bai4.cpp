#include "Linkedlist.h"

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
       throw std::out_of_range("Index out of range");

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

int main() {
    srand((unsigned int)time(NULL));
    const int maxV = 1000, iTest = 2;
    int n = 5 + rand() % 10;

    Linkedlist<int> ll;

    for (int i = 0; i < n; i++) {
        if (rand() % 2 == 0)
            ll.addHead(rand() % maxV);
        else
            ll.addTail(rand() % maxV + maxV);
    }

    cout << ll << endl;

    ll[iTest] = -123;
    ll[iTest + 2] = 9876;

    ll.removeHead();
    ll.removeTail();

    cout << "\nSau thay doi:\n";
    cout << ll << endl;

    Linkedlist<string> llCS;
    llCS.addTail("cstring-1");
    llCS.addTail("cstring-2");
    llCS.addTail("cstring-3");

    cout << "List CString: " << llCS << endl;

    llCS[iTest] = "new CString";
    cout << "List CString changed:\n" << llCS << endl;

    system("pause");
    return 0;
}