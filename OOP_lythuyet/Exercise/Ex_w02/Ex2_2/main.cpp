#include "lib.h"
#include "lib.cpp"

int main(){
    int count = 0;

    cout << "test constructor: " << endl;
    Array<int> arr1;
    arr1.setOrder(++count);
    cout << "Array with length = 0: ";
    arr1.output();
    cout << endl;

    Array<int> arr2(5);
    arr2.setOrder(++count);
    cout << "Array with length = 5 and all elements = 0: ";
    arr2.output();
    cout << endl;

    int a[] = {1, 2, 3};
    int length_of_temp = sizeof(a)/sizeof(a[0]);
    Array<int> arr3(a,length_of_temp);
    arr3.setOrder(++count);
    cout << "Array with a[] = {1, 2, 3}: ";
    arr3.output();
    cout << endl;

    Array<int> arr4(arr3);
    arr4.setOrder(++count);
    cout << "Array with from another object of Array: ";
    arr4.output();
    cout << endl;

    Array<int> arr5;
    arr5.setOrder(++count);
    arr5.input();
    arr5.output();
    cout << endl;
    
    
    int b[] = {4, 7, 5, 6, 9, 10};
    int length_of_b = sizeof(b)/sizeof(b[0]);
    Array<int> arr6(b,length_of_b);
    arr6.setOrder(++count);
    cout << "All elememts of arr6: ";
    arr6.output();
    cout << "size of arr6: " << arr6.getSize() << endl;
    cout << "4th element of arr6: " << arr6.getElement(4) << endl;
    cout << "Update size arr6 with length = 8" << endl;
    arr6.setSize(8);
    cout << "Size of arr6 after update: " << arr6.getSize() << endl;
    cout << "Update arr6 element with 2 and 8" << endl;
    arr6.setElement(6, 2);
    arr6.setElement(7, 8);
    cout << "All elements of arr6 after update: ";
    arr6.output();
    cout << "Index of 6 in arr6: " << arr6.find(6) << endl;
    cout << "Index of 1 in arr6: " << arr6.find(1) << endl;
    arr6.sortArray();
    cout << "Arr6 after sort: ";
    arr6.output();
    cout << endl;
    
    cout << "Delete memory: "<< endl;
    arr1.~Array();
    arr2.~Array();
    arr3.~Array();
    arr4.~Array();
    arr5.~Array();
    arr6.~Array();
    
    // Array <Fraction> arr2;
    // arr2.setOrder(++count);
    // Fraction b = arr2.getElement(5);
    // b.output();
    // arr2.~Array();
    // return 0;
}