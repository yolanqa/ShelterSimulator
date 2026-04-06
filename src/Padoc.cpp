//
// Created by Lenovo ThinkBook on 4/6/2026.
//

#include "Padoc.h"
#include "Animal.h"
#include <vector>
#include <iostream>
#include <string>
#include "Adoptie.h"
#include "Hrana.h"


    Padoc::Padoc(const std::vector<Animal> &animale, const std::vector<Adoptie> &adoptii,
             const int capacitate, const std::string &tip_animale, const double buget_sectiune)
        : vector_animale(animale), vector_adoptii(adoptii),
          capacitate(capacitate), tip_animale(tip_animale), buget_sectiune(buget_sectiune) {}

    bool Padoc::adauga_animal(const Animal &a) {
        if (static_cast<int>(vector_animale.size()) < capacitate) {
            vector_animale.push_back(a);
            return true;
        }
        std::cout << "Padocul este plin! Nu se poate adauga un alt animal.\n";
        return false;
    }

    void Padoc::hraneste_toate(const Hrana &h) {
        for (auto &an: vector_animale)
            an.hraneste(h);
    }

    double Padoc::venituri_adoptii() const {
        double total = 0;
        for (const auto &ad: vector_adoptii)
            if (ad.este_aprobata())
                total += ad.get_taxa();
        return total;
    }
    void Padoc::adauga_adoptie(const Adoptie &a) {
        vector_adoptii.push_back(a);
        std::cout << "Adoptia a fost adaugata cu succes!\n";
    }

    int Padoc::get_numar_animale() const {
        return static_cast<int>(vector_animale.size());
    }

    const Animal* Padoc::animal_recomandat() const {
        for (const auto &a: vector_animale) {
            if (a.este_de_adoptat()) return &a;
        }
        return nullptr;
    }



    std::ostream &operator<<(std::ostream &os, const Padoc &obj) {
        return os << "tipul animalelor: " << obj.tip_animale
                  << " capacitate: " << obj.capacitate
                  << " animale prezente in padoc: " << obj.vector_animale.size()
                  << " buget per padoc: " << obj.buget_sectiune;
    }


