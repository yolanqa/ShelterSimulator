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

    void Pisica::aplica_tratament(Animal* a) {
        Pisica* p = dynamic_cast<Pisica*>(a);

        if (p != nullptr) {
            if (p->get_rasa() == "persana") {
                a->stare_de_sanatate_modificata(13);
                std::cout << "Tratament pentru pisica persana: sanatate+13\n";

            } else if (p->get_rasa() == "siameza") {
                a->stare_de_sanatate_modificata(10);
                std::cout << "Tratament pentru pisica siameza: sanatate+10\n";
            } else {
                a->stare_de_sanatate_modificata(5);
                std::cout << "Tratament standard pentru pisica: sanatate+5.\n";
            }
        } else {
            std::cout << "Tratamentul nu se aplica - nu e pisica\n";
        }
    }
    void Pisica::print(std::ostream& os) const {
        Animal::print(os);
        os << " | rasa: " << rasa;
    }

    //Pisica::~Pisica=default;