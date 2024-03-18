#include <iostream>
using namespace std;

class MyString {
    char *buf;
    int l;
public:
    //constr fara param – initializeaza atrib. cu 0 sau NULL
    MyString();

    // constr cu param – un sir de caractere
    MyString(char *);

    // constr de copiere
    MyString(const MyString &);

    // operator de atribuire
    MyString& operator=(const MyString &);

    // destructor
    ~MyString();

    // operatorii pentru afisare si citire pentru obiecte MyString
    friend ostream& operator<<(ostream&, const MyString&);
    friend istream& operator>>(istream&, MyString&);

    // operator+ concateneaza 2 siruri si salveaza rezultatul intr-un
    // obiect nou de tip MyString pe care il returneaza
    friend const MyString operator+(const MyString &, const MyString &);

    // operator+= concateneaza 2 siruri si salveaza rezultatul
    // in primul operand a carui adresa o returneaza
    MyString& operator+=(const MyString &);

    //operator de indexare – returneaza referinta catre caracterul
    //de pe pozitia i din buf
    char& operator[](int);

    // cauta caracterul dat ca parametru in sir si
    // returneaza numarul de aparitii
    int lookFor(char) const;

    // verifica daca cele 2 siruri sunt identice
    friend bool operator==(const MyString &, const MyString &);

    // verifica daca cele 2 siruri sunt diferite, poate folosi ==
    friend bool operator!=(const MyString &, const MyString &);

    // Implementati operatorii de relatie: <, <= >, >= ca functii friend
    //ordonare se face alfabetic

};
