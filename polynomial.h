#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>

using namespace std;

class Polynomial {

friend ostream &operator<<(ostream &out, const Polynomial& other);
friend istream &operator>>(istream &in, const Polynomial& other);

private:
    vector<double> coeffs;  // coefficients of the polynomial
    Polynomial result;

    // set both sizes of both vectors equal to eachother by adding empty elements
    void Polynomial setVectorSize(const vector<double>& c, const Polynomial& other);

public:
    // constructor that takes vector of coeffs
   Polynomial(const Polynomial& other);

   // no arg constructor
   Polynomial();

    // arithmetic operators
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator+=(const Polynomial& other);
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator-=(const Polynomial& other);
    Polynomial operator*(const Polynomial& other) const;
    Polynomial operator*=(const Polynomial& other);
    Polynomial operator/(const Polynomial& other) const;
    Polynomial operator/=(const Polynomial& other);
    
    // equality and not equal operators
    bool operator==(const Polynomial& other) const;
    bool operator!=(const Polynomial& other) const;
   
    // comparison operators
    bool operator>(const Polynomial& other) const;
    bool operator<(const Polynomial& other) const;
    bool operator>=(const Polynomial& other) const;
    bool operator<=(const Polynomial& other) const;

    // print function
    void print() const; ????
};

#endif
