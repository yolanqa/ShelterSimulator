#include <iostream>
#include <array>
#include <cstring>
#include <ostream>
#include <vector>
#include "include/Example.h"
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"


class Hrana {
private:
    std::string tip;
    double cantitate;
    double valoare_nutritiva;
public:
    //Hrana(const std::string &tip, double cantitate, double valoare_nutritiva);

    Hrana(const std::string &tip, const double cantitate, const double valoare_nutritiva)
        : tip(tip),
          cantitate(cantitate),
          valoare_nutritiva(valoare_nutritiva) {
    }

    Hrana(const Hrana &other)
        : tip(other.tip),
          cantitate(other.cantitate),
          valoare_nutritiva(other.valoare_nutritiva) {
    }

    Hrana & operator=(const Hrana &other) {
        if (this == &other)
            return *this;
        tip = other.tip;
        cantitate = other.cantitate;
        valoare_nutritiva = other.valoare_nutritiva;
        return *this;
    }

    ~Hrana() = default;

    friend std::ostream & operator<<(std::ostream &os, const Hrana &obj) {
        return os
               << "tip: " << obj.tip
               << " cantitate: " << obj.cantitate
               << " valoare_nutritiva: " << obj.valoare_nutritiva;
    }
};

class Animal {
private:
    char* nume;
    std::string specie;
    double greutate;
    int varsta;
    int pozitie_a;
    int pozitie_b;
    Hrana hrana_preferata;


    void functie(const char* src) {
        if (src) {
            nume= new char[strlen(src) + 1];
            strcpy(nume,src);
        }else {
            nume= nullptr;
        }
    }
public:
    //Animal(const char* nume, const std::string& specie, double greutate, int varsta, const Hrana& hrana_preferata);

        Animal(const char* nume, const std::string &specie, const double greutate, const int varsta, const int pozitie_a, const int pozitie_b,
            const Hrana &hrana_preferata )
            : specie(specie),
              greutate(greutate),
              varsta(varsta),
              pozitie_a(pozitie_a),
              pozitie_b(pozitie_b),
              hrana_preferata(hrana_preferata) { functie(nume); }


    Animal(const Animal &other)
        :
          specie(other.specie),
          greutate(other.greutate),
          varsta(other.varsta),
          pozitie_a(other.pozitie_a),
          pozitie_b(other.pozitie_b),
          hrana_preferata(other.hrana_preferata) { functie(other.nume);}


    Animal & operator=(const Animal &other) {
        if (this == &other)
            return *this;
        delete[] nume;
        functie(other.nume);
        specie = other.specie;
        greutate = other.greutate;
        varsta = other.varsta;
        pozitie_a = other.pozitie_a;
        pozitie_b = other.pozitie_b;
        hrana_preferata = other.hrana_preferata;
        return *this;
    }

    [[nodiscard]] int pozitie_a1() const {
        return pozitie_a;
    }

    [[nodiscard]] int pozitie_b1() const {
        return pozitie_b;
    }

    void set_pozitie_a(int pozitie_a) {
        this->pozitie_a = pozitie_a;
    }

    void set_pozitie_b(int pozitie_b) {
        this->pozitie_b = pozitie_b;
    }

    ~Animal() {
        delete[] nume;
    }


    friend std::ostream & operator<<(std::ostream &os, const Animal &obj) {
        return os
               << "nume: " << (obj.nume ? obj.nume : "(null)")
               << " specie: " << obj.specie
               << " greutate: " << obj.greutate
               << " varsta: " << obj.varsta
               << " pozitie_a: " << obj.pozitie_a
               << " pozitie_b: " << obj.pozitie_b
               << " hrana_preferata: " << obj.hrana_preferata;
    }
};

class Obstacol {
private:
    std::string tip;
    int pozitie_1;
    int pozitie_2;
    bool activ;

public:
    Obstacol(const std::string &tip, int pozitie_1, int pozitie_2, bool activ)
        : tip(tip),
          pozitie_1(pozitie_1),
          pozitie_2(pozitie_2),
          activ(activ) {
    }

    bool Coliziune(const Animal &animal) const {
        if (animal.pozitie_a1() == pozitie_1 && animal.pozitie_b1() == pozitie_2) {
            return true;
        }
        else
            return false;
    };

    void Efect (Animal &animal) const {
        if (tip=="peste_balon") {
            animal.set_pozitie_a(animal.pozitie_a1()-1);
        }
        if (tip=="coral") {
            std::cout<<"Game over"<<std::endl;
        }
    }

    void Mutare(int viteza) {
        pozitie_1=pozitie_1-viteza;
        if (pozitie_1<0) {
            activ=false;
        }
    }

    friend std::ostream & operator<<(std::ostream &os, const Obstacol &obj) {
        return os
               << "tip: " << obj.tip
               << " pozitie_1: " << obj.pozitie_1
               << " pozitie_2: " << obj.pozitie_2
               << " activ: " << obj.activ;
    }
};



class Bazin {
private:
    std::vector<Animal> vector_animale;
    std::vector<Obstacol> vector_obstacole;
    int volum;
    double temperatura;
    int salinitate;

public:
    //Bazin(int volum, double temperatura, int salinitate);


    Bazin(const std::vector<Animal> &animale, const std::vector<Obstacol> &obstacole, const int volum, const double temperatura, const int salinitate)
        : vector_animale(animale),
          vector_obstacole(obstacole),
          volum(volum),
          temperatura(temperatura),
          salinitate(salinitate) {
    }

    friend std::ostream & operator<<(std::ostream &os, const Bazin &obj) {
        return os
               << " volum: " << obj.volum
               << " temperatura: " << obj.temperatura
               << " salinitate: " << obj.salinitate;
    }

    ~Bazin() = default;
};

class Acvariu{
private:
    std::vector<Bazin> bazine;
    std::string nume;
    double buget;

public:
    //Acvariu(const std::string& nume, double buget);

    Acvariu(const std::vector<Bazin> &bazine, const std::string &nume, const double buget)
        : bazine(bazine),
          nume(nume),
          buget(buget) {
    }

    friend std::ostream & operator<<(std::ostream &os, const Acvariu &obj) {
        return os
               << " nume: " << obj.nume
               << " buget: " << obj.buget;
    }

    ~Acvariu() = default;
};



int main() {
    Hrana hrana ("shrimps", 100.0, 20.0);
    Animal animal ("Lary", "specie", 100.0, 5, 10, 15, hrana);
    Obstacol obstacole ("peste balon", 20, 25, true);
    std::vector<Animal> vec_animale = {animal};
    std::vector<Obstacol> vec_obstacole = {obstacole};
    Bazin bazin (vec_animale, vec_obstacole, 200, 20.0, 3);
    std::vector<Bazin> vec_bazine = {bazin};
    Acvariu acvariu (vec_bazine, "Acvariul 1", 100.0);

    std::cout << hrana << std::endl;
    std::cout << animal << std::endl;
    std::cout << obstacole << std::endl;
    std::cout << bazin << std::endl;
    std::cout << acvariu << std::endl;

    Example e1;
    e1.g();

    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    if (obstacole.Coliziune(animal)) {
        std::cout << "Coliziune detectata" << std::endl;
    }else {
        std::cout << " Nu exista coliziune" << std::endl;
    }

    obstacole.Efect(animal);
    std::cout << animal << std::endl;

    obstacole.Mutare(5);
    std::cout << obstacole << std::endl;

    return 0;
}
