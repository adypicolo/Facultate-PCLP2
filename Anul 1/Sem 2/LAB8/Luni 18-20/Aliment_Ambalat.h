#pragma once
#include "Aliment.h"
#include <string>
#include <iostream>
using namespace std;

class Aliment_Ambalat: public Aliment {
    string tip_ambalaj; // ex. carton
    bool ambalaj_reciclabil;

    public:
        ///1.
        Aliment_Ambalat(string m, int p, int nr, string *info, string tip, bool ambalaj):tip_ambalaj(tip),ambalaj_reciclabil(ambalaj), Aliment(m, p, nr, info){}

        ///3.
        void afisare() const{
            Aliment::afisare();
            cout << endl << "Tip Ambalaj= " << tip_ambalaj << endl;
            (ambalaj_reciclabil == 0) ? cout << "Reciclabil = Nu" : cout << "Reciclabil = Da";
        }

        friend istream& operator>>(istream &dev, Aliment_Ambalat &a){
            cout << "Marca= "; dev >> a.marca;
            cout << "Pret= "; dev >> a.pret;
            cout << "Nr info = "; dev >> a.nr_info;
            for (int i = 0; i < a.nr_info; i++)
                dev >> a.informatii[i];
            cout << "Tip Ambalaj= "; dev >> a.tip_ambalaj;
            cout << "Este reciclabil= "; dev >> a.ambalaj_reciclabil;

            return dev;
        }

        ///5.
        ///Constructor fara parametru
        Aliment_Ambalat():tip_ambalaj(" "),ambalaj_reciclabil(0){}
        Aliment_Ambalat& operator=(const Aliment_Ambalat &a){
            if (this != &a){
                marca = a.marca;
                pret = a.pret;
                Aliment::setInfo(a.nr_info, a.informatii);
                tip_ambalaj = a.tip_ambalaj;
                ambalaj_reciclabil = a.ambalaj_reciclabil;
            }

            return *this;
        }

        friend bool operator>(const Aliment_Ambalat &a, const Aliment_Ambalat &b){
            if (a.marca < b.marca) return 1;
                else return 0;
        }

        ///6.
        bool getAmbalajReciclabil() const{
            return ambalaj_reciclabil;
        }
};
