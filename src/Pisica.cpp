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
        double m = 1.0;
        if (rasa == "bengaleza") m = 5.0;
        else if (rasa == "persana") m = 2.5;
        else if (rasa == "siameza") m = 1.7;
        double taxa = 70.0 * m;
        if (get_stare_sanatate() < 4)
            taxa /= 2;
        return taxa;
    }


    void Pisica::print(std::ostream& os) const {
        Animal::print(os);
        os << " | rasa: " << rasa;
    }


    void Pisica::se_joaca_cu(const Animal* a) const {
        const Pisica* p = dynamic_cast<const Pisica*>(a);
        if (p != nullptr) {
            std::cout << get_nume() << " se joaca cu o pisica : " << a->get_nume() << "\n";
        } else {
            std::cout << get_nume() << " ignora " << a->get_nume() << "\n";
        }
    }

    bool Pisica::accepta_hrana(const Hrana& h) const {
        if (h.get_tip() == "carne" || h.get_tip() == "boabe") return true;
        std::cout << get_nume() << " refuza " << h.get_tip() << "\n";
        return false;
    }

    //Pisica::~Pisica=default;