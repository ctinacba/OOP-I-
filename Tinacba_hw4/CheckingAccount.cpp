// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: Homework 4: Inheritance & Polymorphism

#include "CheckingAccount.h"
#include <sstream>
#include <iomanip>

// Constructor: initializes a CheckingAccount by calling the base Account constructor
// and setting the additional fee specific to checking accounts.
CheckingAccount::CheckingAccount(int accNo, std::string name, double balance, double fee)
    : Account(accNo, std::move(name), balance), fee(fee) {}

// Destructor: currently empty, but declared for proper cleanup if needed later.
CheckingAccount::~CheckingAccount() {}

// Returns a formatted string including base account information,
// plus checking account–specific details like the account type and fee.
std::string CheckingAccount::toString() {
    std::ostringstream strChecking;  // String builder for formatting output

    // Reuse Account's toString() and append checking-specific information.
    strChecking << Account::toString()
        << " [Type: Checking, Fee: $" << std::fixed << std::setprecision(2) << fee << "]";

    return strChecking.str();  // Return final formatted string
}
