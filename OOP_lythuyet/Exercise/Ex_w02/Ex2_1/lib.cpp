#include "lib.h"

Fraction Fraction::add(Fraction p){
    Fraction sum;
    sum.Num = Num * p.Denom + Denom * p.Num;
    sum.Denom = Denom * p.Denom;
    return sum;
}
void Fraction::output() {
    if(Denom == 1) cout << Num << endl;
    else cout << Num << "/" << Denom << endl;
}
int Fraction::getNum() {
    return Num;
}
int Fraction::getDenom() {
    return Denom;
}
void Fraction::setDenom(int value){
    Denom = value;
}
void Fraction::setNum(int value){
    Num = value;
}
void Fraction::input(){
    cin >> Num >> Denom;
    if (Denom == 0) {
        cout << "phan so khong hop le moi nhap lai: ";
        input();
    }
}
int Fraction::compare(Fraction p){
    if(Num * p.Denom < p.Num * Denom) return -1;
    else if(Num * p.Denom > p.Num * Denom) return 1;
    else return 0;
}
void Fraction::reduce(){
    int a = Num;
    int b = Denom;
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;  
    }
    Num /= a;
    Denom /= a;
}
Fraction Fraction::inverse(){
    Fraction p;
    p.Num = Denom;
    p.Denom = Num;
    return p;
}
Fraction::Fraction(){
    this -> Num = 0;
    this -> Denom = 1;
}
Fraction::Fraction(const int a){
    this -> Num = a;
    this -> Denom = 1;
}
Fraction::Fraction(const Fraction& a){
    this -> Num = a.Num;
    this -> Denom = a.Denom;
}
Fraction::Fraction(int a, int b) : Num(a), Denom(b) {}

Fraction::Fraction(string a) {
    this -> Num = a[0] - '0';
    this -> Denom = a[2] - '0';
}