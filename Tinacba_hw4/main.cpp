// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: Homework 4: Inheritance & Polymorphism

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main() {
    // Open the input file containing client account information
    ifstream infile("./clients.txt");
    if (!infile) {
        cerr << "Failed to open clients.txt\n";
        return 1;  // Exit program if file cannot be opened
    }

    vector<Account*> accounts;  // Store pointers to Account objects (polymorphism)
    char type;                  // Indicates whether an account is Savings ('S') or Checking ('C')

    // Read and process each record from the file
    while (infile >> type) {
        int accNo;
        string name;
        double balance;
        double lastVal;  // Interest rate (Savings) OR fee (Checking)

        // Validate the rest of the line
        if (!(infile >> accNo >> name >> balance >> lastVal)) {
            cerr << "Malformed line in input file.\n";
            break;  // Stop reading if a line is incomplete
        }

        // Create the appropriate type of account based on the 'type' character
        if (type == 'S') {
            accounts.push_back(new SavingsAccount(accNo, name, balance, lastVal));
        }
        else if (type == 'C') {
            accounts.push_back(new CheckingAccount(accNo, name, balance, lastVal));
        }
        else {
            cerr << "[ERROR] Unknown Account Type, Please try again" << type << "\n";
        }
    }

    // Print the information for all accounts
    for (Account* a : accounts) {
        cout << a->toString() << endl;
    }

    // Cleanup: delete dynamically allocated account objects
    for (Account* a : accounts)
        delete a;

    accounts.clear();  // Not required, but good practice

    return 0;
}
