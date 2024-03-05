#include "masina.h"
#include <iostream>
#include <string.h>
using namespace std;

Masina::Masina(){
    marca = NULL;
    strcpy(nr_inmatriculare, "0000000");
    pret = 0.0;
}

Masina::Masina(char *mar, char nr_in[], double p){
    if (mar != NULL){
        marca = new char[strlen(mar)+1];
        strcpy(marca, mar);
    }
    else marca = NULL;
    strcpy(nr_inmatriculare, nr_in);
    pret = p;
}

Masina::Masina(const Masina &vec){
    delete []vec.marca;
    if (vec.marca != NULL){
    marca = new char[strlen(vec.marca)+1];
    strcpy(marca, vec.marca);
    }
    else marca = NULL;
    strcpy(nr_inmatriculare, vec.nr_inmatriculare);
    pret = vec.pret;
}

Masina::~Masina(){
    delete []marca;
    delete []nr_inmatriculare;
}

void Masina::afisare() const{
    if (marca != NULL) cout << "Marca: " << marca << endl;
        else cout << "Marca: NULL" << endl;
    cout << "Nr inmatriculare: " << nr_inmatriculare << endl;
    cout << "Pret: " << pret << endl;
}

void Masina::copie(const Masina &vec){
    delete []vec.marca;
    if (vec.marca != NULL){
        marca = new char[strlen(vec.marca)+1];
        strcpy(marca, vec.marca);
    }
    else marca = NULL;
    strcpy(nr_inmatriculare, vec.nr_inmatriculare);
    pret = vec.pret;
}

double Masina::getPret() const{
    return pret;
}

char* Masina::getNr_Inmatriculare(){
    return nr_inmatriculare;
}

char* Masina::getMarca(){
    return marca;
}
