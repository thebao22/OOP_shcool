#include "lib.h"
//====IMPLEMENT ARRAY CLASS
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

// Array::Array(int a[], int n)
// {
//     this->size = n;
//     arr = new int[size];
//     for (int i = 0; i < n; i++)
//         arr[i] = a[i];
// }

Array::Array(int *a, int n)
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
int Array::findmax()
{
    int max{};
    for (int i = 0; i < size; i++)
    {
        if (max == 0 || max < arr[i])
            max = arr[i];
    }
    return max;
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

//===IMPLEMENT HISTOGRAM CLASS
void Histogram::compute()
{

    delete[] histogram;
    histsize = Array::findmax();
    histogram = new int[histsize + 1];
    for (int i = 0; i <= histsize; i++)
    {
        histogram[i] = 0;
    }
    for (int i = 0; i < Array::getSize(); i++)
    {
        int index = Array::getElement(i);
        if (index <= histsize)
            histogram[index]++;
    }
}
Histogram::Histogram(int *a, int n) : Array(a, n)
{
    compute();
}
void Histogram::display()
{
    for (int i = 0; i <= histsize; i++)
    {
        cout << i << "->" << histogram[i] << " ";
    }
}