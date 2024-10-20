#ifndef SERIESCIRCUIT_H
#define SERIESCIRCUIT_H

#include "LinkedList.h"
#include "Complex.h"

// SeriesCircuit class to represent the circuit
class SeriesCircuit {

private:
    LinkedList<Complex> components;  // Associated LinkedList to store components
    Complex source;         // Voltage source (complex number)
    bool hasSource;         // Flag to check if a source has been added

public:    

    SeriesCircuit(); // Constructor to initialize the circuit
    void addSource(Complex V);  // Function to add the AC voltage source
    void addComponent(Complex Z); // Function to add a component to the series circuit 
    void rmComponent(int list);
    Complex getTotalImpedance(); // Function to calculate and return the total impedance of the series circuit
    Complex getCurrent(); // Function to calculate and return the current in the circuit
    void printComponents(); // Function to print all components in the circuit
};

#endif