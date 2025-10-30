#include <iostream>
using namespace std;

class Fraction {
private:
    int num , denom;
   
    
public:
    Fraction();
    ~Fraction();
    static void printCount();
    static int count;
};

Fraction::Fraction(){
   count++;
}

Fraction::~Fraction(){
    count--;
}

void Fraction::printCount(){
    cout << "Total objects: " << count << endl;
}

int Fraction::count = 0;

int main() {
    Fraction frac1;
    Fraction *frac2 = new Fraction();
    frac1.printCount();
    delete frac2;
    //Fraction::printCount();
    frac1.printCount();
    cout << Fraction::count;
}