//
// Created by Lenovo ThinkBook on 4/27/2026.
//
#pragma once
#include <iostream>
#include "Animal.h"
#include "Exceptii.h"
class Peste:public Animal{
    std::string apa;

protected:
    void print(std::ostream& os) const override;
public:
    Peste(const std::string& nume, const std::string& specie, double greutate, int varsta, int stare_sanatate, int nivel_sociabilitate, const Hrana& hrana_preferata, const std::string& apa);
    const std::string& get_apa() const;
    void sunet() const override;
    Animal* clone() const override;
    void se_joaca_cu(const Animal* a) const override;

    double calculeaza_taxa_adoptie() const override;

    ~Peste() override = default;


};