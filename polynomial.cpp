
#include "polynomial.h"
#include <iostream>
#include <vector>

using namespace std;
 
ostream &operator<<(ostream &out, const Polynomial& other) {
    
}

istream &operator>>(istream &in, const Polynomial& other) {

}

// constructor that takes vector of coeffs
Polynomial::Polynomial(const vector<double>& c) {
    coeffs = c;
}

// no arg constructor
// sets empty constructor to 1
Polynomial::Polynomial() {
    coeffs = {0} // value 1, equals 0
}

// set both sizes of both vectors equal to eachother by adding empty elements
void Polynomial::setVectorSize(const vector<double>& c, const Polynomial& other) {
    int p1 = coeffs.size() - 1;
    int p2 = other.coeffs.size() - 1;
    int maxExponent;
    if (p1 == p2) {
        return;
    } else if (p1 > p2) {
        maxExponent = p1;
        for (int i = p2; i <= p1; i++) {
            other.coeffs.insert(other.coeffs.begin(), i);
        }
    } else {
        maxExponent = p2;
        for (int i = p1; i <= p2; i++) {
            coeffs.insert(coeffs.begin(), i);
        }
    }
    return;
}

// addition operator +
Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial::setVectorSize(coeffs, other.coeffs);
    for (int i = 0; i <= maxExponent; i++) {
        result = coeffs[i] + other.coeffs[i];
    } 
    return result;
}

// addition and assignment operator +=
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

// subtraction operator -
Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial::setVectorSize(coeffs, other.coeffs);
    for (int i = 0; i <= maxExponent; i++) {
        result = coeffs[i] - other.coeffs[i];
    } 
    return result;
}

// subtraction and assignment operator -=
Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

// multiplication operator *
Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial::setVectorSize(coeffs, other.coeffs);
    for (int i = 0; i <= maxExponent; i++) {
        result = coeffs[i] * other.coeffs[i];
    } 
    return result;
}

// multiplication and assignment operator *=
Polynomial& Polynomial::operator*=(const Polynomial& other) {
    *this = *this  * other;
    return *this;
}

// division operator /
Polynomial Polynomial::operator/(const Polynomial& other) const {
    // Check if denominator is zero, that is invalid.
    if (other.coeffs.size() == 1 && other.coeffs[0] == 0) {
        throw??
    }
}

// division and assignment operator /=
Polynomial& Polynomial::operator/=(const Polynomial& other) {
    *this = *this / other;
    return *this;
}
    
// check equality ==
bool Polynomial Polynomial::operator==(const Polynomial& other) const {
    return coeffs == other.coeffs;
}

// check if not equal !=
bool Polynomial Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);
}

// Greater than operator >
bool operator>(const Polynomial& other) const {
    if (coeffs.size() != other.coeffs.size()) {
        return coeffs.size() > other.coeffs.size();
    }
    for (int i = coeffs.size() - 1; i >= 0; i--) {
        if (coeffs[i] != other.coeffs[i]) {
            return coeffs[i] > other.coeffs[i];
        }
    }
    return false;
}

// Less than operator <
bool operator<(const Polynomial& other) const {
    if (coeffs.size() != other.coeffs.size()) {
        return coeffs.size() < other.coeffs.size();
    } 
    for (int i = coeffs.size() - 1; i >= 0; i--) {
        if (coeffs[i] != other.coeffs[i]) {
            return coeffs[i] < other.coeffs[i];
        }
    }
    return false;
}

// Greater than or equal to operator >=
bool operator>=(const Polynomial& other) const {
    return (*this == other) || (*this > other);
}

// Less than or equal to operator <= 
bool operator<=(const Polynomial& other) const {
    return (*this == other) || (*this < other);
}
