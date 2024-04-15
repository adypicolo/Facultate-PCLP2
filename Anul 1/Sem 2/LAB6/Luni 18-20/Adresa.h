#pragma once
#include <string>
#include <ostream>
using namespace std;

class Adresa
{
    string oras;
    string strada;
    int nr;
public:
    Adresa() = default;
    Adresa(const string &, const string &, int);
    friend ostream& operator<<(ostream&, const Adresa &);
    friend istream& operator>>(istream&,  Adresa &);
    //se genereaza in mod automat constructor de copiere, operator=, destructor - si functioneaza corect
    string getOras() const;
    string getStrada() const;
    int getNr() const;
};
