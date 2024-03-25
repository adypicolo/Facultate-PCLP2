#include <string>
using namespace std;
class Persoana{
    string nume;
    string prenume; //daca are 2 sau mai multe prenume, acestea sunt legate cu -: Ana-Maria
    string CNP;
    bool student; //true daca e student, false altfel
public :
    //constructor fara parametri
    Persoana();

    //constructor cu parametri
    Persoana(string, string, string, bool);

    //supradefinirea operatorului de extragere
    //atributele sunt afisate pe aceeasi linie, cu spatii intre ele, la final se trece la linie noua
    friend ostream& operator<<(ostream &, const Persoana & );

    /*supradefinirea operatorului de insertie; valorile pentru atribute sunt citite considerand ca au spatiu intre ele*/
    friend istream& operator>>(istream &, Persoana & );

    //returneaza valoarea atributului student
    bool eStudent()const;

    //returneaza data de nastere din CNP ca string, in formatul din CNP: aallzz
    string getDataNastere() const;

     //returneaza true daca prima cifra din CNP este 2, 4, sau 6
    bool eFemeie() const;

    /*testeaza daca CNP-ul are exact 13 caractere si returneaza true daca aceasta e lungimea stringului si false altfel*/
    bool eCNPValid() const;

    //returneaza numarul de prenume ale persoanei
    int getNrPrenume() const;

    //returneaza un vector care contine prenumele - sub forma de vector de stringuri
    string* getPrenumeList()const;

    //returneaza un string in care se gasesc concatenate numele si prenumele, se obtine: Pop Marin-Ion
    string getNumePrenume()const;

    /*se primeste ca parametru un string care contine numele si prenumele separate prin spatiu: Popescu Marin-Ion; sunt extrase numele si respectiv prenumele din acest string si folosite sa modifice numele si prenumele unei persoane*/
    void setNumePrenume(string);

    string getPrenume() const;
};
