#include "Adresa.h"
#include <iostream>
using namespace std;
Adresa::Adresa(const string &o, const string &s, int n):oras(o), strada(s), nr(n)
{
}
ostream& operator<<(ostream& dev, const Adresa &a)
{
    dev<<a.oras<<" "<<a.strada<<" "<<a.nr<<endl;
    return dev;
}
istream& operator>>(istream &dev, Adresa &a)
{
    dev>>a.oras;
    dev>>a.strada;
    dev>>a.nr;
    return dev;
}

string Adresa::getOras() const{
    return oras;
}

string Adresa::getStrada() const{
    return strada;
}
int Adresa::getNr() const{
    return nr;
}
