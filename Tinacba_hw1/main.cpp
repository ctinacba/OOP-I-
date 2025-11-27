// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: CS2313 Homework 1

#include <iostream>
#include <string.h>
#include "Student.h"
using namespace std;

int main() {
//-------------------------------------------------------------------------------------
    // Variables Used
    double uiGpa; //User Input = (UI)
    string uiName;  // User Input Name
    string rmSpace; // Remove Extra Space for Get Line
    Student student1("Jane Doe",18, 3.89 ); // Valid Inputs
    Student student2("John Doe", -10, 5.05); // Invalid Inputs
//-------------------------------------------------------------------------------------
    // Prints Student Information
    student1.printInfo();
    student2.printInfo();
//-------------------------------------------------------------------------------------
    // Assess if Adult or Not
    if (student1.isAdult())
        cout <<  student1.getName() << " is an adult." << endl;
    else
        cout << student1.getName() << " is not an adult." << endl;

    if (student2.isAdult())
        cout <<  student2.getName() << " is an adult." << endl;
    else
        cout << student2.getName() << " is not an adult." << endl;
//-------------------------------------------------------------------------------------
    //Check Eligible for Scholarship for Students
    if (student1.eligibleForScholarship())
        cout << student1.getName() << " is eligible for scholarship!" << endl;
    else
        cout << student1.getName() << " is ineligible for a scholarship." << endl;

    if (student2.eligibleForScholarship())
        cout << student2.getName() << " is eligible for a scholarship!" << endl;
    else
        cout << student2.getName() << " is ineligible for a scholarship." << endl;
//-------------------------------------------------------------------------------------
    // Calculates Average
    student1.calculateWeeklyStudyAverage();
//-------------------------------------------------------------------------------------
    // User Input with 3rd Students

    getline(cin, rmSpace); // Grabs the extra line from the previous to allow for grabbing the full name WITH space

    cout << "Enter Student's Name: ";
    getline(cin, uiName);

    cout << "Enter Student's GPA: ";
    cin >> uiGpa;

    Student  student3(uiName, 0, uiGpa);

    student3.setAge(18);
    student3.printInfo();

    if (student3.isAdult())
        cout <<  student3.getName() << " is an adult." << endl;
    else
        cout << student3.getName() << " is not an adult." << endl;

    if (student3.eligibleForScholarship())
        cout << student3.getName() << " is eligible for a scholarship. :)" << endl;
    else
        cout << student3.getName() << " is ineligible for a scholarship! Work harder!" << endl;

    student3.calculateWeeklyStudyAverage();

    return 0;
}


