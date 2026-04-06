//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#pragma once

#include <ostream>
#include <string>

class Hrana {
private:
    std::string tip;
    double cantitate;
    double valoare_nutritiva;

public:
    Hrana(const std::string &tip, const double cantitate, const double valoare_nutritiva);

    Hrana(const Hrana &other);

    Hrana &operator=(const Hrana &other);

    ~Hrana() = default;

    [[nodiscard]] double get_valoare_nutritiva() const;

    friend std::ostream &operator<<(std::ostream &os, const Hrana &obj);
};

