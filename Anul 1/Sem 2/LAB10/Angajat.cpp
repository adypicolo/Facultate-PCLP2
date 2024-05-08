#pragma once
#include <iostream>
#include "Angajat.h"
using namespace std;

Angajat::Angajat():id_angajat(0),salariu(0){};

Angajat::Angajat(string n, int id, int sal):Persoana(n),id_angajat(id),salariu(sal){};

void Angajat::afisare() const{
    Persoana::afisare();
    cout << id_angajat << " " << salariu;
}

int Angajat::getVenit() const{
    return salariu;
}

int Angajat::getId() const{
    return id_angajat;
}

int Angajat::getSalariu() const{
    return salariu;
}


