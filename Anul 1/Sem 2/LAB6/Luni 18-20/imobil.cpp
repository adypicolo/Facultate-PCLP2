#include "imobil.h"
#include <iostream>
#include <string>
using namespace std;

Imobil::Imobil():adr(" "," ",0),nr(0),imbunatatiri(NULL) {}

Imobil::Imobil(const Adresa &a, int n, string *imb):adr(a),nr(n) {
    setImbunatatiri(imb, n);
}

Imobil::Imobil(const Imobil &i):adr(i.adr),nr(i.nr){
   setImbunatatiri(i.imbunatatiri, i.nr);
}

Imobil& Imobil::operator=(const Imobil &i){
    if (this != &i){
        adr = i.adr;
        nr = i.nr;
        delete []imbunatatiri;
        setImbunatatiri(i.imbunatatiri, i.nr);
    }
    return *this;
}

Imobil::~Imobil(){
    delete []imbunatatiri;
}

ostream& operator<<(ostream &dev, const Imobil &i){
    dev << i.adr << " " << i.nr << " ";
    if (i.nr > 0)
        for (int j = 0; j < i.nr; j++)
            dev << i.imbunatatiri[j] << " ";
    dev << endl;

    return dev;
}

istream& operator>>(istream &dev,  Imobil &i){
    dev >> i.adr;
    dev >> i.nr;
    delete [] i.imbunatatiri;
    i.imbunatatiri = new string[i.nr];
    if (i.nr > 0){
        for (int j = 0; j < i.nr; j++)
            dev >> i.imbunatatiri[j];
    }
    return dev;
}

void Imobil::setImbunatatiri (string *v, int n){
    if (n > 0){
        if (v != NULL){
            imbunatatiri = new string[n];
            for (int j = 0; j < n; j++)
                imbunatatiri[j] = v[j];
        } else imbunatatiri = NULL;
    } else imbunatatiri = NULL;
}

bool Imobil::seGaseste(string ora){
    return adr.getOras() == ora;
}

bool operator==(const Imobil &a, const Imobil &b){
    if (
         (a.adr.getOras() == b.adr.getOras()) &&
         (a.adr.getStrada() == b.adr.getStrada()) &&
         (a.adr.getNr() == b.adr.getNr()) && (a.nr == b.nr)
       ){

        for (int k = 0; k = a.nr; k++)
            if (a.imbunatatiri[k] != b.imbunatatiri[k]) return 0;

    } else return 0;
    return 1;
}

bool operator!=(const Imobil &a, const Imobil&b){
    return !(a==b);
}
