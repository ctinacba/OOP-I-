/**************************************************************/
//
//       Name: Chelsy Tinacba
// Student ID: S00753660
//  File Name: Doctor.h
//
/**************************************************************/
#ifndef MIDTERMAKTAR_DOCTOR_H //IF NOT DEFINED
#define MIDTERMAKTAR_DOCTOR_H
    #include <iostream>
    #include <string>

/**************************************************************/
enum class Specialty {
    General,Pediatrics
};

/**************************************************************/
class Doctor{
private:
    /*Variable Types*/
    std::string lastName;       //Doctor Names
    Specialty specialty;  //The Specialty of the Doctor
    /**************************************************************/
public:
    //Overloaded Constructor
    Doctor(std::string userlN, Specialty specials) {
        lastName = userlN;
        specialty = specials;
    }
/********************************************/
    //Struggled to print out enum so added this
    std::string getSpecialtyName() const {
         switch (specialty) {
             case Specialty::General: return "General";
             case Specialty:: Pediatrics: return "Pediatrics";

         }
    }

    void printDoctor() {

        std::cout << "Name: " << lastName << " | Specialty: " << getSpecialtyName() << std::endl;
    }

};
#endif //MIDTERMAKTAR_DOCTOR_H




