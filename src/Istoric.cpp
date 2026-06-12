//
// Created by Lenovo ThinkBook on 6/7/2026.
//

#include "Istoric.h"
#include <iostream>
#include <stdexcept>

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