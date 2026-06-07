//
// Created by Lenovo ThinkBook on 6/7/2026.
//

#pragma once
#include <string>
#include <vector>

class Istoric {
    std::vector<std::string> evenimente;

    Istoric() = default;

public:
    Istoric(const Istoric&) = delete;
    Istoric& operator=(const Istoric&) = delete;

    static Istoric& get_instance();
    void inregistreaza(const std::string& eveniment);
    void afiseaza_istoric() const;
    int numar_evenimente() const;
};
