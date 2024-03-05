struct Pachet_Promo {
    // implicit ar fi publice, dar nu vreau ca oricine
    // sa poata modifica aceste campuri -> private

    private:
    char *descriere;
    char cod[6];
    int pret_initial_produse_continute[5];
    // ex pret_initial : 10, 16, 16, 5, 0 - daca am mai putin de 5 produse
    // în pachet - ultimele preturi vor primi valoarea 0
    // pretul pachetului este: 0.4 * sum(pret_initial_produse_continute[i])
    // dacă nu as face metodele publice, ar fi private ca și câmpurile
    // și nu as putea sa interactionez cu datele stocate

    public:

    // initializeaza fiecare camp cu 0 sau NULL
    void init();

    // citeste de la tastatura datele unui pachet
    void citire();

    // afiseaza informatii pachet
    void afisare() const;

    // modificare cod
    void modificare(char []);

    // modifica toate campurile folosind valorile stocate
    // in variabila Pachet_Promo data ca parametru
    void modificare(const Pachet_Promo &);

    // modifica pretul initial de pe o anumita pozitie din
    // vectorul de preturi initiale ale produselor (primul parametru),
    // iar noua valoare e transmisa in al doilea parametru
    void modificare(int, int);

    double diferenta();
};
