#pragma once
#include "Persoana.h"
class Angajat: virtual public Persoana {
        int id_angajat; // unic pentru fiecare persoana de acest tip
        int salariu;
        // venitul unui angajat pe luna e salariul
    public:
        Angajat();
        Angajat(string , int , int);
        ~Angajat() = default;
        void afisare() const;
        int getVenit() const;
        int getId() const;
        int getSalariu() const;
};

