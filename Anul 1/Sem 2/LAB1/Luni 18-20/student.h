struct Student {
    // implicit ar fi publice, dar nu vreau ca
    // oricine sa poata modifica aceste campuri -> private
    private:
        int id;
        char *nume;
        char gr[5]; //1315
        int note_sem_I[6]; // Fizica 1, Chimie 2, Matematica 2, ...
        // daca nu as face metodele publice, ar fi private ca si campurile
        // si nu as putea sa interactionez cu datele stocate

    public:
    // inițializează fiecare camp cu 0 sau NULL
    void init();

    // citeste de la tastatura datele unui student
    void citire();

    // afiseaza informatii student
    void afisare() const;

    // modifica grupa studentului
    void modificare(char []);

    // modifica toate campurile folosind valorile stocate in
    // variabila Student data ca parametru
    void modificare(const Student &);

    // modifica nota de pe o anumita pozitie (primul parametru),
    // iar noua valoare a notei e transmisa in al doilea parametru
    void modificare(int, int);

    double medie();
};
