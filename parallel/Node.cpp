#ifndef NODE_CPP
#define NODE_CPP
#include "Node.h"

// Constructor to initializae a node
template <typename T> 
Node<T>::Node(T val): data(val), next(nullptr) { }

#endif