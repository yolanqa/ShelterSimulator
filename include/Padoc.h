//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#pragma once

#include "Animal.h"
#include <vector>
#include <string>
#include <ostream>
#include "Adoptie.h"
#include "Hrana.h"

class Padoc {
private:
    std::vector<Animal> vector_animale;
    std::vector<Adoptie> vector_adoptii;
    int capacitate;
    std::string tip_animale;
    double buget_sectiune;

public:
    Padoc(const std::vector<Animal> &animale, const std::vector<Adoptie> &adoptii,
             const int capacitate, const std::string &tip_animale, const double buget_sectiune);

    bool adauga_animal(const Animal &a);

    void hraneste_toate(const Hrana &h);

    double venituri_adoptii() const;


    void adauga_adoptie(const Adoptie &a);

    [[nodiscard]] int get_numar_animale() const;

    const Animal* animal_recomandat() const;



    friend std::ostream &operator<<(std::ostream &os, const Padoc &obj);

    ~Padoc() = default;
};

