class Masina {
// atributele sunt implicit private
    char *marca;
    char nr_inmatriculare[8];
    double pret;

public:
    // constr. fara param;
    // util pentru a crea obiecte intializate cu valori default
    // necesar pt. alocarea spatiului pentru elemente din vect. de masini
    // marca = NULL; nr_inmatriculare este  de ex: "000..0"; pret=0
    Masina();

    // constr. cu param; pentru a initializa cu valori dorite toate atrib.
    Masina(char*, char[], double);

    // constructor de copiere - se apeleaza automat la transmiterea
    // parametrilor in functii prin valoare si la
    // returnarea obiectelor din fctii prin valoare;
    // puneti: cout<<"const de copiere"; (ca sa vedeti unde e apelat)
    Masina(const Masina&);

    // elibereaza spatiu ocupat de un obiect
    ~Masina();

    //afiseaza toate atributele unui obiect de acest tip
    void afisare() const;

    // face o copie profunda a parametrului si o stocheaza in
    // obiectul cu care se face apelul;
    void copie(const Masina &);

    double getPret() const;

    char* getMarca();

    char* getNr_Inmatriculare() ;
};

