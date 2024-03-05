#include "pachet_promo.h"
#include <iostream>
#include <string.h>
using namespace std;

void Pachet_Promo::init(){
    descriere = NULL;
    strcpy(cod, "000000");
    for (int i = 0; i < 5; i++)
        pret_initial_produse_continute[i]= 0;
}


void Pachet_Promo::citire(){
    char aux[256];
    cout << "Descriere produs = "; cin >> aux;
    descriere = new char[strlen(aux)+1];
    strcpy(descriere, aux);

    cout << "Cod produs = "; cin >> cod;

    cout << "Pret initial produse = ";
    for (int i = 0; i < 5; i++)
        cin >> pret_initial_produse_continute[i];
}

void Pachet_Promo::afisare() const{
    cout << "Descriere produs: " << descriere << endl;
    cout << "Cod produs: " << cod << endl;
    cout << "Pret initial produse: ";
    for (int i = 0; i < 5; i++)
        cout << pret_initial_produse_continute[i] << " ";
}

void Pachet_Promo::modificare(char cod_nou[]){
    strcpy(cod, cod_nou);
}

void Pachet_Promo::modificare(const Pachet_Promo &produs_anterior){
    descriere = new char[strlen(produs_anterior.descriere)+1];
    strcpy(descriere, produs_anterior.descriere);

    strcpy(cod, produs_anterior.cod);

    for (int i = 0; i < 5; i++)
        pret_initial_produse_continute[i] = produs_anterior.pret_initial_produse_continute[i];
}

void Pachet_Promo::modificare(int poz, int pret){
    pret_initial_produse_continute[poz] = pret;
}

double Pachet_Promo::diferenta(){
    double suma = 0;
    for (int i = 0; i < 5; i++)
        suma += pret_initial_produse_continute[i];
    return (double)(suma-(0.4*suma));
}



