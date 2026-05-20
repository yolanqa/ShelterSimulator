//
// Created by Lenovo ThinkBook on 4/6/2026.
//

#include "Padoc.h"
#include "Animal.h"
#include "Exceptii.h"
#include <vector>
#include <iostream>
#include <string>
#include "Adoptie.h"
#include "Hrana.h"
#include <algorithm>


    Padoc::Padoc(const std::vector<std::unique_ptr<Animal>>& animale, const std::vector<Adoptie> &adoptii,
          int capacitate, const std::string &tip_animale, double buget_sectiune)
    : vector_adoptii(adoptii), capacitate(capacitate),
        tip_animale(tip_animale), buget_sectiune(buget_sectiune) {
            for (const auto &a : animale)
            vector_animale.push_back(std::unique_ptr<Animal>(a->clone()));
}
    Padoc::Padoc(const Padoc& other)
        : vector_adoptii(other.vector_adoptii),
            capacitate(other.capacitate),
            tip_animale(other.tip_animale),
            buget_sectiune(other.buget_sectiune) {
        for (const auto& a : other.vector_animale)
            vector_animale.push_back(std::unique_ptr<Animal>(a->clone()));
    }

    Padoc& Padoc::operator=(Padoc other) {
        std::swap(vector_animale, other.vector_animale);
        std::swap(vector_adoptii, other.vector_adoptii);
        std::swap(capacitate, other.capacitate);
        std::swap(tip_animale, other.tip_animale);
        std::swap(buget_sectiune, other.buget_sectiune);
        return *this;
    }


    void Padoc::hraneste_toate(const Hrana &h) {
        for (auto &an: vector_animale)
            an->hraneste(h);
    }

    double Padoc::venituri_adoptii() const {
        double total = 0;
        for (const auto &ad: vector_adoptii)
            if (ad.este_aprobata())
                total += ad.get_taxa();
        return total;
    }

    void Padoc::sorteaza_dupa_stare_sanatate() {
        std::sort(vector_animale.begin(), vector_animale.end(),
            [](const std::unique_ptr<Animal>& a, const std::unique_ptr<Animal>& b) {
                return a->get_stare_sanatate() < b->get_stare_sanatate();
            });
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
            if (a->este_de_adoptat()) return a.get();
        }
        return nullptr;
    }

    void Padoc::actualizare_animale(int luni, bool este_buget) {
        for (auto &a : vector_animale) {
            a->imbatraneste_d(luni);
            if (!este_buget)
                a->stare_de_sanatate_modificata(-10 * luni);
            else
                a->stare_de_sanatate_modificata(2 * luni);
    }
}



    bool Padoc::adauga_animal(const Animal &a) {
        if (static_cast<int>(vector_animale.size()) >= capacitate) {
            throw CapacitatePadocException();
        }
        vector_animale.push_back(std::unique_ptr<Animal>(a.clone()));
        return true;
    }


    std::ostream &operator<<(std::ostream &os, const Padoc &obj) {
         os << "tipul animalelor:  ["<<obj.tip_animale<<"]\n"
            << " | capacitate: " << obj.capacitate<<"\n"
            << " | animale prezente in padoc: " << obj.vector_animale.size()<<"\n"
            << " | buget per padoc: " << obj.buget_sectiune;

        if (obj.vector_animale.empty())
            os<<"Nu sunt animale in padoc";
        else {
            os<<"ANimale: ";
            for (const auto &a: obj.vector_animale)
                os<<"-"<<*a<<"\n";
        }
        return os;
    }

    double Padoc::taxa_medie_adoptie() const {
        if (vector_animale.empty()) return 0.0;
        double total = 0;
        for (const auto& a : vector_animale)
            total += a->calculeaza_taxa_adoptie();
        return total / static_cast<double>(vector_animale.size());
    }

    const std::string& Padoc::get_tip_animale() const {
        return tip_animale;
    }

    bool Padoc::exista_animal_critic() const {
        return std::find_if(vector_animale.begin(), vector_animale.end(),
            [](const std::unique_ptr<Animal>& a) {
                return a->get_stare_sanatate() <= 3;
            }) != vector_animale.end();
    }

    int Padoc::numar_animale_adoptabile() const {
        return static_cast<int>(std::count_if(vector_animale.begin(), vector_animale.end(),
            [](const std::unique_ptr<Animal>& a) {
                return a->este_de_adoptat();
            }));
    }


