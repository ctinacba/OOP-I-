/**************************************************************/
//
// Student ID: S00753660
//  File Name: Patient.h
//       Name: Chelsy Tinacba
//
/**************************************************************/
//IF NOT DEFINED
#ifndef MIDTERMAKTAR_PATIENT_H
#define MIDTERMAKTAR_PATIENT_H
    #include <iostream>
    #include <string>
    #include <vector>
    #include "Doctor.h"

/**************************************************************/
enum class Insurance{Medicare, BCBS, Aetna};
enum class Gender{Female, Male};
/**************************************************************/
class Patient {
private: /*Variables For Patient Object*/
    std::string firstName;
    std::string lastName;
    double bill;
    const static int MaxDoctors = 2;
    Insurance insurance;
    Gender gender;
    std::vector<Doctor> doctors;
/**************************************************************/
public:
/**************************************************************/
    // Constructors
    Patient(std::string pFName, std::string pLName, Insurance pInsurance, Gender pGender) {
        firstName = pFName;
        lastName = pLName;
        bill = 0.0;

        insurance = pInsurance;
        gender = pGender;
    }
/**************************************************************/
    /* Functions/Methods*/
    /***************************************/
    // Add Doctors IF there is
    void setDoctor(const Doctor& doc) {
        if (doctors.size() == MaxDoctors) {
            std::cout << "[ERROR] 2 DOCTORS ONLY ALLOWED TO ONE PATIENT." << std::endl;
        }
        else {
            doctors.push_back(doc);
        }
    }

    /***************************************/
    // Updates Billing for Patient
        void updateBilling(double amount) {
        bill += amount;
    }
    /***************************************/
    // Get Billing for Patient
        double getBilling(void) const {

            if (insurance == Insurance::Medicare )
                if (bill > 200)
                    return bill-200;
            if (insurance == Insurance::BCBS || insurance == Insurance::Aetna)
                if (bill > 500)
                    return bill-500;
            return bill;
        }

};
/**************************************************************/
#endif //MIDTERMAKTAR_PATIENT_H