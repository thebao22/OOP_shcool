#include "lib.h"
#include "lib.cpp"

int main()
{
    cout << fixed << setprecision(0);
    cout << "--- BAT DAU CHUONG TRINH (KHONG VIRTUAL) ---" << endl;

    Bank *TBCB = new Bank("TBCB");
    Client *minh = new Client("Minh");
    TBCB->InsertClient(minh);

    MainAccount *tkMinh = new MainAccount("TK_MINH_999", 5000000);
    minh->InsertMainAcc(tkMinh);

    SubAccount *tkLinh = new SubAccount("TK_LINH_111", tkMinh);
    minh->InsertSubAcc(tkLinh);

    cout << "\n--- GIAO DICH QUA TK LINH ---" << endl;
    SubAccount *p_tkLinh = minh->getSubAccount("TK_LINH_111");

    if (p_tkLinh)
    {
        cout << "\n--- Linh rut 1.500.000 (Lan 1) ---" << endl;
        p_tkLinh->with_draw(1500000);
        cout << "So du TK Chinh hien tai: " << p_tkLinh->getBalance() << endl;

        cout << "\n--- Linh rut 1.000.000 (Lan 2) ---" << endl;
        p_tkLinh->with_draw(1000000);
        cout << "So du TK Chinh hien tai: " << p_tkLinh->getBalance() << endl;

        cout << "\n--- Linh rut 500.000 (Lan 3) ---" << endl;
        p_tkLinh->with_draw(500000);
        cout << "So du TK Chinh hien tai: " << p_tkLinh->getBalance() << endl;

        cout << "\n--- Linh nap 200.000 ---" << endl;
        p_tkLinh->deposit(200000);
        cout << "So du TK Chinh hien tai: " << p_tkLinh->getBalance() << endl;
    }

    cout << "\n--- KET THUC CHUONG TRINH ---" << endl;
    delete TBCB;

    return 0;
}