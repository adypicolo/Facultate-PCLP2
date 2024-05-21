#pragma once
#include <iostream>
#include <string>
#include "Electrocasnic.h"
#include "produs.h"
using namespace std;

///1.
/// Constructor fara parametrii
Electrocasnic::Electrocasnic():nr_caracteristici(0),caracteristici(NULL),are_garantie(false) {}

/// Constructor cu parametrii
Electrocasnic::Electrocasnic(char a[], int p, int nc, string* c, bool ag):Produs(a, p), nr_caracteristici(nc), are_garantie(ag){
    setInfo(nc, c);
}

///2.
///Constructor de copiere
Electrocasnic::Electrocasnic(const Electrocasnic &b): Produs(b.cod, b.pret){
    nr_caracteristici = b.nr_caracteristici;
    setInfo(b.nr_caracteristici, b.caracteristici);
    are_garantie = b.are_garantie;

}

///Operator=
Electrocasnic& Electrocasnic::operator=(const Electrocasnic &b){
    if (this != &b){
        for (int i = 0; i < 6; i++)
            cod[i] = b.cod[i];
        pret = b.pret;
        setInfo(b.nr_caracteristici, b.caracteristici);
    }
    return *this;
}

///Destructor
Electrocasnic::~Electrocasnic(){
    delete []caracteristici;
}


///3
/// Functie de afisare
void Electrocasnic::afisare() const{
    Produs::afisare();
    cout << nr_caracteristici << " ";
    for (int i = 0; i < nr_caracteristici; i++)
        cout << caracteristic[i] << " ";
    if (are_garantie == false) cout << "Nu";
        else cout << "Da";
}
