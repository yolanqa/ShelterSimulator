//
// Created by Lenovo ThinkBook on 6/7/2026.
//

#pragma once
#include "Animal.h"
#include "Hrana.h"
#include <string>

class CentruInregistrare {
public:
    static Animal* inregistreaza(const std::string& tip, const std::string& nume, double greutate, int varsta, int stare_sanatate,
                                 int nivel_sociabilitate, const Hrana& hrana, const std::string& atribut_specific);
};