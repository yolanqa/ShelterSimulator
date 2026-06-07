//
// Created by Lenovo ThinkBook on 6/7/2026.
//

#include "Istoric.h"
#include <iostream>

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