#pragma once
#include "Produs.h"
using namespace std;

class Aliment: public Produs {
    protected:
        int nr_info; // nr informatii despre aliment eg. 2
        string * informatii = NULL; // ex. 230cal/100g, expirare:12.12.2024
    public:
        ///1.
        Aliment(string m, int p, int nr, string *info):Produs(m, p){
            setInfo(nr, info);
        }

        ///2.
        ///Constructor cu parametrii
        Aliment(string m, int p, const Aliment &a): Produs(m, p){
            setInfo(a.nr_info, a.informatii);
        }

        ///Operator=
        Aliment& operator=(const Aliment &a){
            if (this != &a){
                marca = a.marca;
                pret = a.pret;
                setInfo(a.nr_info, a.informatii);
            }
            return *this;
        }

        ///Destructor
        ~Aliment(){
            delete []informatii;
        }

        ///3.
        void afisare() const{
            Produs::afisare();
            cout << "Nr info = " << nr_info << endl;
            for (int i = 0; i < nr_info; i++)
                cout << informatii[i] << " ";
        }

        ///5.
        Aliment():nr_info(0),informatii(NULL){}

        void setInfo(int nr, string *info){
            nr_info = nr;
            delete []informatii;
            if (nr != 0){
                informatii = new string[nr];
                for (int i = 0; i < nr; i++)
                    informatii[i] = info[i];
            }
            else informatii = NULL;
        }

        ///6.
        int getnrInfo() const{
            return nr_info;
        }

};
