#ifndef SERIESCIRCUIT_CPP
#define SERIESCIRCUIT_CPP

#include "SeriesCircuit.h"
#include "LinkedList.cpp"
#include "Complex.h"
#include "Node.h"

// Constructor to initialize the circuit
SeriesCircuit::SeriesCircuit() : hasSource(false) {}

// Function to add the AC voltage source
void SeriesCircuit::addSource(Complex V) {
    source = V;
    hasSource = true;
}

// Function to add a component to the series circuit
void SeriesCircuit::addComponent(Complex Z) {
    components.addLast(Z);
}

void SeriesCircuit::rmComponent(int number) {
    components.remove(number);
}

// Function to calculate and return the total impedance of the series circuit
Complex SeriesCircuit::getTotalImpedance() {
    Complex total = Complex(0,0);
    for(int i=0; i < components.getSize(); i++){
        total = total + components.get(i);
    }
    return total;
}

// Function to calculate and return the current in the circuit
Complex SeriesCircuit::getCurrent() {
    if (!hasSource) {
        throw runtime_error("No source added to the circuit.");
    }
    Complex totalZ = getTotalImpedance();
    return source / totalZ;
}

// Function to print all components in the circuit
void SeriesCircuit::printComponents() {
    
    for(int i=0; i<components.getSize(); i++) {
        cout << "Component " << i+1 << ": " << components.get(i) << endl;
    }
}

#endif