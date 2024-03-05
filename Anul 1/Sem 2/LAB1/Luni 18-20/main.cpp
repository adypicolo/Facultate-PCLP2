/// Facultatea de Stiinte Aplicate dorește să țină evidenta studentilor sai. Se doreste:
/// 1. ca studenții să fie stocati într-un vector (alocat dinamic), datele sa fie introduse de la tastatura
/// 2. sa fie afișate toate detaliile despre toți studenții
/// 3. sa se poată modifica grupa unui student
/// 4. sa se poată modifica datele unui student, folosind ca parametru datele unui alt student
/// 5. sa se poată modifica nota unui student la o anumita materie
/// 6. sa se sorteze vectorul în funcție de media notelor din semestrul I.
#include <iostream>
#include "student.h"
using namespace std;

int main()
{
    /// 1.
    cout << "1. " << endl;
    int n;
    Student *v;
    cout << "n= "; cin >> n;
    v = new Student[n];

    for (int i = 0; i < n; i++){
        cout << "Student " << i << ":" << endl;
        v[i].init();
        v[i].citire();
        cout << endl;
    }

    /// 2.
    cout << "2." << endl;
    for (int i = 0; i < n; i++){
        cout << "Student " << i << ":" << endl;
        v[i].afisare();
        cout << endl;
    }

    ///3.
    cout << endl << "3." << endl;
    int nrID;
    char gr[5];
    cout << "Id student= "; cin >> nrID;
    cout << "Noua grupa= "; cin >> gr;

    v[nrID].modificare(gr);
    v[nrID].afisare();

    ///4.
    cout << endl << "4." << endl;
    int nrID1, nrID2;
    cout << "Id student 1= "; cin >> nrID1;
    cout << "Id student 2= "; cin >> nrID2;
    v[nrID1].modificare(v[nrID2]);
    v[nrID2].afisare();

    ///5.
    cout << endl << "5." << endl;
    int pozitia, nota;
    cout << "ID Student = "; cin >> nrID;
    cout << "Materia = "; cin >> pozitia;
    cout << "Nota = "; cin >> nota;
    v[nrID].modificare(pozitia, nota);

    ///6.
    cout << endl << "6." << endl;

    for (int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i].medie() < v[j].medie()){
                Student aux;
                aux.modificare(v[i]);
                v[i].modificare(v[j]);
                v[j].modificare(aux);
            }

    for (int i = 0; i < n; i++){
        v[i].afisare();
        cout << endl;
    }

    ///INPUT: 3 1 Vlad 1314 1 2 3 4 5 6 2 Popescu 1315 4 5 6 7 8 9 3 Ion 1312 4 5 3 6 9 7 2 1311 1 2
    ///media vlad = 3.5 ; media ion = 5.6
}
