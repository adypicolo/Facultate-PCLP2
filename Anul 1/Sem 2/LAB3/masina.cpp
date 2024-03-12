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

Masina& Masina::operator=(const Masina &b){
    delete []marca;
    if (this != &b){
        if (b.marca != NULL){
            this->marca = new char [strlen(b.marca)+1];
            strcpy(this->marca, b.marca);
        }
        else this->marca = NULL;
        strcpy(this->nr_inmatriculare, b.nr_inmatriculare);
        this->pret = b.pret;

        return *this;
    }
}

bool operator==(const Masina &a, const Masina &b){
    return ((strcmp(a.marca, b.marca) == 0) && (strcmp(a.nr_inmatriculare, b.nr_inmatriculare) == 0) && (a.pret == b.pret));
}

bool operator!=(const Masina &a, const Masina &b){
    return ((strcmp(a.marca, b.marca) != 0) && (strcmp(a.nr_inmatriculare, b.nr_inmatriculare) != 0) && (a.pret != b.pret));
}

void Masina::citire(){
    char aux[256];
    delete []marca;
    cout << "Marca = "; cin >> aux;
    if (marca == NULL){
        marca = new char[strlen(aux)+1];
        strcpy(marca, aux);
    }
    else marca = NULL;

    char nr_inmat[8];
    cout << "Nr inmatriculare = "; cin >> nr_inmat;
    strcpy(nr_inmatriculare,  nr_inmat);

    double pr;
    cout << "Pret = "; cin >> pr;
    pret = pr;
}

void sortare(Masina *v, int n){
    for (int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(v[i].marca, v[j].marca) > 0){
                Masina aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}
