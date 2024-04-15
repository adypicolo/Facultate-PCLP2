#pragma once
#include <iostream>
#include <string>
using namespace std;

class Produs{
    protected:
        string marca;
        int pret;
    public:
        ///1.
        Produs(string m, int p):marca(m),pret(p) {}

        ///3.
        void afisare() const{
            cout << "Marca= " << marca << endl;
            cout << "Pret= " << pret << endl;
        }

        ///5.
        Produs():marca(" "),pret(0){}

        ///6.
        int getPret() const{
            return pret;
        }
};
