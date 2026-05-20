//
// Created by Lenovo ThinkBook on 4/27/2026.
//

#include "Peste.h"
#include "Exceptii.h"

    Peste::Peste(const std::string& nume, const std::string& specie, double greutate, int varsta, int stare_sanatate, int nivel_sociabilitate, const Hrana& hrana_preferata, const std::string& apa):Animal(nume, specie, greutate, varsta, stare_sanatate, nivel_sociabilitate, hrana_preferata), apa(apa) {
        if (apa.empty() || apa == "null")
            throw ApaInvalidaException(apa);
    };

    std::string Peste::get_apa() const {return apa;}

    Animal* Peste::clone() const {
        return new Peste(*this);
    }

    void Peste::sunet() const {
        if (get_stare_sanatate() <= 3)
            std::cout << "Pestele nu se misca - posibil bolnav!\n";
        else if (get_nivel_sociabilitate() <= 4)
            std::cout << "Pestele sta singur";
        else
            std::cout << "Pestele este activ";
    }

    double Peste::calculeaza_taxa_adoptie() const {
        double taxa_baza = 50.0;
        if (apa == "sarata") return taxa_baza + 100.0;
        if (apa == "dulce") return taxa_baza + 30.0;
        return taxa_baza;
    }
    void Peste::print(std::ostream& os) const {
        Animal::print(os);
        os << " | apa: " << apa;
    }
