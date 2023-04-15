
#include "polynomial.h"
#include <iostream>
#include <vector>

using namespace std;
 
// constructor that takes vector of coeffs
Polynomial::Polynomial(const vector<double>& c) {
    coeffs = c;
    reduce();
}

// no arg constructor
// sets empty constructor to 1
// value 1, equals 0
Polynomial::Polynomial() {
    coeffs = {0};
}

// ostream overload operator displays final polynomial
ostream &operator<<(ostream &out, const Polynomial& other) {
    for (int i = (other.coeffs.size() - 1); i >= 0; i--) { // backwards, last element is highest degree
        if (other.coeffs[i] == 0) {
            continue; // if coeff is 0, skip to next loop
        }
        if (i == 0) {  // first in vector, gets printed alone
            out << other.coeffs[i];
        } else if (i == 1) { // 2 one in vector, gets printed with one x only
            out << other.coeffs[i] << "x";
        } else {
            out << other.coeffs[i] << "x" << i << "+";
        }
    } 
    return out << endl;
}

// istream overload operator taking in polynomial from user
istream &operator>>(istream &in, Polynomial& other) {
    other.coeffs.clear(); // clear previous coeffs
    string term;
    getLine(in, term); // get line from input
    stringstream s(term); // convert line to stringStream
    string subTerm;

    // add '+' between subterms
    while (getLine(s, subTerm, '+')) {
        int coeff = 0;
        int exp = 0;

        // extract coeff and exponent from each subTerm
        size_t xIndex = subTerm.find('x');
        if (xIndex != string::npos) {
            coef = stoi(subTerm.substr(0, xIndex)); // Extract coeff
            size_t expIndex = subTerm.find('^');
            if (expIndex != string::npos) {
                exp = stoi(subTerm.substr(expIndex + 1)); // Extract exponent
            } else {
                exp = 1; // default exponent is 1
            }
        } else {
            coeff = stoi(subTerm); // if no x, then subterm is just coeff
        }

         // insert coeffs into vector at right exp
        if (other.coeffs.size() <= exp) {
            other.coeffs.resize(exp + 1);
        }
        other.coeffs[exp] += coeff;
    }
    return in;
}

// remove leading and trailing zeros in the vector
void Polynomial::reduce() {
    // remove leading zeros
    while (!coeffs.empty() && coeffs.front() == 0) {
        coeffs.erase(coeffs.begin());
    }

    // remove trailing zeros
    while (!coeffs.empty() && coeffs.back() == 0) {
        coeffs.pop_back();
    }

    // if all coefficients are zero, add a zero constant term
    if (coeffs.empty()) {
        coeffs.push_back(0);
    }
}

// addition operator +
Polynomial Polynomial::operator+(const Polynomial& other) const {
    vector<double> result(max(coeffs.size(), other.coeffs.size()));
    for (double i = 0; i < result.size(); i++) {
        double a = (i < coeffs.size()) ? coeffs[i] : 0;
        double b = (i < other.coeffs.size()) ? other.coeffs[i] : 0;
        result[i] = a + b;
    } 
    return Polynomial(result);
}

// addition and assignment operator +=
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

// subtraction operator -
Polynomial Polynomial::operator-(const Polynomial& other) const {
    vector<double> result(max(coeffs.size(), other.coeffs.size()));
    for (int i = 0; i <= (result.size() - 1); i++) {
        result[i] = coeffs[i] - other.coeffs[i];
    } 
    return Polynomial(result);
}

// subtraction and assignment operator -=
Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

// multiplication operator *
Polynomial Polynomial::operator*(const Polynomial& other) const {
    vector<double> result(max(coeffs.size(), other.coeffs.size()));
    for (int i = 0; i < coeffs.size(); i++) {
        for (int j = 0; j < other.coeffs.size(); j++) {
            result[i+j] += coeffs[i] * other.coeffs[j];
        }
    }
    return Polynomial(result);
}

// multiplication and assignment operator *=
Polynomial& Polynomial::operator*=(const Polynomial& other) {
    *this = *this  * other;
    return *this;
}
    
// check equality ==
bool Polynomial::operator==(const Polynomial& other) const {
    if (coeffs == other.coeffs) {
        return true;
    } else {
        return false;
    }
}

// check if not equal !=
bool Polynomial::operator!=(const Polynomial& other) const {
    if (!(*this == other)) {
        return true;
    } else {
        return false;
    }
}

// Greater than operator >
bool Polynomial::operator>(const Polynomial& other) const {
    if (coeffs.size() > other.coeffs.size()) {
        return true;
    }
    else if (coeffs.size() < other.coeffs.size()) {
        return false;
    } else {
        for (int i = coeffs.size() - 1; i >= 0; i--) {
            if (coeffs[i] > other.coeffs[i]) {
                return true;
            } else if (coeffs[i] < other.coeffs[i]) {
                return false;
            }
        }
    }
    return false; // equal
}

// Less than operator <
bool Polynomial::operator<(const Polynomial& other) const {
    if (coeffs.size() < other.coeffs.size()) {
        return true;
    } else if (coeffs.size() > other.coeffs.size()) {
        return false;
    }
    for (int i = coeffs.size() - 1; i >= 0; i--) {
        if (coeffs[i] < other.coeffs[i]) {
            return true;
        } else if (coeffs[i] > other.coeffs[i]) {
            return false;
        }
    }
    return false;
}

// Greater than or equal to operator >=
bool Polynomial::operator>=(const Polynomial& other) const {
    return (*this == other) || (*this > other);
}

// Less than or equal to operator <= 
bool Polynomial::operator<=(const Polynomial& other) const {
    return (*this == other) || (*this < other);
}

