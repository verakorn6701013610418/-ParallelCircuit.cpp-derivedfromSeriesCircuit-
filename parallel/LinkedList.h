#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

// LinkedList class to manage the list operations
template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Pointer to the first node
    int size;
public:
    LinkedList(); // Constructor to initialize the linked list
    void addFirst(T data); // Function to add a node at the beginning
    void addLast(T data); // Function to add a node at the end
    T get(int i); // Function to get the value at index i
    void set(int i, T data); // Function to set the value at index i
    T removeFirst(); // Function to remove the first node
    T removeLast();
    T remove(int i);
    void printList();
    int getSize();
};

#endif