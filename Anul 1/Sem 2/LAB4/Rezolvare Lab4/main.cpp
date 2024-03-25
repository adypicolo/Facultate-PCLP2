#include <iostream>
#include <string.h>
#include "masina.h"
using namespace std;

int main()
{
    cout << "1." << endl;
    int n;
    Masina *v;
    cout << "Nr masini = "; cin >> n;
    v = new Masina[n];

    for (int i = 0; i < n; i++){
        cout << "Masina nr. " << i << endl;
        cin >> v[i];
        v[i].cateMasini();

    }

    cout << endl;
    for (int i = 0; i < n; i++){
        cout << "Masina nr. " << i << endl;
        cout << v[i] << endl;
    }

    ///2.
    cout << endl << "2." << endl;
    Masina m1("Audi", "B100ADY", 1000);
    m1.cateMasini();
    cout << "Sunt " << cautare(v, n, m1) << " egale in vectorul dat.";

    Masina minim = v[0];
    for (int i = 1; i < n; i++){
        if (minim < v[i]) minim = v[i];
    }

    for (int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] < v[j]){
                Masina aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    for (int i = 0; i < n; i++)
        cout << v[i];

}
