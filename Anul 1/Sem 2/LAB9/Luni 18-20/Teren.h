#pragma once
#include <iostream>
#include "Proprietate.h"
using namespace std;

class Teren : public Proprietate {
    double venit_pe_luna_m2; //venitul generat de imobil prin inchiriere pe //luna a unui metru patrat
    double suprafata; //in metrii patrati

    public:
        Teren() = default;
        Teren(int d[], double v, double vpl, double s): Proprietate(d,v),venit_pe_luna_m2(vpl),suprafata(s) {};
        void setInfo() {};
        ~Teren() {};

        ///3
        double getVenit(){
            return venit_pe_luna_m2;
        }

        ///5
        void afisare(){
            Proprietate::afisare();
            cout << venit_pe_luna_m2 << " " << suprafata;
        }


}; // venitul generat de un teren pe luna este venit_pe_luna_m2*suprafata
