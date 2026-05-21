//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#include "Padoc.h"
#include "Adapost.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include "Exceptii.h"



    Adapost::Adapost(std::vector<std::unique_ptr<Padoc>>&& padocuri, const std::string &nume, double buget)
        : nume(nume), buget(buget) {
        for (auto& p : padocuri)
            this->padocuri.push_back(std::move(p));
    }

    int Adapost::nr_total_adaposturi = 0;

    int Adapost::get_nr_total_adaposturi() {
        return nr_total_adaposturi;
    }

    double Adapost::cost_intretinere() const {
        return static_cast<double>(padocuri.size()) * 50;
    }



    bool Adapost::poate_cumpara_hrana(const double pret) const {
        return buget >= cost_intretinere() + pret;
    }


    bool Adapost::adauga_padoc(const Padoc &p) {
        if (buget < cost_intretinere() + 50.0) {
            throw BugetInsuficientException();
        }
        padocuri.push_back(std::make_unique<Padoc>(p));
        return true;
    }




    void Adapost::raport() const {
        std::cout << "Raport: " << nume << "\n";
        std::cout << "Numar padocuri: " << padocuri.size() << "\n";
        int nr_animale = 0;
        for (const auto &s : padocuri)
            nr_animale += s->get_numar_animale();
        std::cout << "Total animale: " << nr_animale << "\n";
        std::cout << "Cost intretinere: " << cost_intretinere() << " Ron\n";
        std::cout << "Buget ramas: " << buget - cost_intretinere() << " Ron\n";

    }




    void Adapost::afiseaza_padocuri() const {
        std::cout << "Padocurile din " << nume << ":\n";
        for (int i = 0; i < static_cast<int>(padocuri.size()); i++) {
            std::cout << "Padoc " << i + 1 << ": " << *padocuri[i] << "\n";
        }
    }



    void Adapost::trece_timpul(int luni) {
        int nr_animale = 0;
        for (const auto &s : padocuri)
            nr_animale += s->get_numar_animale();

        double cost_total = nr_animale*50.0*static_cast<double>(luni);
        bool este_buget = (buget>=cost_total);

        if (este_buget) {
            buget = buget - cost_total;
            std::cout<<"Cheltuiala de: "<<cost_total<<"; "<<"Buget ramas: "<<buget;
        }
        else {
            buget = 0;
        }

        for (auto &s : padocuri)
            s->actualizare_animale(luni,este_buget);
    }


    std::ostream &operator<<(std::ostream &os, const Adapost &obj) {
        os << "Adapost: "<< obj.nume<<"\n";
        for (const auto &padoc : obj.padocuri)
                  os<<*padoc << "\n";
        return os;
    }


std::string Adapost::cel_mai_aglomerat_padoc() const {
        if (padocuri.empty()) return "Nu exista padocuri";
        int max = 0;
        std::string tip;
        for (const auto& p : padocuri) {
            if (p->get_numar_animale() > max) {
                max = p->get_numar_animale();
                tip = p->get_tip_animale();
            }
        }
        return tip;
    }


    int Adapost::total_animale() const {
        return std::accumulate(padocuri.begin(), padocuri.end(), 0,
            [](int sum, const std::unique_ptr<Padoc>& p) {
                return sum + p->get_numar_animale();
            });
    }

    const std::string& Adapost::get_nume() const {return nume;}

    void Adapost::hraneste_toate(const Hrana& h) {
        for (auto& p : padocuri)
            p->hraneste_toate(h);
    }



    void Adapost::adauga_animal_in_primul_padoc(const Animal& a) {
        if (padocuri.empty()) {
            std::cout << "Nu exista niciun padoc!\n"; return;
        }
        padocuri[0]->adauga_animal(a);
    }



    void Adapost::sorteaza_animale_primul_padoc() {
        if (padocuri.empty()) {
            std::cout << "Nu exista niciun padoc!\n";
            return;
        }
        padocuri[0]->sorteaza_dupa_stare_sanatate();
    }



    void Adapost::afiseaza_animal_recomandat() const {
        for (const auto& p : padocuri) {
            const Animal* rec = p->animal_recomandat();

            if (rec != nullptr) {
                std::cout << "Recomandat: " << *rec << "\n";
                return;
            }

        }
        std::cout << "Niciun animal nu este disponibil pentru adoptie.\n";
    }


    int Adapost::numar_animale_adoptabile() const {
        int total = 0;

        for (const auto& p : padocuri)
            total += p->numar_animale_adoptabile();

        return total;
    }



    double Adapost::taxa_medie_adoptie() const {
        if (padocuri.empty()) return 0.0;

        double total = 0;
        for (const auto& p : padocuri)
            total += p->taxa_medie_adoptie();

        return total / static_cast<double>(padocuri.size());
    }