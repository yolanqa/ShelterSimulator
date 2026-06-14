//
// Created by Lenovo ThinkBook on 6/7/2026.
//

#include "Istoric.h"
#include <iostream>
#include <stdexcept>
#include<fstream>
#include<algorithm>

Istoric& Istoric::get_instance() {
    static Istoric instanta;
    return instanta;
}

void Istoric::inregistreaza(const std::string& eveniment) {
    evenimente.push_back(eveniment);
}

void Istoric::afiseaza_istoric() const {
    std::cout << "ISTORIC\n";
    if (evenimente.empty()) {
        std::cout << "Niciun eveniment inregistrat\n"; return;
    }
    for (size_t i = 0; i < evenimente.size(); i++) {
        std::cout << (i + 1) << ". " << evenimente[i] << "\n";
    }
}

int Istoric::numar_evenimente() const {
    return static_cast<int>(evenimente.size());
}

const std::string& Istoric::ultimul_eveniment() const {
    if (evenimente.empty())
        throw std::out_of_range("Istoric gol");
    return evenimente.back();
}

bool Istoric::contine(const std::string& text) const {
    for (const auto& e : evenimente)
        if (e.find(text) != std::string::npos)
            return true;
    return false;
}

void Istoric::goleste() {
    evenimente.clear();
}

void Istoric::pastreaza_ultimele(int n) {
    if (n >= static_cast<int>(evenimente.size())) return;
    evenimente.erase(evenimente.begin(), evenimente.end() - n);
}
std::vector<std::string> Istoric::evenimente_care_contin(const std::string& text) const {
    std::vector<std::string> rezultat;
    for (const auto& e : evenimente)
        if (e.find(text) != std::string::npos)
            rezultat.push_back(e);
    return rezultat;
}
void Istoric::exporta(const std::string& fisier) const {
    std::ofstream out(fisier);
    if (!out) throw std::runtime_error("Nu pot scrie in " + fisier);
    for (const auto& e : evenimente) out << e << "\n";
}