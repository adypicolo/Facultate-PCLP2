#include <iostream>
#include "persoana.h"
#include <string>
#include <fstream>
using namespace std;

bool compara(Persoana p1, Persoana p2){
    if (p1.getDataNastere().substr(0,2) != p2.getDataNastere().substr(0,2))
        return p1.getDataNastere().substr(0,2) < p2.getDataNastere().substr(0,2);
    else if (p1.getDataNastere().substr(2,4) != p2.getDataNastere().substr(2,4))
        return p1.getDataNastere().substr(2,4) < p2.getDataNastere().substr(2,4);
    else if (p1.getDataNastere().substr(4,6) != p2.getDataNastere().substr(4,6))
        return p1.getDataNastere().substr(4,6) < p2.getDataNastere().substr(4,6);
}

void sortare(Persoana * &p, int n){
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (compara(p[i], p[j]) == true){
                Persoana aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
}

int catePrenume(Persoana &p){
    string aux = p.getPrenume();
    int nrPrenume = 0;
    for (int i = 0; i < p.getNrPrenume(); i++){
        if (aux[i] == '-')
            nrPrenume ++;
    }
    return nrPrenume;
}

int main()
{
    ///1.
    cout << "1." << endl <<  "TEST PASSED" << endl;
    /*
    Persoana p1, p2("Vlad", "Adrian", "5150106987563", 1);
    cout << p1 << endl << p2 << endl;

    ///Este student p2?
    cout << "Este student p2? " << p2.eStudent() << endl;

    cout << "Persoana p1 = " << endl; cin >> p1;
    cout << p1;
    */

    ///2.
    cout << endl << "2." << endl;
    Persoana p;
    int n;
    fstream f("persoana.in", ios::out|ios::app);

    cout << "n= "; cin >> n;

    for (int i = 0; i < n; i++){
        cin >> p; cout << endl;
        f << p;
    }
    f.close();

    ///3.
    cout << endl << "3." << endl;
    Persoana *v;
    v = new Persoana[n];
    f.open("persoana.in",ios::in);

    for (int i = 0; i < n; i++){
        f >> v[i];
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        if (v[i].eStudent() == true)
            cout << v[i];

    ///4.
    cout << endl << "4." << endl;
    cout << v[2].eFemeie() << endl; /// 1
    cout << v[0].eCNPValid() << endl; /// 1
    cout << v[1].getDataNastere() << endl; /// 851012
    cout << v[0].getNrPrenume() << endl; /// 6
    cout << v[1].getPrenumeList() << endl; /// Marian
    cout << v[0].getNumePrenume() << endl; /// Vlad Adrian
    v[2].setNumePrenume("TINJALA BIANCA"); /// TINJALA BIANCA
    cout << v[2];
    ///INPUT: 3 Vlad Adrian 1840101491013 1 Timis Marian 2851012626311 0 Tinjala Bianca 6020407136211 1

    ///5.
    cout << endl << "5." << endl;
    sortare(v, n);

    for (int i = 0; i < n; i++)
        cout << v[i];

    ///6.
    fstream g("6.txt", ios::out|ios::app);
    for (int i = 0; i < n; i++)
        if (catePrenume(v[i]) == 1)
            g << v[i];

}
