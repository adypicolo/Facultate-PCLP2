#include <iostream>
#include <string>
#include "Proprietate.h"
#include "Teren.h"
#include "Imobil.h"
using namespace std;

///4
void sortare(Proprietate **vec){
    for (int i = 0; i < 2; i++)
        for (int j = i+1; j < 3; j++)
            if (vec[i]->getVenit() > vec[j]->getVenit()){
                Proprietate* aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
}

int main()
{
    ///3
    int data_dob[3]={1, 12, 2024};
    string *s;
    s = new string[2];
    s[0] = string("Zugravit");
    s[1] = string("Pat nou");

    Proprietate **v = new Proprietate*[3];
    v[0] = new Proprietate(data_dob, 50000);
    v[1] = new Teren(data_dob, 25000, 300, 30);
    v[2] = new Imobil(data_dob, 75000, 6000, 2, s);

    ///4
    sortare(v);

    ///5;
    for (int i = 0; i < 3; i++){
        v[i] -> afisare();
        cout << endl;
    }
}
