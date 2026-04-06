//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include "Hrana.h"
class Animal {
private:
    static int nr_total_animale;
    char *nume;
    std::string specie;
    double greutate;
    int varsta;
    int stare_sanatate;
    int nivel_sociabilitate;
    Hrana hrana_preferata;

    void copiaza_nume(const char *src);

public:
    Animal(const char *nume, const std::string &specie, const double greutate,
           const int varsta, const int stare_sanatate, const int nivel_sociabilitate,
           const Hrana &hrana_preferata);

    Animal(const Animal &other);

    Animal &operator=(const Animal &other);

    static int get_nr_total_animale();

    ~Animal();

    [[nodiscard]] double get_greutate() const;
    [[nodiscard]] int get_stare_sanatate() const;
    [[nodiscard]] int get_nivel_sociabilitate() const;
    [[nodiscard]] const std::string& get_specie() const;
    [[nodiscard]] std::string get_nume() const;

    void hraneste(const Hrana &h);

    void imbatraneste();

    bool este_compatibil(const Animal &other) const;

    void afiseaza_stare() const;

    bool este_de_adoptat() const;

    friend std::ostream &operator<<(std::ostream &os, const Animal &obj);
};
