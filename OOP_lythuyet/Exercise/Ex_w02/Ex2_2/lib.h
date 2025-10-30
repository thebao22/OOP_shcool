#pragma once
#include <iostream>
using namespace std;
template <class T>
class Array{
    private:
        T *arr;
        int size;
        int number; // get the order of arr;

    public:
        Array();
        Array(int size);
        Array(T a[], int n);
        Array(const Array &temp);
        ~Array();
        void input();
        void output();
        T getSize();
        void setSize(int size);
        T getElement(int index);
        void setElement(int index, T value);
        T find(T value);
        void sortArray();
        void setOrder(int value);
};


//Class Fraction    
class Fraction{
    private:
        int Num;
        int Denom;
    public:
        //khoi constructor: 
        Fraction();
        Fraction(int a, int b);
        Fraction(const int a);
        Fraction(const Fraction& a);
        Fraction(string a);

        //function:
        int getDenom();
        int getNum();        
        void setNum(int value);
        void setDenom(int value);
        void input();
        Fraction add(Fraction p);
        Fraction inverse();
        void output();
        void reduce();
        int compare(Fraction p);

        //destructor
        ~ Fraction();
};
    