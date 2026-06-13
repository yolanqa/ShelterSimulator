//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#pragma once

#include <iostream>
#include <string>


class Adoptie {
private:
    std::string nume_adoptator;
    std::string data_adoptie;
    bool aprobata;
    double taxa;
    std::string nume_animal;

public:
    Adoptie(const std::string &nume_adoptator, const std::string &data_adoptie,
            const bool aprobata, const double taxa, const std::string &nume_animal);

    void aprobare();


    void genereaza_contract() const;

    [[nodiscard]] bool este_aprobata() const;
    [[nodiscard]] double get_taxa() const;
    bool operator==(const Adoptie& other) const {
        return nume_adoptator == other.nume_adoptator && nume_animal == other.nume_animal;
    }


    friend std::ostream &operator<<(std::ostream &os, const Adoptie &obj);
};

