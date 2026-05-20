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
    std::vector<std::unique_ptr<Padoc>> padocuri;
    std::string nume;
    double buget;



public:
    Adapost(std::vector<std::unique_ptr<Padoc>>&& padocuri, const std::string &nume,  double buget);


    double cost_intretinere() const;


    bool adauga_padoc(const Padoc &p);


    bool poate_cumpara_hrana( double pret) const;


    void raport() const;


    void afiseaza_padocuri() const;


    void trece_timpul(int luni);


    std::string cel_mai_aglomerat_padoc() const;


    int total_animale() const;


    friend std::ostream &operator<<(std::ostream &os, const Adapost &obj);
};
