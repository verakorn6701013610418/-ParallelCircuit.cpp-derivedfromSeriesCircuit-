#ifndef NODE_H
#define NODE_H

// Node class representing each element in the list
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T val); // Constructor to initialize a node
};

#endif