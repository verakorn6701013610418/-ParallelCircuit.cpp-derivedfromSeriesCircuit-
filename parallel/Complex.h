#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <iomanip>
using namespace std;

class Complex {
private:
    double real;    // Real part
    double imag;    // Imaginary part

public:
    Complex(double r = 0.0, double i = 0.0); // Constructor to initialize complex number
    Complex operator+(const Complex& other); // Overload the + operator to add two complex numbers
    Complex operator-(const Complex& other); // Overload the - operator to subtract two complex numbers
    Complex operator*(const Complex& other); // Overload the * operator to multiply two complex numbers
    Complex operator/(const Complex& other); // Overload the / operator to multiply two complex numbers
    // Complex operator/(const Complex& other); // Overload the / operator to divide two complex numbers

    Complex Conjugate(const Complex& A);
    Complex Magnitude(const Complex& A);

    bool operator==(const Complex& other); // Overload the == operator to compare two complex numbers
    void displayRectangular() const; // Function to display in rectangular form (a + bi)
    void displayPolar() const; // Function to display in polar form (r ∠ θ)
    // Overload the << operator for displaying complex numbers
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << fixed << setprecision(2);
        if (c.imag >= 0) {
            os << c.real << " + " << c.imag << "i";
        }
        else {
            os << c.real << " - " << -c.imag << "i";
        }
        return os;
    }

};

#endif
