#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Produs{
    public:
        virtual void afisare() const = 0;
        virtual int getPret() const = 0;
        virtual ~Produs(){};
};

class produs_software:public Produs { //PS
    protected:
        int pret;
    public:
        produs_software():pret(0) {};
        produs_software(int p):pret(p) {};
        void afisare()const{
            cout << pret;
        }

        int getPret()const{
            return pret;
        }

        ~produs_software(){};

};

class Piesa {
        char cod[6];
        int pret;
    public:
        Piesa():pret(0){
            for (int i = 0; i < 6; i++)
                cod[i]=' ';
        }

        Piesa(char c[6], int p):pret(p){
            for(int i = 0; i < 6; i++)
                cod[i] = c[i];
        }

        void afisare() const{
            cout << cod << " " << pret;
        }

        int getPret()const{
            return pret;
        }

        ~Piesa(){};

        friend ostream& operator<<(ostream &dev, const Piesa &p){
            dev << p.cod << endl << p.pret;
            return dev;
        }

};

class modul_hardware:public Produs { //MH
    protected:
        vector<Piesa> vec; // vector piese
        int pm;            // pret manopera pe ora
        int nr_ore;        // ore dezvoltare

    public:
        modul_hardware() = default;
        modul_hardware(vector<Piesa> v, int p, int nro):vec(v),pm(p),nr_ore(nro){};

        void afisare()const{
            for (int it = 0; it < vec.size(); it++)
                vec[it].afisare() ;
            cout << " " << pm << " " << nr_ore;
        }

        int getPret()const{
            int suma = 0;
            for (int it = 0; it < vec.size(); it++)
                suma += vec[it].getPret();
            suma += pm*nr_ore;

            return suma;
        }

        ~modul_hardware(){};




    // pret = suma preturilor pieselor+pm*nr_ore
};

class produs_mixt: public modul_hardware { //PM
    produs_software ps;
    vector<string> functionalitati;
    // pret = pret ps+pret MH

    public:
    produs_mixt() = default;
    produs_mixt(vector<Piesa> v, int p, int nro,produs_software p, vector<string> f):modul_hardware(v,p,nro),ps(p),functionalitati(f) {};

    void afisare() const{
        ps.afisare();
        modul_hardware::afisare();
        for (int i = 0; i < functionalitati.size(); i++)
            cout << functionalitati[i] << " ";
    }

    int getPret() const{
        return ps.getPret() + modul_hardware::getPret();
    }


};


int main(){
    ///1.
    vector<Piesa> p(3);
    p[0]=Piesa("123456", 250);
    p[1]=Piesa("456789", 2500);
    p[2]=Piesa("789123", 25000);

    produs_software ps(123);

    vector<string> functionalitati(2);
    functionalitati[0]=string("#1");
    functionalitati[1]=string("#2");

    vector <Produs *> v;
    v.push_back(new produs_software(100));
    v.push_back(new modul_hardware(p, 50, 8));
    v.push_back(new produs_mixt(p, 0, 3,ps, functionalitati));

    ///2.
    int total=0;
    for (int i = 0; i < v.size(); i++)
        total += v[i]->getPret();

    cout << "2. Total = " << total << endl;

    ///3.
    fstream o("output.txt", ios::out|ios::app);
    for (int i = 0; i < v.size(); i++){
        v[i]->afisare();
        cout << endl;
    }
    cout << endl << "3. A fost efectuata afisarea in fisier.";


    ///4.
    v.pop_back();
    v.pop_back();
    cout << endl << "4. Au fost sterse ultimele doua elemente din vector.";

    ///5.
    vector<Produs*>::iterator pozitie = v.begin();
    //int pozitie = 1;

    Produs* psn = new produs_software(1000);
    v.insert(pozitie, psn);
    cout << endl << "5. A fost inserat elementul in vector.";


    ///6.
    int maxim = 0;
    for (int i = 0; i < v.size(); i++)
        if (maxim < v[i]->getPret())
            maxim = v[i]->getPret();
    cout << endl << "6. Maximul este: " << maxim;

}

