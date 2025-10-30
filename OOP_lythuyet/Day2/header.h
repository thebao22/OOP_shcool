#pragma once
#include <iostream>
#include <string>
using namespace std;

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