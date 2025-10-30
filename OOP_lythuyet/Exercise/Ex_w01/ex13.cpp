#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;

//Ascending
template <typename T>
void ascending(T array[], int n){
    for(int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) 
            if (array[i] > array[j]){
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

//Descending
template <typename T>
void descending(T array[], int n){
    for(int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) 
            if (array[i] < array[j]){
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

template <typename T>
using Operator = void (*) (T array[], int);

template <typename T>
void sortArray(T array[], int n, Operator<T> p){
    p(array,n);
}

template <typename T>
void print_array(T a[], int n) {
    cout << "Elements of array after sort: \n";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n; 

    //test case 1: char[].
    cout << "test case 1: char[]" << endl;
    char a[] = {'a', 'c', 'd', 'b', 'f', 'h', 'g', 'i'};
    n = sizeof(a)/sizeof(a[0]);
    cout << "Elements of array before sort: \n";
    print_array(a,n);

    cout << "\nSort Ascending: "<< endl;
    sortArray(a,n,ascending);
    print_array(a,n);

    cout << "\nSort Descending:" << endl;
    sortArray(a,n,descending);
    print_array(a,n);

    //test case 2: float[].
    cout << "\ntest case 2: float[]" << endl;
    float b[] = {1.2f, 3.6f, 2.1f, 2.4f, 1.5f};
    n = sizeof(b)/sizeof(b[0]);
    cout << "Elements of array before sort: \n";
    print_array(b,n);

    cout << "\nSort Ascending: "<< endl;
    sortArray(b,n,ascending);
    print_array(b,n);

    cout << "\nSort Descending:" << endl;
    sortArray(b,n,descending);
    print_array(b,n);

    //test case 3: int[].
    int c[] = {1, 3, 5, 7, 9, 2, 6, 4, 8};
    n = sizeof(c)/sizeof(c[0]);

    cout << "Elements of array before sort: \n";
    print_array(c,n);

    cout << "\nSort Ascending: "<< endl;
    sortArray(c,n,ascending);
    print_array(c,n);

    cout << "\nSort Descending:" << endl;
    sortArray(c,n,descending);
    print_array(c,n);

    return 0;
}