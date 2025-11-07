#include <iostream>
#pragma once
using namespace std;

// constructor calling in Inheritance
// Example
// Neu khong co ham constructor nao thi ham default se dc tao tu dong
// Nguoc lai khi da co it nhat mot constructor thi ham default se k dc tao tu dong
// destructor()
// k can goi nhieu ham huy
//  tao ham main de test.

class Array
{
private:
    double a;
    int b;
    int size;
    int *arr;

public:
    ~Array();
    Array(int size);
    Array(int a[], int n);
    Array(const Array &temp);
    Array();

    void input();
    void output();

    int getSize();
    void setSize(int newSize);

    int getElement(int index);
    void setElement(int index, int value);

    int find(int value);
    int findmax();
    void sortArray();
    void setOrder(int value);

    Array operator+(const Array &);
    Array operator+=(const Array &);
    Array &operator=(const Array &);
    int &operator[](int index);
    const int &operator[](int index) const;
    operator int *const();
    friend ostream &operator<<(ostream &out, const Array &);
    friend istream &operator>>(istream &in, Array &);
};

class Histogram : public Array
{
private:
    int *histogram;
    int histsize;

public:
    void compute();
    Histogram() = default;
    Histogram(int a[], int n);
    Histogram(const Histogram &a);
    ~Histogram()
    {
        delete[] histogram;
    }

    void display();
    Histogram &operator=(const Histogram &);
};
