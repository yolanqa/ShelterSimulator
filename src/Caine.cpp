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
        if (grupa == "paza") return taxa_baza + 50.0;
        if (grupa == "frumusete") return taxa_baza + 100.0;
        return taxa_baza;
    }
    void Caine::print(std::ostream& os) const {
        Animal::print(os);  // apeleaza baza
        os << " | grupa: " << grupa;
    }

    //Caine::~Caine() = default;
