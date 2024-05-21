#pragma once
#include <iostream>
#include "produs.h"
using namespace std;

///1
/// Construcotr fara parametru
Produs::Produs():pret(0){
    for (int i = 0; i < 6; i++)
        cod[i] = '0';
}

/// Construcotr cu parametru
Produs::Produs(const char a[], const int p):pret(p){
    for (int i = 0; i < 6; i++)
        cod[i] = a[i];
}

///3
/// Functie de afisare
void Produs::afisare() const{
    cout << cod << " " << pret;
}

