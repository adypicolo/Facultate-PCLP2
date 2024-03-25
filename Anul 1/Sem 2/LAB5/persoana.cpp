#include "persoana.h"
#include <iostream>
#include <string>
using namespace std;

Persoana::Persoana(){
    nume = " ";
    prenume = " ";
    CNP = " ";
    student = false;
}

Persoana::Persoana(string num, string pre, string CN, bool stud){
    nume = num;
    prenume = pre;
    CNP = CN;
    student = stud;
}

ostream& operator<<(ostream &dev, const Persoana &p){
    /*
    dev << "Nume: " << p.nume << endl;
    dev << "Prneume: " << p.prenume << endl;
    dev << "CNP: " << p.CNP << endl;
    dev << "Este stduent: ";
    */

    dev << p.nume << " " << p.prenume << " " << p.CNP << " ";
    if (p.student == true) dev << "1";
        else dev << "0";
    dev << '\n';

    return dev;
}

istream& operator>>(istream &dev, Persoana &p){
    cout << "Nume = "; dev >> p.nume;
    cout << "Prenume= "; dev >> p.prenume;
    cout << "CNP= "; dev >> p.CNP;
    cout << "Student= "; dev >> p.student;

    return dev;
}

bool Persoana::eStudent()const{
    return student;
}

string Persoana::getDataNastere() const{
    return CNP.substr(1,6);
}

bool Persoana::eFemeie() const{
    if (CNP[0] % 2 == 0) return 1;
        else return 0;
}

bool Persoana::eCNPValid() const{
    if (CNP.size() == 13) return 1;
        else return 0;
}

int Persoana::getNrPrenume() const{
    return prenume.size();
}

string* Persoana::getPrenumeList()const{
    string *Pl;
    ///Din start noi stim ca exista un prenume;
    int nrPrenume = 0, v[100];

    /// Verificam cate cratime avem in prenume pentru a retine cate
    /// prenume va avea vectrul de stringuri, si totodata vom retine
    /// pozitile.
    for (int i = 0; i < prenume.size(); i++)
        if (prenume[i] == '-'){
            nrPrenume ++;
            v[0] = i;
        }
    Pl = new string[nrPrenume];

    Pl[0] = prenume.substr(0, v[0]);
    for (int i = 1; i < nrPrenume; i++){
        if (i + 1 == nrPrenume) Pl[i] = prenume.substr(v[i], prenume.size());
            else Pl[i] = prenume.substr(v[i], v[i+1]);
    }

    return Pl;
}

string Persoana::getNumePrenume()const{
    return nume + " " + prenume;
}

void Persoana::setNumePrenume(string vechi){
    nume = vechi.substr(0, vechi.find(" "));
    prenume = vechi.substr(vechi.find(" ")+1, vechi.size());
}

string Persoana::getPrenume()const{
    return prenume;
}


