#pragma once
#include <string>
#include <iostream>
using namespace std;

class Persoana{
    protected:
        string nume;
    public:
        Persoana() = default;
        Persoana(string);
        virtual void afisare() const;
        virtual int getVenit() const = 0;
        virtual ~Persoana() {}
};
