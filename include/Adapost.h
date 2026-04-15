//
// Created by Lenovo ThinkBook on 4/6/2026.
//

#pragma once
#include <ostream>
#include <vector>
#include <string>
#include "Padoc.h"



class Adapost {
private:
    std::vector<Padoc> padocuri;
    std::string nume;
    double buget;

public:
    Adapost(const std::vector<Padoc> &padocuri, const std::string &nume, const double buget);

    double cost_intretinere() const;

    bool adauga_padoc(const Padoc &p);


    bool poate_cumpara_hrana(const double pret) const;

    void raport() const;


    void afiseaza_padocuri() const;

    void trece_timpul(int luni);





    friend std::ostream &operator<<(std::ostream &os, const Adapost &obj);
};
