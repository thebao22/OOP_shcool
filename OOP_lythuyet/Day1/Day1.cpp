#include <stdio.h>
#include <iostream>
#define MAXARRAY 100

template <typename T1, typename T2>
auto add (T1 a, T2 b) {
    return a + b;
}

template <typename T1, typename T2>
auto mul (T1 a, T2 b) {
    return a * b;
}

// typedef int (*Operator) (int, int); cal(int a, int b, Operator p);
// using Operator = int (*) (int, int); cal(int a, int b, Operator p);
typedef int (*Operator) (int, int);
int cal(int a, int b, Operator p) {
    a = a * a;
    b= b * b;
    return p(a,b);
}
template <typename T>
void read_sort_array(T a[], int &n) {
    cout << "enter number of elements = "
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "nhap [" <<i<<"] = ";
        cin >> a[i];
    }
}
template <typename T>
void print_array(T a[], int n) {
    cout << "Elements of array: \n"
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

//ex1
template <typename T>
void sortArray(T a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; i++)
            if (a[i] > a[j]) {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main() {
    double a[MAXARRAY];
    int n;
    read_sort_array(a,n);
    sortArray(a,n);
    print_array(a,n);
}
