#include <iostream>
#include <string>
#include "Persoana.h"
#include "Student.h"
#include "Angajat.h"
#include "Student_Angajat.h"
using namespace std;

void sortare(Persoana **p){
    for (int i = 0; i < 2; i++)
        for (int j = i + 1; j < 3; j++)
            if (p[i]->getVenit() > p[j]->getVenit()){
                Persoana *aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
}

int main()
{
    /*
    //Persoana p("Vlad");
    Angajat a("Vlad", 0, 4000);
    Student s("Bianca", 0, 3, note);

    //p.afisare();
    a.afisare();
    cout << endl;
    s.afisare();
    */

    ///1.
    int note[3] = {10,10,9};
    Persoana **v;
    v = new Persoana *[3];
    v[0] = new Angajat("Vlad", 0, 4000);
    v[1] = new Student("Bianca", 0, 3, note);
    v[2] = new Student_Angajat("Mihai", 1, 3, note, 1, 3000);

    ///2.
    sortare(v);

    ///3.
    for (int i = 0; i < 3; i++){
        v[i]->afisare();
        cout << endl;
    }
}
