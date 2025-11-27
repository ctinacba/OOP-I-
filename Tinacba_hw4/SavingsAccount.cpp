// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: Homework 4: Inheritance & Polymorphism

#include "SavingsAccount.h"
#include <sstream>
#include <iomanip>

// Constructor: initializes a SavingsAccount by calling the base Account constructor
// and setting the interest rate that applies to savings accounts.
SavingsAccount::SavingsAccount(int accNo, std::string name, double balance, double rate)
    : Account(accNo, std::move(name), balance), interestRate(rate) {}

// Destructor: currently empty, but included for proper cleanup if extended later.
SavingsAccount::~SavingsAccount() {}

// Returns a formatted string with all account information, including the base
// Account details and the savings account–specific interest rate.
std::string SavingsAccount::toString() {
    std::ostringstream strSavings;  // String builder for formatting output

    // Append base account info, then add savings-specific data.
    // The interest rate is multiplied by 100 to display it as a percentage.
    strSavings << Account::toString()
               << " [Type: Savings, Rate: "
               << std::fixed << std::setprecision(2)
               << (interestRate * 100) << "%]";

    return strSavings.str();  // Return the completed formatted string
}
