// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: Homework 4: Inheritance & Polymorphism

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

// SavingsAccount is a derived class that extends the Account base class.
// It adds an interest rate and overrides the toString() function to provide
// savings-specific account information.
class SavingsAccount : public Account {
private:
    double interestRate;
    // The interest rate applied to the savings account (e.g., 0.03 for 3%)

public:
    // Constructor: initializes a SavingsAccount with an account number,
    // owner's name, initial balance, and interest rate.
    SavingsAccount(int accNo, std::string name, double balance, double rate);

    // Virtual destructor to ensure proper cleanup when using polymorphism.
    virtual ~SavingsAccount();

    // Returns a string representation of the account, including interest rate.
    // Overrides the base class's toString() method.
    virtual std::string toString() override;
};

#endif // SAVINGSACCOUNT_H
