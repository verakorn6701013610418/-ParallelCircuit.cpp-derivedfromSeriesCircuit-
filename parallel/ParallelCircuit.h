#ifndef PARALLELCIRCUIT_H
#define PARALLELCIRCUIT_H

#include "LinkedList.h"
#include "Complex.h"
#include "SeriesCircuit.h"

// SeriesCircuit class to represent the circuit
class ParallelCircuit {

private:
    LinkedList<Complex> components;  // Associated LinkedList to store components
    Complex source;         // Voltage source (complex number)
    bool hasSource;         // Flag to check if a source has been added

public:

    ParallelCircuit(); // Constructor to initialize the circuit
    void addSource(Complex V);  // Function to add the AC voltage source
    void addline(Complex Z); // Function to add a component to the series circuit 
    void rmline(int list);
    Complex getTotalImpedance(); // Function to calculate and return the total impedance of the series circuit
    Complex getCurrent(); // Function to calculate and return the current in the circuit
    void printComponents(); // Function to print all components in the circuit
};

#endif