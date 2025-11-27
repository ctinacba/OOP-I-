//
// Name: Chelsy Tinacba
// Student ID: S00753660
// HW3 -> Operator Overloading
//

#ifndef HW3_FRACTION_H
#define HW3_FRACTION_H

#include <iosfwd>
/**************************************************************/
class Fraction {
private:
    int numerator;
    int denominator;

    void simplify();
    int gcd(int a,int b);
    /**************************************************************/
public:
    /*Constructors*/
    Fraction();             /*Initialize to 0/1*/
    Fraction(int n);        /*Initialize to n/1*/
    Fraction(int n, int d); /*Initialize to n/d*/

    /*Overloaded Arithmetic Operators*/
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    /**************************************************************/
    /*Overloaded Comparison Operators*/
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    /**************************************************************/
    /*Overloaded Stream Operators*/
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);
    /**************************************************************/
    /*Bonus*/
    Fraction& operator+=(const Fraction& other) const;

    Fraction &operator+=(const Fraction &other);

    Fraction& operator++();
    Fraction operator++(int);

};
/**************************************************************/

#endif //HW3_FRACTION_H