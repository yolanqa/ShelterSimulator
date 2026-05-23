//
// Created by Lenovo ThinkBook on 4/27/2026.
//
#pragma once
#include "Animal.h"
#include "Exceptii.h"
class Pisica:public Animal{
    std::string rasa;

protected:
    void print(std::ostream& os) const override;
public:
    Pisica(const std::string& nume, const std::string& specie, double greutate, int varsta, int stare_sanatate, int nivel_sociabilitate, const Hrana& hrana_preferata, const std::string& rasa);

    const std::string& get_rasa() const;

    void sunet() const override;

    Animal* clone() const override;

    double calculeaza_taxa_adoptie() const override;
    void aplica_tratament(Animal* a) override;

    ~Pisica() override = default;


};