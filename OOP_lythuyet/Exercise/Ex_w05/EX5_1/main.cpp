#include "lib.h"
#include "lib.cpp"

int main() {
    ExchangeStudent ex("Bao", "SV001", 3.8, "88 Nanjing Road", "Shanghai", "China", "Viet Nam", 6);
    ex.display();
    ex.updateDuration(9);
    cout << "\nAfter update:\n";
    ex.display();
    return 0;
}
