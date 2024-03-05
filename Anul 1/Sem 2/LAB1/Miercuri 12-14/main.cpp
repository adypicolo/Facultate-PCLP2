/// Un supermarket dorește să țină evidenta pachetelor promoționale. Pachetul promotional are o
/// descriere, un cod, si un vector in care se salveaza preturile produselor incluse in pachet(max 5 produse).
/// Se dorește:
/// 1. ca acestea sa fie stocate într-un vector (alocat dinamic), datele despre ele să fie introduse de la
/// tastatură
/// 2. să fie afișate toate detaliile despre toate pachetele promoționale
/// 3. să se poată modifica datele unui pachet promotional, folosind ca parametru datele unui alt
/// pachet promotional
/// 4. să se poată modifica codul unui pachet promotional
/// 5. să se poată modifica prețul inițial pentru orice produs dintr-un pachet promotional
/// 6. să se sorteze în funcție diferenta dintre: suma prețurilor produselor componente și prețul
/// promotional

#include <iostream>
#include "pachet_promo.h"
using namespace std;

int main()
{
    ///1.
    Pachet_Promo *v;
    int n;

    cout << "1." << endl;
    cout << "Numarul de produse produse la care doriti sa tineti evidenta = "; cin >> n;

    v = new Pachet_Promo[n];

    for (int i = 0; i < n; i++){
        v[i].init();
        cout << "Nr. produs: " << i << endl;
        v[i].citire();
        cout << endl;
    }

    ///2.
    cout << endl << "2." << endl << "Afisare produse: " << endl;

    for (int i = 0; i < n; i++){
        cout << "Nr. produs: " << i << endl;
        v[i].afisare();
        cout << endl << endl;
    }

    ///3.
    int pp1, pp2;
    cout << "3." << endl;

    cout << "Pachet promotional #1: "; cin >> pp1;
    cout << "Pachet promotional #2: "; cin >> pp2;
    v[pp1].modificare(v[pp2]);
    v[pp1].afisare();

    ///4.
    int nrProd;
    char cod_nou[6];
    cout << endl << endl << "4." << endl;

    cout << "Produs = "; cin >> nrProd;
    cout << "Introduceti noul cod = "; cin >> cod_nou;
    v[nrProd].modificare(cod_nou);
    v[nrProd].afisare();

    ///5.
    int pret;
    cout << endl << endl << "5." << endl;

    cout << "Produs = "; cin >> nrProd;
    for (int i = 0; i < 5; i++){
        cin >> pret;
        v[nrProd].modificare(i, pret);
    }
    v[nrProd].afisare();

    ///6.
    cout << endl << endl << "6." << endl;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i].diferenta() < v[j].diferenta()){
                Pachet_Promo aux;
                aux.modificare(v[i]);
                v[i].modificare(v[j]);
                v[j].modificare(aux);
            }

    for (int i = 0; i < n; i++){
        cout << "Nr. produs: " << i << endl;
        v[i].afisare();
        cout << endl;
    }
}
///INPUT: 2 test 123450 1 2 3 4 5 bla 159870 1 5 9 8 7 0 1 0 111110 1 10 10 10 10 10 10

