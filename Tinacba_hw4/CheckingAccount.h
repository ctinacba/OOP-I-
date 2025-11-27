// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: Homework 4: Inheritance & Polymorphism

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

// The CheckingAccount class represents a type of bank account
// that includes an additional service fee. It inherits all basic
// account behavior from the Account base class.
class CheckingAccount : public Account {
private:
    double fee;   // Monthly or service fee specific to checking accounts

public:
    // Constructor: creates a CheckingAccount with an account number,
    // client name, starting balance, and associated fee.
    CheckingAccount(int accNo, std::string name, double balance, double fee);

    // Virtual destructor: ensures proper cleanup when using base
    // class pointers to delete derived objects.
    virtual ~CheckingAccount();

    // Returns a formatted string describing this account.
    // Overrides the base class version to include the account type and fee.
    virtual std::string toString() override;
};

#endif // CHECKINGACCOUNT_H
