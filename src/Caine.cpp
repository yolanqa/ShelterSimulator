//
// Created by Lenovo ThinkBook on 4/27/2026.
//

#include "Caine.h"

    const std::string& Caine::get_grupa() const { return grupa; }
    Caine::Caine(const std::string& nume, const std::string& specie,  double greutate,  int varsta,  int stare_sanatate, int nivel_sociabilitate, const Hrana& hrana_preferata, const std::string& grupa): Animal(nume, specie, greutate, varsta, stare_sanatate, nivel_sociabilitate, hrana_preferata), grupa(grupa){
        if (grupa.empty() || grupa == "null")
            throw RasaInvalidaException(grupa);}
    void Caine::sunet()const {
        if(get_stare_sanatate() <= 3)
            std::cout << "Cainele latru agitat - posibil bolnav!\n";
        else if(get_nivel_sociabilitate() <= 4)
            std::cout << "Cainele maraie sau musca!\n";
        else
            std::cout << "Cainele nu scoate niciun sunet!\n";
    }

    Animal* Caine::clone()const {
        return new Caine(*this);
    }

    double Caine::calculeaza_taxa_adoptie() const {
        double taxa_baza = 150.0;
        taxa_baza += get_varsta() * 5.0;
        taxa_baza -= (10 - get_stare_sanatate()) * 10.0;
        if (grupa == "paza") taxa_baza += 50.0;
        if (grupa == "frumusete") taxa_baza += 100.0;
        if (taxa_baza > 0)
            return taxa_baza;
        return 0;
    }

    void Caine::se_joaca_cu(const Animal* a) const {
        const Caine* c = dynamic_cast<const Caine*>(a);
        const Iepure* i = dynamic_cast<const Iepure*>(a);
        if (c != nullptr) {
            std::cout << get_nume() << " se joaca cu : caine " << a->get_nume() << "\n";
        } else if (i != nullptr) {
            std::cout << get_nume() << " se joaca cu : iepure " << a->get_nume() << "\n";
        } else {
            std::cout << get_nume() << " nu se joaca cu " << a->get_nume() << "\n";
        }
    }

    bool Caine::accepta_hrana(const Hrana& h) const {
        if (h.get_tip() == "carne" || h.get_tip() == "boabe") return true;
        std::cout << get_nume() << " refuza " << h.get_tip() << "\n";
        return false;
    }

    void Caine::print(std::ostream& os) const {
        Animal::print(os);
        os << " | grupa: " << grupa;
    }


    //Caine::~Caine() = default;
