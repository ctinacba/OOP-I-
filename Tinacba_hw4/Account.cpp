// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: Homework 4: Inheritance & Polymorphism

#include "Account.h"
#include <sstream>
#include <iomanip>


// Constructor
Account::Account(int accNo, std::string name, double balance)
    : accountNo(accNo), name(std::move(name)), balance(balance) {}

/*Destructor*/
Account::~Account() {}


/*Prints out Client Information*/
std::string Account::toString() {
    std::ostringstream strClient;
    strClient << "Account No: " << accountNo
        << " | Name: " << name
        << " | Balance: $" << std::fixed << std::setprecision(2) << balance;
    return strClient.str();
}