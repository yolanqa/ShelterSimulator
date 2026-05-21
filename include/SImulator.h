//
// Created by Lenovo ThinkBook on 5/21/2026.
//


#pragma once
#include "Adapost.h"
#include "Padoc.h"
#include "Hrana.h"
#include <string>
#include <limits>

class Simulator {
    Adapost* adapost;

    Hrana hrana_default;

    bool activ;

    static void titlu(const std::string& text);
    static void invalid();
    static int citesteInt(const std::string& mesaj);
    static std::string citesteString(const std::string& mesaj);
    void meniuAnimale();
    void meniuAdoptii();
    void meniuStatistici();
    void meniuSimulare();




public:
    explicit Simulator(const std::string& nume_adapost, double buget, const Hrana& hrana);
    ~Simulator();
    Simulator(const Simulator&) = delete;
    Simulator& operator=(const Simulator&) = delete;
    void ruleaza();
};