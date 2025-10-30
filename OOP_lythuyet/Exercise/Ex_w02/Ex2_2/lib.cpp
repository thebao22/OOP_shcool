#include "lib.h"

template<class T>
Array<T>::Array(){
    size = 0;
    arr = new T[size];
}

template<class T>
Array<T>::Array(int size){
    this->size = size;
    arr = new T[size]();
}

template<class T>
Array<T>::Array(T a[], int n){
    this->size = n;
    arr = new T[size];
    for (int i = 0; i < n; i++)
        arr[i] = a[i];     
}

template<class T>
Array<T>::Array(const Array &temp){
    size = temp.size;
    arr = new T [size];
    for (int i = 0; i < size; i++)
        arr[i] = temp.arr[i];
}

template<class T>
Array<T>::~Array(){
    delete[] arr;
    cout << "Delete memory of arr" << number <<  " success!" << endl;
}

template<class T>
void Array<T>::input(){
    delete[] arr;
    cout << "Enter size of array: ";
    cin >> size;
    arr = new T [size];
    cout << "Enter array elemenets: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];
}

template<class T>
void Array<T>::output(){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template<class T>
T Array<T>::getSize(){
    return size;
}

template<class T>
void Array<T>::setSize(int newSize){
    int* newArr = new T [newSize];
    int minSize = (newSize < size) ? newSize : size;
    for (int i = 0; i < minSize; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    size = newSize;
}

template<class T>
T Array<T>::getElement(int index){
    return arr[index];
}

template<class T>
void Array<T>::setElement(int index, T value){
    arr[index] = value;
}

template<class T>
T Array<T>::find(T value){
    int index{-1};
    for (int i = 0; i < size; i++){
        if (value == arr[i]) 
        {
            index = i;
            break;
        }
    }
    return index;
}

template<class T>
void Array<T>::sortArray(){
    for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
        if (arr[i] > arr[j]) {
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
}

template<class T>
void Array<T>::setOrder(int value){
    number = value;
}

// fraction
Fraction Fraction::add(Fraction p){
    Fraction sum;
    sum.Num = Num * p.Denom + Denom * p.Num;
    sum.Denom = Denom * p.Denom;
    return sum;
}
void Fraction::output() {
    if(Denom == 1) cout << Num << endl;
    else cout << Num << "/" << Denom << endl;
}
int Fraction::getNum() {
    return Num;
}
int Fraction::getDenom() {
    return Denom;
}
void Fraction::setDenom(int value){
    Denom = value;
}
void Fraction::setNum(int value){
    Num = value;
}
void Fraction::input(){
    cin >> Num >> Denom;
    if (Denom == 0) {
        cout << "phan so khong hop le moi nhap lai: ";
        input();
    }
}
int Fraction::compare(Fraction p){
    if(Num * p.Denom < p.Num * Denom) return -1;
    else if(Num * p.Denom > p.Num * Denom) return 1;
    else return 0;
}
void Fraction::reduce(){
    int a = Num;
    int b = Denom;
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;  
    }
    Num /= a;
    Denom /= a;
}
Fraction Fraction::inverse(){
    Fraction p;
    p.Num = Denom;
    p.Denom = Num;
    return p;
}
Fraction::Fraction(){
    this -> Num = 0;
    this -> Denom = 1;
}
Fraction::Fraction(const int a){
    this -> Num = a;
    this -> Denom = 1;
}
Fraction::Fraction(const Fraction& a){
    this -> Num = a.Num;
    this -> Denom = a.Denom;
}
Fraction::Fraction(int a, int b) : Num(a), Denom(b) {}

Fraction::Fraction(string a) {
    this -> Num = a[0] - '0';
    this ->
    Denom = a[2] - '0';
}
Fraction::~Fraction(){
    
}