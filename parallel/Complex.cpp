
#ifndef COMPLEX_CPP
#define COMPLEX_CPP

#include <iostream>
#include <cmath>  // For sqrt and atan2
#include <iomanip>  // For controlling output format
#include "Complex.h"

#define M_PI 3.14

using namespace std;

// Constructor to initialize complex number
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Overload the + operator to add two complex numbers
Complex Complex::operator+(const Complex& other) {
    return Complex(real + other.real, imag + other.imag);
}

// Overload the - operator to subtract two complex numbers
Complex Complex::operator-(const Complex& other) {
    return Complex(real - other.real, imag - other.imag);
}

// Overload the * operator to multiply two complex numbers
Complex Complex::operator*(const Complex& other) {
    double realPart = (real * other.real) - (imag * other.imag);
    double imagPart = (real * other.imag) + (imag * other.real);
    return Complex(realPart, imagPart);
}

// TODO: Implement the operation division (the formalae are in the lab sheet)
// Overload the / operator to divide two complex numbers
// Complex Complex::operator/(const Complex& other) {
Complex Complex::operator/(const Complex& other) {
    double denominator = other.real * other.real + other.imag * other.imag;
    double realPart = (real * other.real + imag * other.imag) / denominator;
    double imagPart = (imag * other.real - real * other.imag) / denominator;
    return Complex(realPart, imagPart);
}

//}
// Overload the == operator to compare two complex numbers
bool Complex::operator==(const Complex& other) {
    return (real == other.real) && (imag == other.imag);
}

Complex Complex::Conjugate(const Complex& A) {
    return Complex(A.real, -A.imag);
}

Complex Complex::Magnitude(const Complex& A) {
    return sqrt((A.real * A.real) + (A.imag * A.imag));
}

// Function to display in rectangular form (a + bi)
void Complex::displayRectangular() const {
    cout << fixed << setprecision(2);  // Set precision to 2 decimal places
    if (imag >= 0) {
        cout << "Rectangular form: " << real << " + " << imag << "i" << endl;
    }
    else {
        cout << "Rectangular form: " << real << " - " << -imag << "i" << endl;
    }
}

// Function to display in polar form (r ∠ θ)
void Complex::displayPolar() const {
    double r = sqrt(real * real + imag * imag);  // Magnitude (r)
    double theta = atan2(imag, real);  // Angle in radians (θ)
    double thetaDegrees = theta * 180.0 / M_PI;  // Convert to degrees

    cout << fixed << setprecision(2);  // Set precision to 2 decimal places
    cout << "Polar form: " << r << " polar " << thetaDegrees << "degree" << endl;
}

#endif
