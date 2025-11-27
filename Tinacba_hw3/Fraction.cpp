//
// Name: Chelsy Tinacba
// Student ID: S00753660
// HW3 -> Operator Overloading
//
/**************************************************************/
#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <ostream>
#include "Fraction.h"
using namespace std;
/**************************************************************/
    /*Simplify*/
void Fraction::simplify() {
    if (denominator == 0) {
        cerr << "[ERROR] Denominator CANNOT be Zero." << endl;
        numerator = 0;
        denominator = 1;
        return;
    }
    if (numerator ==0) {
        denominator = 1;
        return;
    }

    /*Set to positive*/
    if (denominator < 0){
        denominator = -denominator;
        numerator = -numerator;
    }
    int gcDivisor = gcd(numerator, denominator);
    numerator   /= gcDivisor;
    denominator /= gcDivisor;
}

/**************************************************************/
    /*Constructors*/
Fraction::Fraction():numerator(0), denominator(1) {}
Fraction::Fraction(int n): numerator(n), denominator(1){}
Fraction::Fraction(int n, int d): numerator(n), denominator(d) {
    if (d==0) {
        cerr << "[ERROR] Denominator CANNOT be zero.\n";
        numerator = 0;
        denominator = 1;
    }
    else
        simplify();
}
/**************************************************************/
    /*Arithmetic*/
Fraction Fraction::operator+(const Fraction& other) const {
    Fraction r(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    r.simplify();
    return r;
}
/***************/
Fraction Fraction::operator-(const Fraction& other) const {
    Fraction r(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    r.simplify();
    return r;
}
/***************/
Fraction Fraction::operator*(const Fraction& other) const {
    Fraction r(numerator * other.numerator, denominator * other.denominator);
    r.simplify();
    return r;
}
/***************/
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        cerr << "[ERROR] Denominator CANNOT be zero. \n";
        return Fraction();
    }
    Fraction r(numerator * other.denominator, denominator * other.numerator);
    r.simplify();
    return r;
}
/**************************************************************/
    /*Conditional Operators*/
bool Fraction::operator==(const Fraction& other) const {
    long long lhs = static_cast<long long>(numerator * other.denominator);
    long long rhs = static_cast<long long>(denominator * other.numerator);
    return lhs == rhs;
}
/***************/
bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}
/***************/
bool Fraction::operator<(const Fraction& other) const {
    long long lhs = static_cast<long long>(numerator * other.denominator);
    long long rhs = static_cast<long long>(denominator * other.numerator);
    return lhs < rhs;
}
/***************/
bool Fraction::operator>(const Fraction& other) const {
    long long lhs = static_cast<long long>(numerator * other.denominator);
    long long rhs = static_cast<long long>(denominator * other.numerator);
    return lhs > rhs;
}
/**************************************************************/
    /*Overloaded Stream Operators*/
ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}
/***************/
istream& operator>>(istream& is, Fraction& f) {
    int n = 0, d = 1;
    char back = 0;
    if (!(is >> n)) {
        is.setstate(ios::failbit);
        return is;
    }
    if (!(is >> back) || back != '/') {
        if (is && back) is.unget();
        f = Fraction(n, 1);
        return is;
    }
    if (!(is >> d)) {
        is.setstate(ios::failbit);
        return is;
    }
    f = Fraction(n, d);
    return is;
}
/**************************************************************/
    /*Bonus Operators*/
Fraction& Fraction::operator+=(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator = denominator * other.denominator;
    simplify();
    return *this;
}
/***************/
Fraction &Fraction::operator++() {
    numerator += denominator;
    simplify();
    return *this;
}
/***************/
Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    ++(*this);
    return temp;
}
/**************************************************************/
    /*Private Functions*/
int Fraction::gcd(int a, int b) {
    a = abs(a); b = abs(b); /*Sets to positive with Absolute Power*/
    int r;
    for (int i = 1; i <= a && i <= b ; i++) {
        if (a%i == 0 && b%i==0)
            r = i;
    }
    return r;
}