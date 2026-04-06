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
        return padocuri.size() * 50;
    }

    bool Adapost::adauga_padoc(const Padoc &p) {
        if (buget >= cost_intretinere() + 100) {
            padocuri.push_back(p);
            std::cout << "Padocul a fost adaugat! Buget ramas: "
                      << buget - cost_intretinere() - 100 << " Ron\n";
            return true;
        }
        std::cout << "Buget insuficient! Bugetul disponibil: "
                  << buget - cost_intretinere()
                  << "Buget necesar: 100 Ron\n";
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



    std::ostream &operator<<(std::ostream &os, const Adapost &obj) {
        return os << "nume: " << obj.nume
                  << " buget: " << obj.buget
                  << " padocuri: " << obj.padocuri.size();
    }



