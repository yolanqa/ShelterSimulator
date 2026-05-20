//
// Created by Lenovo ThinkBook on 4/27/2026.
//
#include "Pisica.h"
#include "Exceptii.h"

    Pisica::Pisica(const std::string& nume, const std::string& specie, double greutate, int varsta, int stare_sanatate, int nivel_sociabilitate, const Hrana& hrana_preferata, const std::string& rasa):Animal(nume, specie, greutate, varsta, stare_sanatate, nivel_sociabilitate, hrana_preferata), rasa(rasa) {
        if (rasa.empty() || rasa == "null")
            throw RasaInvalidaException(rasa);
    };

    const std::string& Pisica::get_rasa() const{return rasa;}
    Animal* Pisica::clone() const {
        return new Pisica(*this);
    }
    void Pisica::sunet() const {
        if (get_stare_sanatate() <= 3)
            std::cout << "Pisica scheauna - posibil bolnava!\n";
        else if (get_nivel_sociabilitate() <= 4)
            std::cout << "Pisica sasaie!\n";
        else
            std::cout << "Pisica toarce!\n";
    }

    double Pisica::calculeaza_taxa_adoptie() const {
        double taxa_baza = 100.0;
        if (rasa == "persana") return taxa_baza + 150.0;
        if (rasa == "siameza") return taxa_baza + 100.0;
        if (rasa == "bengaleza") return taxa_baza + 200.0;
        return taxa_baza;
    }
    void Pisica::print(std::ostream& os) const {
        Animal::print(os);
        os << " | rasa: " << rasa;
    }

    //Pisica::~Pisica=default;