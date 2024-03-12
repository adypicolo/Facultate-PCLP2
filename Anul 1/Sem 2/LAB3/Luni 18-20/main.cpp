#include <iostream>
#include <string.h>
#include "masina.h"
using namespace std;

int cautare(const Masina *v, int n, const Masina &p){
    int contor = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == p) contor++;

    return contor;
}

void adaugare(Masina * &v, int &n, const Masina &p){
    bool ok = true;
    for (int i = 0; i < n; i++)
        if (v[i] == p){
            ok = false;
            break;
        }

    if (ok == true){
        Masina *aux;
        n++;
        aux = new Masina[n];
        for (int i = 0; i < n-1; i++)
            aux[i] = v[i];
        aux[n-1] = p;
        delete []v;
        v = aux;
    }
}

void elimina(Masina * &v, int &n){
    for (int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] == v[j]){
                for (int k = j; k < n-1; k++)
                    v[k] = v[k+1];
                n--;
                j--;
            }


    Masina *aux = new Masina[n];
    delete []v;
    for (int i = 0; i < n; i++)
        aux[i] = v[i];
    v = aux;
}

int main()
{
    ///1.
    cout << "1." << endl;
    int n;
    Masina *v;
    cout << "Nr masini = "; cin >> n;
    v = new Masina[n];

    for (int i = 0; i < n; i++){
        cout << "Masina nr. " << i << endl;
        v[i].citire();

    }

    cout << endl;
    for (int i = 0; i < n; i++){
        cout << "Masina nr. " << i << endl;
        v[i].afisare();
        cout << endl;
    }

    ///2.
    cout << endl << "2." << endl;
    Masina m1("Audi", "B100ADY", 1000);
    cout << "Sunt " << cautare(v, n, m1) << " egale in vectorul dat.";

    ///3.
    cout << endl << "3." << endl;
    sortare(v, n);
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << "Masina nr. " << i << endl;
        v[i].afisare();
        cout << endl;
    }

    ///4.
    cout << endl << "4." << endl;
    Masina m2("MERCEDES", "MM69PKB", 14556);
    adaugare(v, n, m2);

    cout << endl;
    for (int i = 0; i < n; i++){
        cout << "Masina nr. " << i << endl;
        v[i].afisare();
        cout << endl;
    }

    ///BONUS
    cout << endl << "BONUS" << endl;
    elimina(v, n);

    cout << endl;
    for (int i = 0; i < n; i++){
        cout << "Masina nr. " << i << endl;
        v[i].afisare();
        cout << endl;
    }
    /// INPUT: 3 Audi B100ADY 1000 BMW MM10ADY 1598 DACIA CL69CLR 66666
}
