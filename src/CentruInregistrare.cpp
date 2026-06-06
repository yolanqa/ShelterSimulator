//
// Created by Lenovo ThinkBook on 6/7/2026.
//

#include "CentruInregistrare.h"
#include "Caine.h"
#include "Pisica.h"
#include "Peste.h"
#include "Iepure.h"
#include <stdexcept>

Animal* CentruInregistrare::inregistreaza(const std::string& tip, const std::string& nume, double greutate, int varsta,
                                          int stare_sanatate, int nivel_sociabilitate, const Hrana& hrana, const std::string& atribut_specific) {
    if (tip == "caine")
        return new Caine(nume.c_str(), "caine", greutate, varsta, stare_sanatate, nivel_sociabilitate, hrana, atribut_specific);

    if (tip == "pisica")
        return new Pisica(nume.c_str(), "pisica", greutate, varsta, stare_sanatate, nivel_sociabilitate, hrana, atribut_specific);

    if (tip == "peste")
        return new Peste(nume.c_str(), "peste", greutate, varsta, stare_sanatate, nivel_sociabilitate, hrana, atribut_specific);

    if (tip == "iepure")
        return new Iepure(nume.c_str(), "iepure", greutate, varsta, stare_sanatate, nivel_sociabilitate, hrana, atribut_specific);
    throw std::invalid_argument("Animal necunoscut: " + tip);
}