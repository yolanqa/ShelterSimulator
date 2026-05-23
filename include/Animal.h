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
    static int contor_id;
    int id;
    std::string nume;
    std::string specie;
    double greutate;
    int varsta;
    int stare_sanatate;
    int nivel_sociabilitate;
    Hrana hrana_preferata;

protected:
    virtual void print(std::ostream& os) const;

public:
    Animal(const std::string& nume, const std::string &specie, const double greutate,
           const int varsta, const int stare_sanatate, const int nivel_sociabilitate,
           const Hrana &hrana_preferata);

    static int get_contor_id();
    [[nodiscard]] int get_id() const;

    virtual Animal* clone() const =0;
    virtual void sunet()const =0;
    virtual double calculeaza_taxa_adoptie() const=0;
    virtual void aplica_tratament(Animal* a);
    static int get_nr_total_animale();



    [[nodiscard]] double get_greutate() const;
    [[nodiscard]] int get_stare_sanatate() const;
    [[nodiscard]] int get_nivel_sociabilitate() const;
    [[nodiscard]] const std::string& get_nume() const;
    [[nodiscard]] const std::string& get_specie() const;
    [[nodiscard]] int get_varsta() const;

    void hraneste(const Hrana &h);
    void imbatraneste();
    bool este_compatibil(const Animal &other) const;
    void afiseaza_stare() const;
    bool este_de_adoptat() const;
    void imbatraneste_d(int luni_din_an);
    void stare_de_sanatate_modificata(int valoare);
    bool necesita_ingrijire_urgenta() const;


    friend std::ostream& operator<<(std::ostream& os, const Animal& obj) {
        obj.print(os);
        return os;
    }
    virtual ~Animal(){};
};
