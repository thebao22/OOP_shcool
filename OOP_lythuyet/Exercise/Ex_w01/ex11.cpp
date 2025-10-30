#include  <stdio.h>
#include <iostream>
#define MAX 100
using namespace std;

//sort function
template <typename T>
void sortArray(T array[], int n){
    for(int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) 
            if (array[i] > array[j]){
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

//print array function
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
    sortArray(a,n);
    print_array(a,n);

    //test case 2: float[].
    cout << "\ntest case 2: float[]" << endl;
    float b[] = {1.2f, 3.6f, 2.1f, 2.4f, 1.5f};
    n = sizeof(b)/sizeof(b[0]);
    sortArray(b,n);
    print_array(b,n);

    //test case 3: int[].
    cout << "\ntest case 3: int[]" << endl;
    int c[] = {1, 3, 5, 7, 9, 2, 6, 4, 8};
    n = sizeof(c)/sizeof(c[0]);
    sortArray(c,n);
    print_array(c,n);
}