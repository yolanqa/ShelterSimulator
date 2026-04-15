//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#include "Padoc.h"
#include "Adapost.h"
#include <iostream>
#include <vector>
#include <string>


    Adapost::Adapost(const std::vector<Padoc> &padocuri, const std::string &nume, const double buget)
        : padocuri(padocuri), nume(nume), buget(buget) {}

    double Adapost::cost_intretinere() const {
        return static_cast<double>(padocuri.size()) * 50;
    }

    bool Adapost::adauga_padoc(const Padoc &p) {
        if (buget >= cost_intretinere() + 150) {
            padocuri.push_back(p);
            std::cout << "Padocul a fost adaugat! Buget ramas: "
                      << buget - cost_intretinere()  << " Ron\n";
            return true;
        }
        std::cout << "Buget insuficient!\n";
        return false;
    }


    bool Adapost::poate_cumpara_hrana(const double pret) const {
        return buget >= cost_intretinere() + pret;
    }

    void Adapost::raport() const {
        std::cout << "Raport: " << nume << "\n";
        std::cout << "Numar padocuri: " << padocuri.size() << "\n";
        int total_animale = 0;
        for (const auto &s : padocuri)
            total_animale += s.get_numar_animale();
        std::cout << "Total animale: " << total_animale << "\n";
        std::cout << "Cost intretinere: " << cost_intretinere() << " Ron\n";
        std::cout << "Buget ramas: " << buget - cost_intretinere() << " Ron\n";

    }


    void Adapost::afiseaza_padocuri() const {
        std::cout << "Padocurile din " << nume << ":\n";
        for (int i = 0; i < static_cast<int>(padocuri.size()); i++) {
            std::cout << "Padoc " << i + 1 << ": " << padocuri[i] << "\n";
        }
    }

    void Adapost::trece_timpul(int luni) {
        int total_animale = 0;
        for (const auto &s : padocuri)
            total_animale += s.get_numar_animale();

        double cost_total = total_animale*50.0*static_cast<double>(luni);
        bool este_buget = (buget>=cost_total);

        if (este_buget) {
            buget = buget - cost_total;
            std::cout<<"Cheltuiala de: "<<cost_total<<"; "<<"Buget ramas: "<<buget;
        }
        else {
            buget = 0;
        }

        for (auto &s : padocuri)
            s.actualizare_animale(luni,este_buget);
    }
    std::ostream &operator<<(std::ostream &os, const Adapost &obj) {
        os << "Adapost: "<< obj.nume<<"\n";
        for (const auto &padoc : obj.padocuri)
                  os<<padoc << "\n";
        return os;
    }



