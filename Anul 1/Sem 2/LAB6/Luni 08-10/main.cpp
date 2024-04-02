#include <iostream>
#include "Adresa.h"
#include "imobil.h"
using namespace std;



int main()
{
    Adresa a("Bucuresti", "Orhideelor", 1);
    /*cout <<a<< endl;
    Adresa b;
    cin>>b;
    cout<<b;*/

    ///TESTARE - PASSED
    ///1.
    Imobil n;
    cout << n;
    cout << endl;

    Imobil n1;
    cin >> n1;
    cout << n1;

    cout << endl;
    n = n1;
    cout << n1;

    ///2.
    /// In cazul in care, in clasa Adresa, variabilele oras si strada
    /// sunt de tipul char*, trebuie sa creem manual constructorul de copiere,
    /// operatorul= si deconstructorul.
    /// In constructorul cu parametru eliminam ":oras(o), strada(s)" si facem copia profunda
    /// (alocare dianmica + strcpy).

    ///3.
    cout << endl << "3." << endl;
    cout << n1.seGaseste("Bucuresti");




}
