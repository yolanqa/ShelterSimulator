//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#include "Animal.h"
#include "Hrana.h"
#include <ostream>
#include <cstring>


    void Animal::copiaza_nume(const char *src) {
        if (src) {
            nume = new char[strlen(src) + 1];
            strcpy(nume, src);
        } else {
            nume = nullptr;
        }
    }

    Animal::Animal(const char *nume, const std::string &specie, const double greutate,
           const int varsta, const int stare_sanatate, const int nivel_sociabilitate,
           const Hrana &hrana_preferata)
        : specie(specie), greutate(greutate), varsta(varsta),
          stare_sanatate(stare_sanatate), nivel_sociabilitate(nivel_sociabilitate),
          hrana_preferata(hrana_preferata) {
        copiaza_nume(nume);
    }

    Animal::Animal(const Animal &other)
        : specie(other.specie), greutate(other.greutate), varsta(other.varsta),
          stare_sanatate(other.stare_sanatate), nivel_sociabilitate(other.nivel_sociabilitate),
          hrana_preferata(other.hrana_preferata) {
        copiaza_nume(other.nume);
    }

    Animal &Animal::operator=(const Animal &other) {
        if (this == &other) return *this;
        delete[] nume;
        copiaza_nume(other.nume);
        specie = other.specie;
        greutate = other.greutate;
        varsta = other.varsta;
        stare_sanatate = other.stare_sanatate;
        nivel_sociabilitate = other.nivel_sociabilitate;
        hrana_preferata = other.hrana_preferata;
        return *this;
    }

    Animal::~Animal() { delete[] nume; }

    [[nodiscard]] double Animal::get_greutate() const { return greutate; }
    [[nodiscard]] int Animal::get_stare_sanatate() const { return stare_sanatate; }
    [[nodiscard]] int Animal::get_nivel_sociabilitate() const { return nivel_sociabilitate; }
    [[nodiscard]] const std::string& Animal::get_specie() const { return specie; }
    [[nodiscard]] std::string Animal::get_nume() const { return nume ? std::string(nume) : ""; }

    void Animal::hraneste(const Hrana &h) {
        greutate += h.get_valoare_nutritiva() * 0.1;
    }

    void Animal::imbatraneste() {
        varsta++;
        if (greutate > 5.0) greutate -= 0.5;
    }

    bool Animal::este_compatibil(const Animal &other) const {
        return this->specie == other.specie;
    }

    void Animal::afiseaza_stare() const {
        std::cout << "Starea lui " << (nume ? nume : "(null)") << ": ";
        if (stare_sanatate <= 3)
            std::cout << "stare critica\n";
        else if (stare_sanatate <= 6)
            std::cout << "stare cat-de-cat buna\n";
        else
            std::cout << "stare buna\n";
    }

    bool Animal::este_de_adoptat() const {
        if (stare_sanatate >= 5 && varsta <= 10) { return true;}
        else return false;
    }

    std::ostream &operator<<(std::ostream &os, const Animal &obj) {
        return os << "nume: " << (obj.nume ? obj.nume : "(null)")
                  << " specie: " << obj.specie
                  << " greutate: " << obj.greutate
                  << " varsta: " << obj.varsta
                  << " stare_sanatate: " << obj.stare_sanatate
                  << " nivel_sociabilitate: " << obj.nivel_sociabilitate
                  << " hrana_preferata: [" << obj.hrana_preferata << "]";
    }
