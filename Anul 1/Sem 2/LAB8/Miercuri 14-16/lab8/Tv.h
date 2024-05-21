#pragma once
#include <iostream>
#include <string>
#include "Electrocasnic.h"
using namespace std;

class TV: public Electrocasnic {
     double diagonala;
     string info_suplimentare; //eg. OLED

     public:
    ///EX 1
    /// Constructor fara parametru
    TV();

    /// Constructor cu parametrii
    TV(double, string, char [], int, int, string*, bool) {};

    ///EX 3
    ///Functie de afisare
    void afisare() const {}

    ///EX 5
    friend istream& operator>>(istream &, TV &){};



};
