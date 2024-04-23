#include <iostream>
#include <string>
#include "Imobil.h"
using namespace std;

Imobil::Imobil():venit_pe_an(0),nr(0),imbunatatiri(NULL){ }

Imobil::Imobil(int d[], double v, double vpa, int n, string *imb):Proprietate(d,v),venit_pe_an(vpa){
    imbunatatiri=NULL;
    setInfo(n, imb);
}

void Imobil::setInfo(double n, string *imb){
    nr = n;
    delete []imbunatatiri;
    if (nr != 0){
        imbunatatiri = new string[nr];
        for (int i = 0; i < nr; i++)
            imbunatatiri[i] = imb[i];
    } else imbunatatiri = NULL;
}

///Constructor de copiere
Imobil::Imobil(const Imobil &n){
     for (int i = 0; i < 3; i++)
        data_dobandire[i] = n.data_dobandire[i];
    valoare = n.valoare;
    venit_pe_an = n.venit_pe_an;
    setInfo(n.nr, n.imbunatatiri);
}

///Operator=
Imobil& Imobil::operator=(const Imobil &n){
    for (int i = 0; i < 3; i++)
        data_dobandire[i] = n.data_dobandire[i];
    valoare = n.valoare;
    venit_pe_an = n.venit_pe_an;
    setInfo(n.nr, n.imbunatatiri);

    return *this;
}

///Destructor
Imobil::~Imobil(){
    delete []imbunatatiri;
}

double Imobil::getVenit(){
    return (double)(venit_pe_an/12);
}

void Imobil::afisare(){
    Proprietate::afisare();
    cout << venit_pe_an << " " << nr << " ";
    for (int i = 0; i < 2; i++)
        cout << imbunatatiri[i] << " ";
}

