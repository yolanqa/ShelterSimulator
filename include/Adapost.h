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
    static int nr_total_adaposturi;



public:
    Adapost(std::vector<std::unique_ptr<Padoc>>&& padocuri, const std::string &nume,  double buget);


    double cost_intretinere() const;
    std::string animal_cel_mai_batran() const;

    bool adauga_padoc(const Padoc &p);


    bool poate_cumpara_hrana( double pret) const;

    static int get_nr_total_adaposturi();


    void raport() const;


    void afiseaza_padocuri() const;


    void trece_timpul(int luni);


    std::string cel_mai_aglomerat_padoc() const;


    int total_animale() const;


    [[nodiscard]] const std::string& get_nume() const;


    void hraneste_toate(const Hrana& h);


    void adauga_animal_in_primul_padoc(const Animal& a);


    void sorteaza_animale_primul_padoc();


    void afiseaza_animal_recomandat() const;


    int numar_animale_adoptabile() const;


    double taxa_medie_adoptie() const;




    friend std::ostream &operator<<(std::ostream &os, const Adapost &obj);
};
