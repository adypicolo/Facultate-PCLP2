#pragma once
#include <iostream>
using namespace std;

class Produs {
    protected:
        char cod[6];
        int pret;

    public:
    ///1
    /// Constructor fara parametrii
    Produs();

    /// Constructor cu parametrii
    Produs(const char [], const int);

    ///3
    /// Functie de afisare
    void afisare() const {};


};
