#include "lib.h"
#include "lib.cpp"
int main() {
    cout << "test cac ham add, input, output, getNum, getDenom." << endl;
    Fraction a;
    Fraction b(1, 6);
    cout << "Nhap phan so a (Num Denom): ";
    a.input();
    Fraction p = a.add(b);
    p.output();
    cout << p.getNum() << endl;
    cout << p.getDenom() << endl;

    cout << endl << "test cac constructor" << endl;
    Fraction ps1 = Fraction();
    Fraction ps2(5, 6);
    Fraction ps3(5);
    Fraction ps4("4/5");
    Fraction ps5(ps2);
    
    ps1.output();
    ps2.output();
    ps3.output();
    ps4.output();
    ps5.output();

    cout << endl << "test ham setNum, setDenom" << endl;
    Fraction ps6 ("6/7");
    cout << "Phan so truoc khi dat lai mau va tu: ";
    ps6.output();
    ps6.setDenom(4);
    ps6.setNum(1);
    cout << "Phan so sau khi dat lai mau va tu: ";
    ps6.output();
    
    cout << endl << "test ham inverse, compare" << endl;
    Fraction ps7 = ps6.inverse();
    cout << "Phan so nghich dao cua 1/4: " << endl;
    ps7.output();
    cout << "ket qua so sanh: (1: lon hon, -1: nho hon:, 0: bang nhau): ";
    cout << ps7.compare(ps6) << endl;

    cout << endl << "test ham reduce" << endl;
    Fraction ps8(45,54);
    cout << "Phan so truoc khi rut gon: ";
    ps8.output();
    ps8.reduce();
    cout << "Phan so sau khi rut gon: ";
    ps8.output();
}