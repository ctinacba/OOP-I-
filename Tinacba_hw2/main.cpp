// Name: Chelsy Tinacba
// Student ID: S00753660
// Assignment: CS2313 Homework 2

#include <iostream>
#include <iomanip>   /* Allows for setprecision function that will allow to choose how many decimal places to output*/
#include <limits>    /* for numeric_lmits*/
#include "MPGstats.h"
using namespace std;

int setTripAmt(void) {
    int lcv; /*Loop Control Variable*/
    cout << "How many trips will you log?:";

    /* Loops until user enters a  valid  integer */
    while (!(cin >> lcv)) {
        cout << "Invalid input. Please enter whole number: ";
        cin.clear();
        // Discards the line's of bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "You will run this program " << lcv <<" times." << endl;
    return lcv;
}

/*==========================================================================*/
/*Get the Users Miles and Gallons*/
/*==========================================================================*/
double getUserMiles(double userMi){
    cout << "Enter the amount of miles on your trip: ";

    /* Loops until user enters a  valid positive integer */
    while (!(cin >> userMi)) {
        cout << "Invalid input. Please enter positive whole number: ";
        cin.clear();
        // Discards the line's of bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return userMi;
}

double getUserGallon(double userGal) {
    cout << "Enter the amount of the gallons used: ";

    while (!(cin >> userGal || userGal <= 0)) {
        cout << "Invalid input. Please enter positive whole number: ";
        cin.clear();
        // Discards the line's of bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return userGal;
}
/*==========================================================================*/
/* Print Function */
/*==========================================================================*/
void summary(MPGStats user) {
    cout << "==================================================================" << endl;
    cout << " --- Fuel Efficiency Summary ---" << endl;
    cout << "Total Trips         |\t" << user.getTrips()        << endl;
    cout << "Total Miles         |\t" << user.getTotalMiles()   << endl;
    cout << "Total Gallons       |\t" << user.getTotalGallons() << endl;
    cout << "Best Trip MPG       |\t" << user.getBestMPG()      << endl;
    cout << "Overall MPG         |\t" << user.overAllMPG()      << endl;
    cout << "Best Trip MPG       |\t" << user.getBestMPG()      << endl;
    cout << "Worst Trip MPG      |\t" << user.getWorseMPG()     << endl;
    cout << "Low MPG Trips (<15) |\t" << user.getLowMPGCount()  << endl;
    cout << "==================================================================" << endl;
}

/*==========================================================================*/
/* Main Function */
/*==========================================================================*/
int main() {
    //Variables Used
    int t;                  /* How many trips to log */
    int lcv = 1;            /*Loop Control Variable*/
    double userMiles, userGallons;
    double calculatedMPG;   /*MPG*/
    MPGStats user1;         /*Object Created*/

    cout << "==================================================================" << endl;
    cout << "This program will calculate the miles per gallon (MPG) based off" <<endl;
    cout << "of the user's information." << endl;
    cout << "==================================================================" << endl;
    cout << "Phase 1" << endl;
    cout << "==================================================================" << endl;

    t = setTripAmt();

    while (lcv <= t) {
        /*Validates if the user enters a valid amount of miles and gallons*/
        do {
            userMiles = getUserMiles(userMiles);
            userGallons = getUserGallon(userGallons);
            calculatedMPG = user1.addTrip(userMiles,userGallons);
        }
        while (calculatedMPG == -1);
        cout << "Trip MPG: " << fixed << setprecision(2) << calculatedMPG << endl << endl;
        lcv++;
    }
    cout << "==================================================================" << endl;
    cout << "Phase 2" << endl;
    cout << "Enter -1 in miles if you would like to finish." << endl;
    cout << "==================================================================" << endl;

    do{
        userMiles = getUserMiles(userMiles);
        if (userMiles == -1)
            break;
        userGallons = getUserGallon(userGallons);
        calculatedMPG = user1.addTrip(userMiles,userGallons);
        cout << "Trip MPG: " << fixed << setprecision(2) << calculatedMPG << " for trip " << lcv << endl << endl;

    }while (calculatedMPG != 1);

    summary(user1);

    system("PAUSE");
    return 0;

}