//
// Name: Chelsy Tinacba
// Student ID: S00753660
// HW3 -> Operator Overloading
//
/**************************************************************/
#include <iostream>
#include "Fraction.h"
using namespace std;
/**************************************************************/
int main(void) {
    cout << "This C++ program goest through and tests all overloaded operators work correctly" << endl;
/**************************************************************/
    /*Constructors*/

    Fraction fract1;
    Fraction fract2(3);
    Fraction fract3(2,4);
    Fraction fract4(-6,-8);
    Fraction fract5(1, -2);
    Fraction fract6(0,5);

    /*Verify Each Fraction*/
    cout << "Practice Constructing:" << endl;
    cout << "Fraction 1 "  << fract1 << endl;
    cout << "Fraction 2 "  << fract2 << endl;
    cout << "Fraction 3 "  << fract3 << endl;
    cout << "Fraction 4 "  << fract4 << endl;
    cout << "Fraction 5 "  << fract5 << endl;
    cout << "Fraction 6 "  << fract6 << endl << endl;


    /*Arithmetics*/
    cout << "Practice Arithmetic:" << endl;
    cout << fract1 << " + " << fract2 << " = " << (fract1 + fract2) << endl;
    cout << fract1 << " - " << fract2 << " = " << (fract1 - fract2) << endl;
    cout << fract1 << " * " << fract2 << " = " << (fract1 * fract2) << endl;
    cout << fract1 << " / " << fract2 << " = " << (fract1 / fract2) << endl;


    /*Comparison*/
    cout << "Practice Comparison:" << endl;
    if (fract3 == fract3) cout << fract3 << " == " << fract4 << " ( == | true)" << endl;
    if (fract3 != fract5) cout << fract3 << " != " << fract5 << " (!= | true)" << endl;
    if (fract5 < fract3)  cout << fract5 << " <  " << fract3 << " ( < | true)" << endl;
    if (fract3 > fract1)  cout << fract3 << " >  " << fract2 << " ( > | true)" << endl << endl;

    /*Stream/Scanning Operators*/
    cout << "Stream Input and Output:" << endl;
    cout << "Enter a fraction (Either n/d OR numerator): ";
    Fraction user;
    if (cin >> user) {
        cout << "You Entered: " << user << endl;
    }
    else {
        cout << "[ERROR] please enter a valid fraction." << endl << endl;
        return 1;
    }

    /*Bonus Operators*/
    Fraction bonusFract(4,5);
    cout << "Bonus Fraction starts as: " << bonusFract << endl;
    bonusFract += Fraction(1,2); /* 4/5 + 1/2 */

    cout << "Bonus Fraction += 1/2 is " << bonusFract << endl;
    cout << "bonus Fraction ++ is " << bonusFract++ << endl;
    cout << "After bonus Fraction++ is " << bonusFract << endl;
    cout << "++bonus Fraction is "  << ++bonusFract << endl;

    return 0;
}
/**************************************************************/