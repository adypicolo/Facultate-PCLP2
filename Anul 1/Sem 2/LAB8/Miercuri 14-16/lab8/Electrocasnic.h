#pragma once
#include <iostream>
#include <string>
#include "produs.h"
using namespace std;

class Electrocasnic : public Produs {
    protected:
        int nr_caracteristici;   //eg. 4
        string* caracteristici;  //eg. H=25, L=15, l=10, alb
        bool are_garantie;

    public:
    ///EX 1
         /// Constructor fara parametru
         Electrocasnic() {};

         /// Constructor cu parametrii
         Electrocasnic(char [], int , int , string*, bool) {};

         /// Functie pentru alocarea dinamica a stringului
         void setInfo(int nr, string *c) {
            nr_caracteristici = nr;
            delete []caracteristici;
            if (nr != 0){
                caracteristici = new string[nr];
                for (int i = 0; i < nr; i++)
                    caracteristici[i] = c[i];
            }
            else caracteristici = NULL;
         }

    ///EX 2
    ///Constructorul de copiere
    Electrocasnic(const Electrocasnic &) {};

    ///Operator=
    Electrocasnic& operator=(const Electrocasnic &) {};

    ///Destructor
    ~Electrocasnic() {};


    ///EX 3
    /// Functie de afisare
    void afisare() const {};

};

