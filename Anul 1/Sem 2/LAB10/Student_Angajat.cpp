#pragma once
#include "Student_Angajat.h"
#include <iostream>
using namespace std;

Student_Angajat::Student_Angajat(string nu, int ids, int m, int *no, int ida, int sal):Student(nu,ids,m,no),Angajat(nu,ida,sal),Persoana(nu) {}

void Student_Angajat::afisare() const{
    Student::afisare();
    cout << Angajat::getId() << " " << Angajat::getSalariu();
}

int Student_Angajat::getVenit() const{
    return Student::getVenit()+Angajat::getVenit();
}
