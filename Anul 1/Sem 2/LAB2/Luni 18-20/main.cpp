#include <iostream>
#include <string.h>
#include "masina.h"
using namespace std;

///Functie pentru determinarea numarului de masini care au acelasi judet
int inmatriculare(Masina *vec, int n, char judet[]){
    int contor = 0;
    for (int i = 0; i < n; i++)
        if (strncmp(vec[i].getNr_Inmatriculare(), judet, 2) == 0)
            contor++;
    return contor;
}

Masina cms(Masina *vec, int n){
    int contor = 0;
    for (int i = 1; i < n-1; i++)
        if (vec[contor].getPret() < vec[i].getPret())
            contor = i;
    return vec[contor];
}

void sortare(Masina *vec, int n){
    for (int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(vec[i].getMarca(), vec[j].getMarca()) < 0){
                Masina x(vec[i]);
                Masina aux; aux.copie(x);
                vec[i].copie(vec[j]);
                vec[j].copie(aux);
            }
}

int main()
{

    /* TEST PASSED
    Masina m;
    Masina m1("audi", "B123ABC", 5000);
    Masina m2(m1); //constr de copiere
    m2.afisare();
    m.copie(m2); //in m se stocheaza o copie profunda a lui m2
    m2.afisare();
    m2.copi
    */

    ///1.
    cout << "1." << endl;
    int n;
    Masina *v;
    cout << "Nr masini = "; cin >> n;
    v = new Masina[n];

    ///Citirea datelor de la tastatura
    char nr_inmat[8];
    double pr;

    for (int i = 0; i < n; i++){
        cout << "Masina nr. " << i << endl;
        char aux[256];
        cout << "Marca = "; cin >> aux;
        cout << "Nr inmatriculare = "; cin >> nr_inmat;
        cout << "Pret = "; cin >> pr;
        Masina x(aux, nr_inmat, pr);
        v[i].copie(x);
    }

    ///2.
    ///Afisarea datelor din vector
    cout << endl << "2." << endl;
    for (int i = 0; i < n; i++){
        cout << "Masina nr. " << i << endl;
        v[i].afisare();
    }

    ///3.
    cout << endl << "3." << endl;
    char judet[2];
    cout << "Judet = "; cin >> judet;
    cout << "Sunt " << inmatriculare(v, n, judet) << " cu acelasi judet.";

    ///4.
    cout << endl << "4." << endl;
    cms(v, n).afisare();

    ///5.
    cout << endl << "5. " << endl;
    sortare(v, n);
}
