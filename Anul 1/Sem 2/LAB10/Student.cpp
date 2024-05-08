#pragma once
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student():id_student(0),n(0),note(NULL){}

Student::Student(string nu, int id, int m, int *no):Persoana(nu),id_student(id){
    setInfo(m,no);
}

Student& Student::operator=(const Student &s){
    nume = s.nume;
    id_student = s.id_student;
    setInfo(s.n, s.note);
    return *this;
}

Student::~Student(){
    delete []note;
}

void Student::setInfo(int m, int *no){
    n = m;
    if (no != NULL){
        delete []note;
        note = new int[m];
        for (int i = 0; i < m; i++)
            note[i] = no[i];
    } else note = NULL;
}

void Student::afisare() const{
    Persoana::afisare();
    cout << id_student << " " << n << " ";
    for (int i = 0; i < n; i++)
        cout << note[i] << " ";
}

int Student::getVenit() const{
    double aux = 0;
    for (int i = 0; i < n; i++)
        aux += note[i];
    aux = aux / n;
    if (aux > 8.50) return 700;
        else return 0;
}

