
#include <iostream>
#include "ParallelCircuit.h"

#define M_PI 3.14

using namespace std;

int main() {
    // Create a SeriesCircuit object
    SeriesCircuit circuit;
    SeriesCircuit circuit2;
    SeriesCircuit circuit3;
    ParallelCircuit Pcircuit;

    // Given values for components and source
    double R1 = 10.0;       // Resistor 1 (Ohms)
    double R2 = 20.0;       // Resistor 2 (Oh-ms)
    double L = 0.1;         // Inductor (Henries)
    double C = 50e-6;       // Capacitor (Farads)

    double frequency = 60.0;  // Frequency (Hertz)
    double V_rms = 120.0;   // Source voltage (RMS value)

    double R3 = 200;
    double R4 = 30;
    double L2 = 0.01;
    double C2 = 0.001;

    double R5 = 220;
    double R6 = 1000;
    double L3 = 0.001;
    double C3 = 0.001;

    // Angular frequency
    double omega = 2 * M_PI * frequency;

    // Add components to the series circuit
    circuit.addComponent(Complex(R1, 0));               // Resistor 1 (real part only)
    circuit.addComponent(Complex(R2, 0));               // Resistor 2 (real part only)
    circuit.addComponent(Complex(0, omega * L));        // Inductor: Z = jωL
    circuit.addComponent(Complex(0, -1 / (omega * C))); // Capacitor: Z = -j/(ωC)

    circuit2.addComponent(Complex(R3, 0));
    circuit2.addComponent(Complex(R4, 0));               // Resistor 2 (real part only)
    circuit2.addComponent(Complex(0, omega * L2));        // Inductor: Z = jωL
    circuit2.addComponent(Complex(0, -1 / (omega * C2))); // Capacitor: Z = -j/(ωC)

    circuit3.addComponent(Complex(R5, 0));
    circuit3.addComponent(Complex(R6, 0));               // Resistor 2 (real part only)
    circuit3.addComponent(Complex(0, omega * L3));        // Inductor: Z = jωL
    circuit3.addComponent(Complex(0, -1 / (omega * C3))); // Capacitor: Z = -j/(ωC)

    Pcircuit.addline(circuit.getTotalImpedance());
    Pcircuit.addline(circuit2.getTotalImpedance());
    Pcircuit.addline(circuit3.getTotalImpedance());

    Pcircuit.getTotalImpedance();
    cout << "total impedance of this circuit is " << Pcircuit.getTotalImpedance() << " Ohm" << endl;
    Pcircuit.printComponents();
    Pcircuit.addSource(V_rms);
    cout << "Current of this circuit is " << Pcircuit.getCurrent() << " A" << endl;
    Pcircuit.getCurrent();


    return 0;
}
