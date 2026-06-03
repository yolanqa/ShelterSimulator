//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#include "Hrana.h"
#include <iostream>
#include <string>


    Hrana::Hrana(const std::string &tip, const double cantitate, const double valoare_nutritiva)
        : tip(tip), cantitate(cantitate), valoare_nutritiva(valoare_nutritiva){}


    const std::string& Hrana::get_tip() const { return tip; }

    double Hrana::get_valoare_nutritiva() const { return valoare_nutritiva; }

    std::ostream &operator<<(std::ostream &os, const Hrana &obj) {
        return os << "tip: " << obj.tip
                  << " cantitate: " << obj.cantitate
                  << " valoare_nutritiva: " << obj.valoare_nutritiva;
    }
    std::string Hrana::categorie_hrana() const {
        if (valoare_nutritiva >= 25.0 && cantitate >= 150.0)
            return "premium";
        if (valoare_nutritiva >= 15.0 && cantitate >= 80.0)
            return "standard";
        if (valoare_nutritiva < 10.0)
            return "slaba";
        return "medie";
    }