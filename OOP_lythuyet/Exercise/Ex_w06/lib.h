#include <iostream>
#pragma once
using namespace std;

class Array
{
private:
    int size;
    int *arr;

public:
    ~Array();
    Array(int size);
    // Array(int a[], int n);
    Array(int *a, int n);
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

class HistogramArray : public Array
{
private:
    int *histogram;
    int histsize;

public:
    void computeHist();
    HistogramArray() = default;
    HistogramArray(int *a, int n);
    HistogramArray(int size_arr, int *a, int n);
    HistogramArray(const HistogramArray &a);
    ~HistogramArray()
    {
        delete[] histogram;
    }

    void displayHist();
    HistogramArray &operator=(const HistogramArray &);
};
