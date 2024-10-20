#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include <iostream>
#include "LinkedList.h"
#include "Node.cpp"

using namespace std;

// Constructor to initialize the linked list
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

// Function to add a node at the beginning
template <typename T>
void LinkedList<T>::addFirst(T v) {
    Node<T>* newNode = new Node<T>(v);
    newNode->next = head;
    head = newNode;
    size++;
}

// Function to add a node at the end
template <typename T>
void LinkedList<T>::addLast(T v) {
    Node<T>* newNode = new Node<T>(v);
    if (head == nullptr) {
        head = newNode;
        size++;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

// Function to get the value at index i
template <typename T>
T LinkedList<T>::get(int i) {
    Node<T>* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (index == i) {
            return temp->data;
        }
        temp = temp->next;
        index++;
    }
    throw out_of_range("Index out of bounds");
}

// Function to set the value at index i
template <typename T>
void LinkedList<T>::set(int i, T v) {
    Node<T>* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (index == i) {
            temp->data = v;
            return;
        }
        temp = temp->next;
        index++;
    }
    throw out_of_range("Index out of bounds");
}

// Function to remove the first node
template <typename T>
T LinkedList<T>::removeFirst() {
    if (head == nullptr) return 0;
    Node<T>* temp = head;
    T temp_val = temp->data;
    head = head->next;
    delete temp;
    size--;
    return temp_val;
}

// Function to remove the last node
template <typename T>
T LinkedList<T>::removeLast() {
    if (head == nullptr) return 0;
    if (head->next == nullptr) {
        T temp_val = head->data;
        delete head;
        head = nullptr;
        size--;
        return temp_val;
    }
    Node<T>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    T temp_val = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
    size--;
    return temp_val;
}

// Function to remove a node at index i
template <typename T>
T LinkedList<T>::remove(int i) {
    if (i == 0) {
        return removeFirst();
    }

    Node<T>* temp = head;
    int index = 0;
    Node<T>* prev = nullptr;
    while (temp != nullptr && index != i) {
        prev = temp;
        temp = temp->next;
        index++;
    }

    if (temp == nullptr) throw out_of_range("Index out of bounds");

    prev->next = temp->next;
    T temp_val = temp->data;
    delete temp;
    size--;
    return temp_val;
}

// Function to traverse and print the list
template <typename T>
void LinkedList<T>::printList() {
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
       // (temp->data).displayPolar();
        temp = temp->next;
    }
    cout << endl;
}

// Function to traverse and print the list
template <typename T>
int LinkedList<T>::getSize() {
    return size;
}
#endif

