//
// Created by Lenovo ThinkBook on 4/27/2026.
//

#pragma once
#include "Animal.h"
#include "Exceptii.h"
#include "Iepure.h"
class Caine:public Animal{
    std::string grupa;
    //daca e de rasa in domeniul asta exista diferite grupe in functie de ce menire are cainele (de paza, de frumusete etc)

protected:
    void print(std::ostream& os) const override;
public:
    const std::string& get_grupa() const;
    Caine(const std::string& nume, const std::string& specie, double greutate, int varsta, int stare_sanatate, int nivel_sociabilitate, const Hrana& hrana_preferata, const std::string& grupa);
    void sunet()const override ;


    Animal* clone()const override ;

    double calculeaza_taxa_adoptie() const override ;
    void se_joaca_cu(const Animal* a) const override;

    ~Caine() override = default;
};