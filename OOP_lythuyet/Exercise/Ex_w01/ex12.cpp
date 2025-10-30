#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;

//Ascending
void ascending(int array[], int n){
    for(int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) 
            if (array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

//Descending
void descending(int array[], int n){
    for(int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) 
            if (array[i] < array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

typedef void (*Operator) (int array[], int);
void sortArray(int array[], int n, Operator p){
    p(array,n);
}

void print_array(int a[], int n) {
    cout << "Elements of array after sort: \n";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int c[] = {1, 3, 5, 7, 9, 2, 6, 4, 8};
    int n = sizeof(c)/sizeof(c[0]);

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