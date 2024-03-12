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

/*
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
*/

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
    /*
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
    */

}
