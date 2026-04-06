//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#include "Hrana.h"
#include <iostream>
#include <string>


    Hrana::Hrana(const std::string &tip, const double cantitate, const double valoare_nutritiva)
        : tip(tip), cantitate(cantitate), valoare_nutritiva(valoare_nutritiva) {}

    Hrana::Hrana(const Hrana &other)
        : tip(other.tip), cantitate(other.cantitate), valoare_nutritiva(other.valoare_nutritiva) {}

    Hrana& Hrana::operator=(const Hrana &other) {
        if (this == &other) return *this;
        tip = other.tip;
        cantitate = other.cantitate;
        valoare_nutritiva = other.valoare_nutritiva;
        return *this;
    }


    double Hrana::get_valoare_nutritiva() const { return valoare_nutritiva; }

    std::ostream &operator<<(std::ostream &os, const Hrana &obj) {
        return os << "tip: " << obj.tip
                  << " cantitate: " << obj.cantitate
                  << " valoare_nutritiva: " << obj.valoare_nutritiva;
    }
