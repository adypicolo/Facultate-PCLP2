#include <iostream>
#include "student.h"
#include <string.h>
using namespace std;

void Student::init(){
    id = 0;
    nume = NULL;
    strcpy(gr, "0000");
    for (int i = 0; i < 6; i++)
        note_sem_I[i] = 0;
}

void Student::afisare() const{
    cout << "ID: " << id << endl;
    cout << "Nume: ";
    if (nume != NULL) cout << nume;
    cout << endl;
    cout << "Grupa: " << gr;
    cout << endl;
    cout << "Note: ";
    for (int i = 0; i < 6; i++)
        cout << note_sem_I[i] << " ";
}

void Student::citire(){
    cout << "ID= "; cin >> id;

    cout << "Nume= ";
    char aux[100];
    cin >> aux;
    nume = new char[strlen(aux)+1];
    strcpy(nume, aux);

    cout << "Grupa= "; cin >> gr;

    cout << "Note= ";
    for (int i = 0; i < 6; i++)
        cin >> note_sem_I[i];
}

void Student::modificare(char grN[]){
    strcpy(gr, grN);
}

void Student::modificare(const Student &s){
    id = s.id;
    nume = new char[strlen(s.nume)+1];
    strcpy(nume, s.nume);
    strcpy(gr, s.gr);
    for (int i = 0; i < 6; i++)
        note_sem_I[i] = s.note_sem_I[i];
}

void Student::modificare(int poz, int nota){
    note_sem_I[poz] = nota;
}

double Student::medie(){
    double media=0;
    for (int i = 0; i < 6; i++)
        media += note_sem_I[i];
    return (double)(media/6);
}
