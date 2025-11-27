// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: Homework 4: Inheritance & Polymorphism

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// The Account class represents a basic bank account with
// an account number, client name, and current balance.
class Account {
protected:
    int accountNo;           // Unique client account number
    std::string name;        // Client's name
    double balance;          // Current account balance

public:
    // Constructor: initializes an Account object with an account number,
    // client name, and starting balance.
    Account(int accNo, std::string name, double balance);

    // Virtual destructor: declared virtual to ensure proper cleanup
    // when deleting objects through a base class pointer.
    virtual ~Account();

    // Returns a formatted string containing account details.
    // Marked virtual so derived classes (like SavingsAccount, CheckingAccount)
    // can override it with their own version.
    virtual std::string toString();
};

#endif // ACCOUNT_H
