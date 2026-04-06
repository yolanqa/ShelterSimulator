//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#include "Adoptie.h"
#include <iostream>
#include <string>



    Adoptie::Adoptie(const std::string &nume_adoptator, const std::string &data_adoptie,
            const bool aprobata, const double taxa, const std::string &nume_animal)
        : nume_adoptator(nume_adoptator), data_adoptie(data_adoptie),
          aprobata(aprobata), taxa(taxa), nume_animal(nume_animal) {}

    void Adoptie::aprobare() {
        aprobata = true;
        std::cout << "Adoptia facuta pentru " << nume_animal << " a fost aprobata!\n";
    }

    void Adoptie::genereaza_contract() const {
        std::cout << "Contract Adoptie\n";
        std::cout << "Adoptator: " << nume_adoptator << "\n";
        std::cout << "Animal: " << nume_animal << "\n";
        std::cout << "Data: " << data_adoptie << "\n";
        std::cout << "Taxa: " << taxa << " Ron\n";
        std::cout << "Statut: " << (aprobata ? "Aprobata": "In asteptare") << "\n";

    }

    bool Adoptie::este_aprobata() const { return aprobata; }
    double Adoptie::get_taxa() const { return taxa; }

    std::ostream &operator<<(std::ostream &os, const Adoptie &obj) {
        return os << "adoptator: " << obj.nume_adoptator
                  << " animal: " << obj.nume_animal
                  << " data: " << obj.data_adoptie
                  << " taxa: " << obj.taxa
                  << " aprobata: " << obj.aprobata;
    }
