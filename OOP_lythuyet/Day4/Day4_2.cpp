
//=========implement
#include <iostream>
using namespace std;

class Array
{
private:
    int size;
    int *arr;

public:
    Array();
    Array(int size);
    Array(int a[], int n);
    Array(const Array &temp);
    ~Array();

    void input();
    void output();

    int getSize();
    void setSize(int newSize);

    int getElement(int index);
    void setElement(int index, int value);

    int find(int value);
    void sortArray();

    void setOrder(int value);

    Array operator+(const Array &);
    Array operator+=(const Array &);
    Array &operator=(const Array &);
    int &operator[](int index);
    const int &operator[](int index) const;
    operator int *const();
    friend ostream &operator<<(ostream &out, const Array &);
    friend istream &operator>>(istream &in, Array &);
};

int main(){
    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {6, 7, 8};
    Array arr1(a1,sizeof(a1)/sizeof(a1[0]));
    Array arr2(a2,sizeof(a2)/sizeof(a2[0]));
    cout << "Array 1: " << arr1; 
    cout << "Array 2: " << arr2;
    //==============================================================
    Array sum;
    sum = arr1 + arr2;
    cout << "Array 1 + Array 2: " << sum;
    cout << endl;
    //==============================================================

    int a3[] = {9, 10, 11};
    Array arr3(a3, sizeof(a3)/sizeof(a3[0]));
    cout << "Array 3: " << arr3;
    arr3 += sum;
    cout << "Array 3 += sum: " << arr3;
    cout << endl;
    //==============================================================
    int *temp_arr;
    temp_arr = (int*) arr3;
    cout << "Test type cast (int*): temp_arr = (int*) arr3" << endl;
    for (int i = 0; i < arr3.getSize(); i++){
        cout << temp_arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    //==============================================================
    Array arr4;
    cin >> arr4;
    cout << "Array 4: " << arr4;
    cout << "Array 4's 2nd element (arr4[1]): " << arr4[1] << endl;
    cout << "Array 4's 6th element (arr4[5]): " << arr4[5] << endl;
    cout << endl;
    //==============================================================
    arr1.~Array();
    arr2.~Array();
    sum.~Array();
    arr3.~Array();
    arr4.~Array();
    return 0;
}
// ===== Implementations =====
Array::Array()
{
    size = 0;
    arr = new int[size];
}

Array::Array(int size)
{
    this->size = size;
    arr = new int[size]();
}

Array::Array(int a[], int n)
{
    this->size = n;
    arr = new int[size];
    for (int i = 0; i < n; i++)
        arr[i] = a[i];
}

Array::Array(const Array &temp)
{
    size = temp.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = temp.arr[i];
}

Array::~Array()
{
    delete[] arr;
}

int Array::getSize()
{
    return size;
}

void Array::setSize(int newSize)
{
    int *newArr = new int[newSize];
    int minSize = (newSize < size) ? newSize : size;
    for (int i = 0; i < minSize; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    size = newSize;
}

int Array::getElement(int index)
{
    return arr[index];
}

void Array::setElement(int index, int value)
{
    arr[index] = value;
}

int Array::find(int value)
{
    int index{-1};
    for (int i = 0; i < size; i++)
    {
        if (value == arr[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

void Array::sortArray()
{
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

Array Array::operator+(const Array &a)
{
    int total_size = this->size + a.size;
    Array newArray(total_size);
    for (int i = 0; i < this->size; i++)
    {
        newArray.arr[i] = this->arr[i];
    }
    for (int i = 0; i < a.size; i++)
    {
        newArray.arr[i + this->size] = a.arr[i];
    }
    return newArray;
}

Array Array::operator+=(const Array &a)
{
    *this = *this + a;
    return *this;
}

Array &Array::operator=(const Array &other)
{
    if (this == &other)
        return *this;

    delete[] this->arr;
    this->size = other.size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++)
        this->arr[i] = other.arr[i];
    return *this;
}

int &Array::operator[](int index)
{
    if (index < 0 || index >= this->size)
    {
        cerr << "ERROR!!!" << endl;
        exit(1);
    }
    else
        return this->arr[index];
}

const int &Array::operator[](int index) const
{
    if (index < 0 || index >= this->size)
    {
        cerr << "ERROR!!!" << endl;
        exit(1);
    }
    else
        return this->arr[index];
}

Array::operator int *const()
{
    return arr;
}

ostream &operator<<(ostream &out, const Array &array)
{
    for (int i = 0; i < array.size; i++)
    {
        out << array[i] << " ";
    }
    out << endl;
    return out;
}

istream &operator>>(istream &in, Array &array)
{
    delete[] array.arr;
    cout << "Enter size of arr: ";
    in >> array.size;
    array.arr = new int[array.size];
    cout << "Enter Array's Element:" << endl;
    for (int i = 0; i < array.size; i++)
    {
        in >> array[i];
    }
    return in;
}