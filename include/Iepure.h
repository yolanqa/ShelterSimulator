#pragma once
#include "Animal.h"
#include "Exceptii.h"


class Iepure:public Animal {
    std::string culoare;

protected:
    void print(std::ostream& os) const override;

public:

    Iepure(const std::string& nume, const std::string& specie, double greutate,
           int varsta, int stare_sanatate, int nivel_sociabilitate,
           const Hrana& hrana_preferata, const std::string& culoare);

    const std::string& get_culoare() const;

    void sunet() const override;
    bool accepta_hrana(const Hrana& h) const override;
    Animal* clone() const override;

    double calculeaza_taxa_adoptie() const override;

    ~Iepure() override = default;
};