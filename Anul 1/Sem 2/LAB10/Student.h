#pragma once
#include "Persoana.h"
class Student: virtual public Persoana {
        int id_student = 0; // unic pentru fiecare persoana de acest tip
        int n = 0; //nr. note pe baza carora se calculeaza media
        int *note = NULL; // vectorul in care se stocheaza cele n note
        // media studentului e suma notelor/n;
        // daca media > 8.5 si nu are note < 5 atunci are bursa
        // venitul unui student pe luna e bursa (= 700)
        // sau 0 daca nu are bursa
    public:
        Student();
        Student(string , int , int , int *);
        Student& operator=(const Student &);
        Student(const Student &);
        ~Student();
        void setInfo(int, int *);
        void afisare() const;
        int getVenit() const;
};
