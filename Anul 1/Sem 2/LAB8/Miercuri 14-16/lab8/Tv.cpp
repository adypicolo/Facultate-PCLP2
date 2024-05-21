#pragma once
#include <iostream>
#include <string>
#include "produs.h"
#include "Electrocasnic.h"
#include "Tv.h"
using namespace std;

///EX 1
/// Constructor fara parametru
TV::TV():diagonala(0),info_suplimentare("") {}

/// Constructor cu parametrii
TV::TV(double d, string is, char a[], int p, int nc, string* c, bool ag):diagonala(d),info_suplimentare(is), Electrocasnic(nc, c, ag) {};

///Ex 3
/// Functie de afisare
void TV::afisare() const{
    Electrocasnic::afisare();
    cout << diagonala << " " << info_suplimentare;
}

///EX 5
istream& operator>>(istream &dev, TV &a){
    dev >> a.cod;
    dev >> a.pret;

    dev >> a.nr_caracteristici;
    for (int i = 0; i < a.nr_caracteristici; i++)
        dev >> caracteristici[i];
    dev >> a.are_garantie;

    dev >> a.diagonala;
    dev >> a.info_suplimentare;

}
