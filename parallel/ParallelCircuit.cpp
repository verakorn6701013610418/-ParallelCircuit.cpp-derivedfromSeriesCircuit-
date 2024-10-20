#ifndef PARALLELCIRCUIT_CPP
#define PARALLELCIRCUIT_CPP

#include "ParallelCircuit.h"
#include "LinkedList.cpp"
#include "Complex.h"
#include "Node.h"

// Constructor to initialize the circuit
ParallelCircuit::ParallelCircuit() : hasSource(false) {}

// Function to add the AC voltage source
void ParallelCircuit::addSource(Complex V) {
    source = V;
    hasSource = true;
}

// Function to add a component to the series circuit
void ParallelCircuit::addline(Complex Z) {
    components.addLast(Z);
}

void ParallelCircuit::rmline(int number) {
    components.remove(number);
}

// Function to calculate and return the total impedance of the series circuit
Complex ParallelCircuit::getTotalImpedance() {
    Complex total = Complex(1, 0);
    Complex divider = Complex(0, 0);
    for (int i = 0; i < components.getSize(); i++) {
        total = total * components.get(i);
        divider = divider + components.get(i);
    }
    return total / divider;
}

// Function to calculate and return the current in the circuit
Complex ParallelCircuit::getCurrent() {
    if (!hasSource) {
        throw runtime_error("No source added to the circuit.");
    }
    Complex totalZ = getTotalImpedance();
    return source / totalZ;
}

// Function to print all components in the circuit
void ParallelCircuit::printComponents() {

    for (int i = 0; i < components.getSize(); i++) {
        cout << "impedance of line " << i + 1 << ": " << components.get(i) << endl;
    }
}

#endif