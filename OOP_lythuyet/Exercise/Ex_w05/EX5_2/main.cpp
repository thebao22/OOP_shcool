#include "lib.h"
#include "lib.cpp"


int main()
{
    Client c1("Nguyen Van A", "C001");
    SavingAccount sa(c1, "ACC1001", 1000.0, 0.05);

    cout << "=== Thong tin ban dau ===" << endl;
    sa.display();

    sa.deposit(500);
    sa.withdraw(200);
    sa.applyInterestRate();

    cout << "\n=== Sau cac giao dich ===" << endl;
    sa.display();

    return 0;
}
