//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#pragma once

#include "Animal.h"
#include "Exceptii.h"
#include <vector>
#include <string>

#include "Adoptie.h"
#include "Hrana.h"
#include <memory>


class Padoc {
private:
    std::vector<std::unique_ptr<Animal>> vector_animale;
    std::vector<Adoptie> vector_adoptii;
    int capacitate;
    std::string tip_animale;
    double buget_sectiune;

public:
    Padoc(const std::vector<std::unique_ptr<Animal>>& animale, const std::vector<Adoptie> &adoptii,
              int capacitate, const std::string &tip_animale, double buget_sectiune);
    Padoc(const Padoc& other);
    Padoc& operator=(Padoc other);
    bool adauga_animal(const Animal &a);

    void hraneste_toate(const Hrana &h);

    double venituri_adoptii() const;

    void sorteaza_dupa_stare_sanatate();

    void adauga_adoptie(const Adoptie &a);

    [[nodiscard]] int get_numar_animale() const;
    bool are_loc_pentru(const Animal& a) const;
    const Animal* animal_cel_mai_batran() const;

    const Animal* animal_recomandat() const;

    void actualizare_animale(int luni, bool este_buget);

    bool exista_animal_critic() const;
    int numar_animale_adoptabile() const;


    [[nodiscard]] const std::string& get_tip_animale() const;

    double taxa_medie_adoptie() const;


    friend std::ostream &operator<<(std::ostream &os, const Padoc &obj);


};

