#pragma once
#include "Student.h"
#include "Angajat.h"
#include <string>
#include <iostream>
using namespace std;
class Student_Angajat:public Student, public Angajat{
    // venitul unui student angajat pe luna este
    // salariul + bursa (=700) sau 0 daca nu are bursa
    public:
        Student_Angajat() = default;
        Student_Angajat(string, int, int, int *, int , int);
        void afisare()const override;
        int getVenit()const override;
};
