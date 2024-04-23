#pragma once
#include <iostream>
#include <string>
#include "Proprietate.h"
using namespace std;

class Imobil : public Proprietate {
    double venit_pe_an = 0; //venitul generat de imobil prin inchiriere pe an
    int nr = 0; // cate imbunatatiri are
    string *imbunatatiri = NULL; // lista cu imbunatatiri,ex:“centrala”,“termopan”

    public:
        ///1
        Imobil();
        Imobil(int [], double , double , int , string *);
        void setInfo(double, string *);

        ///2
        ///Constructor de copiere
        Imobil(const Imobil &);

        ///Operator=
        Imobil& operator=(const Imobil &);

        ///Destructor
        ~Imobil();

        ///4
        double getVenit();

        ///5
        void afisare();

}; // venitul generat de un imobil pe luna este venit_pe_an/12
