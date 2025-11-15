#pragma once
#include <iostream>
#include <ctime>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

template <class T>
struct Node
{
    T value;
    Node *pNext;
};

template <class T>
class Linkedlist
{
private:
    Node<T> *head, *tail;
    int n;
    static Node<T> *CreateNode(const T &);

public:
    Linkedlist();
    ~Linkedlist();

    Node<T> *addHead(const T &);
    Node<T> *addTail(const T &);
    Node<T> *removeHead();
    Node<T> *removeTail();

    int getSize() const;
    T &operator[](const int &) const;

    template <class U>
    friend ostream &operator<<(ostream &, const Linkedlist<U> &);
};
template <class T>
int Linkedlist<T>::getSize() const{
    return n;
}
template <class T>
Node<T> *Linkedlist<T>::CreateNode(const T &_value)
{
    Node<T> *temp = new Node<T>;
    temp->value = _value;
    temp->pNext = nullptr;
    return temp;
}
template <class T>
Linkedlist<T>::Linkedlist()
{
    head = tail = nullptr;
    n = 0;
}
template <class T>
Linkedlist<T>::~Linkedlist()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->pNext;
        delete temp;
    }
    tail = nullptr;
    n = 0;
}
template <class T>
Node<T> *Linkedlist<T>::addHead(const T &_value)
{
    Node<T> *node = CreateNode(_value);
    if (node == nullptr)
        return nullptr;
    if (head == nullptr)
    {
        head = tail = node;
        n++;
    }
    else
    {
        node->pNext = head;
        head = node;
        n++;
    }
    return node;
}
template <class T>
Node<T> *Linkedlist<T>::addTail(const T &_value)
{
    Node<T> *node = CreateNode(_value);
    if (node == nullptr)
        return nullptr;
    if (head == nullptr)
    {
        head = tail = node;
        n++;
    }
    else
    {
        tail->pNext = node;
        tail = node;
        n++;
    }
    return node;
}
template <class T>
Node<T> *Linkedlist<T>::removeHead()
{
    if (head == nullptr)
        throw std::out_of_range("List is empty");

    Node<T> *temp = head;
    Node<T> *val = temp;

    head = head->pNext;
    if (head == nullptr)
        tail = nullptr;

    delete temp;
    n--;
    return val;
}
template <class T>
Node<T> *Linkedlist<T>::removeTail()
{
    if (head == nullptr)
        throw std::out_of_range("List is empty");

    if (head == tail)
    {
        T val = head->value;
        delete head;
        head = tail = nullptr;
        n--;
        return val;
    }

    Node<T> *curr = head;
    while (curr->pNext != tail)
        curr = curr->pNext;

    Node<T> *val = tail;
    delete tail;
    tail = curr;
    tail->pNext = nullptr;
    n--;
    return val;
}

template <class T>
T &Linkedlist<T>::operator[](const int &index) const
{
    if (index < 0 || index >= n)
    {
        throw std::out_of_range("Index out of range");
    }

    Node<T> *curr = head;
    for (int i = 0; i < index; i++)
    {
        curr = curr->pNext;
    }

    return curr->value;
}
template <class T>
ostream &operator<<(ostream &out, const Linkedlist<T> &list)
{
    Node<T> *curr = list.head;
    while (curr != nullptr)
    {
        out << curr->value << " -> ";
        curr = curr->pNext;
    }
    out << "nullptr";
    return out;
}
