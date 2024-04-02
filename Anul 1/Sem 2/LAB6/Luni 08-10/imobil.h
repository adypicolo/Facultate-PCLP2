#pragma once
#include "Adresa.h"

class Imobil {
    Adresa adr;
    int nr; //cate imbunatatiri are
    string *imbunatatiri; //vector cu imbunatatile: centrala, termopan, izolatie
public:
    Imobil();
    Imobil(const Adresa&, int, string *);
    Imobil(const Imobil&);
    Imobil& operator=(const Imobil&);
    ~Imobil();
    friend ostream& operator<<(ostream&, const Imobil &);
    friend istream& operator>>(istream&,  Imobil&);
    void setImbunatatiri(string *, int);
    bool seGaseste(string);
    friend bool operator==(const Imobil &, const Imobil &);
    friend bool operator!=(const Imobil &, const Imobil &);
};
