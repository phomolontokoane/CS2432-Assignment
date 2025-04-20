#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using std::cout;
////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct Node
{
    T data;     // Data of the node
    Node *next; // Pointer to the next node
    Node(T value) : data(value), next(NULL) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head; // Pointer to the head of the list
    int numItems;

public:
    LinkedList();
    ~LinkedList();

    int getSize();

    void add(T);
    T &at(int);
    void remove(int);
    void display();

    T &operator[](int index);
};

////////////////////////////////////////////////////////////////////////////////////

template <typename T>
LinkedList<T>::LinkedList() : head(NULL), numItems(0) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *current = head;
    while (current != NULL)
    {
        Node<T> *newCurrent = current->next;
        delete current;
        current = newCurrent;
    }
}

template <typename T>
int LinkedList<T>::getSize() { return numItems; }

template <typename T>
void LinkedList<T>::add(T data)
{
    Node<T> *newItem = new Node<T>(data);
    Node<T> *temp = head;
    ++numItems;
    
    if (!temp)
    {
        head = newItem;
        return;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newItem;
}

template <typename T>
T& LinkedList<T>::at(int index)
{
    if (index < 0 || index >= numItems)
    {
        throw std::out_of_range("Index out of bounds");
    }

    int count = 0;
    Node<T> *info = head;

    while (count < index)
    {
        info = info->next;
        ++count;
    }

    return info->data;
}

template <typename T>
void LinkedList<T>::remove(int index)
{
    if (index < 0 || index >= numItems)
    {
        throw std::out_of_range("Index out of bounds");
    }

    Node<T> *current = head;
    Node<T> *previous = nullptr;

    if (index == 0)
    {
        head = head->next;
        delete current;
    }
    else
    {
        for (int i = 0; i < index; ++i)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }

    --numItems;
}

template <typename T>
void LinkedList<T>::display()
{
    for (size_t i = 0; i < numItems; i++)
    {
        cout << at(i) << " -> ";
    }
    cout << '\n';
    
}

////////////////////////////////////////////////////////////////////////////////////

template <typename T>
T& LinkedList<T>::operator[](int index)
{
    return at(index);
}

////////////////////////////////////////////////////////////////////////////////////
#endif
