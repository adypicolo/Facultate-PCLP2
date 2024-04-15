#include <iostream>
#include <string>
#include "Aliment.h"
#include "Produs.h"
#include "Aliment_Ambalat.h"
using namespace std;

void sortare (Aliment_Ambalat *&a, int n){
    for (int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                Aliment_Ambalat aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
}

void AfisareSpecifica(Aliment_Ambalat *&a, int n){
    for (int i = 0; i < n; i++)
        if (a[i].getPret() > 10 && a[i].getnrInfo() > 10 && a[i].getAmbalajReciclabil() == true)
            a[i].afisare();
}

int main()
{
    ///4.
    string *test;
    test = new string[2];
    test[0] = "230cal/100g";
    test[1] = "12.12.2024";

    Produs m("iPhone", 1000);
    Aliment a("Mere", 3, 2, test);
    Aliment_Ambalat AA("Monitor", 1500, 2, test, "Carton", 1);

    cout << "4." << endl << "AFISARE PRODUS: " << endl;
    m.afisare();
    cout << endl;

    cout << "AFISARE ALIMENT: " << endl;
    a.afisare();
    cout << endl << endl;

    cout << "AFISARE ALIMENT AMBALAT: " << endl;
    AA.afisare();
    cout << endl;

    ///5.
    cout << endl << "5." << endl;
    Aliment_Ambalat *v;
    int n;
    cout << "n= "; cin >> n;
    v = new Aliment_Ambalat[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sortare(v, n);

    for (int i = 0; i < n; i++){
        cout << "Produsul " << i << endl;;
        v[i].afisare();
        cout << endl;
    }

    ///6.
    AfisareSpecifica(v, n);
}
