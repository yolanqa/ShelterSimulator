//
// Created by Lenovo ThinkBook on 4/27/2026.
//

#include "Peste.h"
#include "Exceptii.h"

    Peste::Peste(const std::string& nume, const std::string& specie, double greutate, int varsta, int stare_sanatate, int nivel_sociabilitate, const Hrana& hrana_preferata, const std::string& apa):Animal(nume, specie, greutate, varsta, stare_sanatate, nivel_sociabilitate, hrana_preferata), apa(apa) {
        if (apa.empty() || apa == "null")
            throw ApaInvalidaException(apa);
    };

    const std::string& Peste::get_apa() const {return apa;}

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
        if (apa == "sarata") {
            double taxa = 150.0;
            if (get_stare_sanatate() >= 8)
                taxa += 50.0;
            return taxa;
        }
        return 50.0 + get_stare_sanatate() * 5.0;
    }
    void Peste::print(std::ostream& os) const {
        Animal::print(os);
        os << " | apa: " << apa;
    }
