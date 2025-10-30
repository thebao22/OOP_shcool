#include <iostream>
using namespace std;

class MangSoNguyen
{
private:
    int *arr;
    int size;

public:
    MangSoNguyen();
    MangSoNguyen(int size);
    MangSoNguyen(int a[], int n);
    MangSoNguyen(const MangSoNguyen &temp);
    ~MangSoNguyen();
    void xuat();
};

MangSoNguyen::MangSoNguyen()
{
    size = 0;
    arr = new int[size];
}
MangSoNguyen::MangSoNguyen(int size)
{
    this->size = size;
    arr = new int[size]();
}
MangSoNguyen::MangSoNguyen(int a[], int n)
{
    this->size = n;
    arr = new int[size];
    for (int i = 0; i < n; i++)
        arr[i] = a[i];
}
MangSoNguyen::MangSoNguyen(const MangSoNguyen &temp)
{
    size = temp.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = temp.arr[i];
}
MangSoNguyen::~MangSoNguyen()
{
    delete[] arr;
}
void MangSoNguyen::xuat()
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    MangSoNguyen msn1;
    msn1.xuat();
    MangSoNguyen msn2(5);
    msn2.xuat();
    int arr[10];
    for (int i = 0; i < 8; i++)
    {
        arr[i] = i * i;
    }
    MangSoNguyen msn3(arr, 8);
    msn3.xuat();
    MangSoNguyen msn4(msn3);
    msn4.xuat();

    //giai phong bo nho
    msn1.~MangSoNguyen();
    msn2.~MangSoNguyen();
    msn3.~MangSoNguyen();
    msn4.~MangSoNguyen();

    return 0;
}