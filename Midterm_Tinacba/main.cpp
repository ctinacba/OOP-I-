//
//       Name: Chelsy Tinacba
// Student ID: S00753660
//  File Name: main.cpp
//

#include <iostream>
#include <string>
#include <vector>

#include "Doctor.h"
#include "Patient.h"

using namespace std;

int main() {
    //Four Object Classes for Doctors
    Doctor docGen1{"Grey", Specialty::General};
    Doctor docGen2{"Webber", Specialty::General};
    Doctor docGen3{"Robbins", Specialty::Pediatrics};
    Doctor docGen4{"Karev", Specialty::Pediatrics};


    /* Student fills this part of the client. Create a patient object with at least three doctors
     * to the patients profile and setup billing information
     */

    Patient Rattler{"Rattler", "Man", Insurance::Medicare, Gender::Male,};

    //Show Error
    Rattler.setDoctor(docGen2);
    Rattler.setDoctor(docGen3);
    Rattler.setDoctor(docGen4);

    Rattler.updateBilling(100);
    cout << "Rattler Man's Bill is " << Rattler.getBilling() << endl;

    Rattler.updateBilling(700);
    cout << "Rattler Man's Bill is " << Rattler.getBilling() << endl;

}



