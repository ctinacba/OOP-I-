// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: CS2313 Homework 1

#include <iostream>
#include <string>
using namespace std;



class Student {
//=====================================================================================
private:
    string name;
    int age;
    double gpa;
//-------------------------------------------------------------------------------------
public:
    Student(string uiName, int  uiAge, double uiGPA) {
        name = uiName;


        // Validation for User
        if (uiAge > 0)
            age = uiAge;
        else
            age = 0;

        if (uiGPA > 0.0 && uiGPA < 4.0)
            gpa = uiGPA;
        else
            gpa = 0.0;
    }

//=====================================================================================
    /*Set Methods for Private Variable*/
    void setName(string uiName) {
        name = uiName;
    }

    void setAge(int uiAge) {
        if (uiAge > 0)
            age = uiAge;
        else
            age = 0;
    }

    void setGpa(double uiGPA) {
        if (uiGPA > 0.0 && uiGPA < 4.0)
            gpa = uiGPA;
        else
            gpa = 0;
    }
//-------------------------------------------------------------------------------------
    /*Get Method for Private Variables*/
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getGpa() const {
        return gpa;
    }
//=====================================================================================
    /*Other Methods*/
    bool isAdult() const{
        if (age >= 18)
            return true;
        return false;
    }

    bool eligibleForScholarship() const {
        if (gpa >= 3.5)
            if (age <= 25)
                return true;
        return false;
    }

    // Calculates the weekly average based off the user input
    void calculateWeeklyStudyAverage() const {
        char week[5] = // For Printing out what day to user
        { 'M','T','W','R', 'F' };
        int hour;   // User Input
        double avg; // Average Between all UI

        cout <<"\n";
        for (int i = 0; i < 5;i++) {
            cout << "How many hours did " << name << " study on " << week[i] << "?";
            cin >> hour;
            avg = avg + hour;
        }
        avg = avg/5;
        cout << "The average amount "<< name << " studied this week is: " << avg << endl <<endl;
    }

    void  printInfo() const {
        cout << "Student Name: " << name << " Age: " << age << " GPA: " << gpa << endl;
    }
};

