#include <iostream>
#include <string>
#include "produs.h"
#include "Electrocasnic.h"
#include "Tv.h"
using namespace std;

void sortare (TV *&a, int n){
    for (int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                TV aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
}

int main()
{
    TV *test;
    cout << "n="; cin >> n;
    test = new TV[n];

    for (int i = 0; i < n; i++)
        cin >> test[i];

    sortare(test, n);

    for (int i = 0; i < n; i++){
        test[i].afisare();
        cout << endl;
    }

}
