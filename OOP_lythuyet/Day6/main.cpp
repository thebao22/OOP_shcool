#include "lib.h"
#include "Day6.cpp"
int main()
{
    int a[] = {1, 1, 3, 4, 2, 1, 1, 5, 8, 6};
    int n = sizeof(a) / sizeof(a[0]);
    Histogram obj(a, n);
    obj.display();
    a[4] = 8;
    obj.compute();
    cout << endl;
    obj.display();
}