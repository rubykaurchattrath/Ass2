#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>

using namespace std;

class Polynomial {

friend ostream &operator<<(ostream &out, const Polynomial& other);
friend istream &operator>>(istream &in, const Polynomial& other);

private:
    // coefficients of the polynomial
    vector<double> coeffs; 

    // remove extra zeros
    void reduce();

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

};

#endif
