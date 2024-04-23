#pragma once
#include <iostream>
using namespace std;

class Proprietate {
    protected:
        int data_dobandire[3]; //ex. data_dobandire[0]=1, data_dobandire[0]=12,
                          //data_dobandire[2]=2023
        double valoare;

    public:
        Proprietate() = default;
        Proprietate(int d[], double v):valoare(v) {
            for (int i = 0; i < 3; i++)
                data_dobandire[i] = d[i];
        }
        virtual ~Proprietate() {};
        ///4
        virtual double getVenit() { return 0; }

        ///5
        virtual void afisare(){
            for (int i = 0; i < 3; i++)
                cout << data_dobandire[i] << " ";
            cout << valoare << " ";
        }

}; // venitul generat de o proprietate pe luna e 0

