//
// Created by Lenovo ThinkBook on 6/12/2026.
//

#pragma once
#include "Adapost.h"
#include "Padoc.h"
#include <string>
#include <vector>
#include <memory>

class AdapostBuilder {
    std::string nume;
    double buget;
    std::vector<std::unique_ptr<Padoc>> padocuri;
public:
    AdapostBuilder();
    AdapostBuilder& cu_nume(const std::string& nume);
    AdapostBuilder& cu_buget(double buget);
    AdapostBuilder& adauga_padoc(const Padoc& p);
    Adapost* construieste();
    AdapostBuilder& reset();
    int numar_padocuri_adaugate() const;
    std::unique_ptr<Adapost> construieste_unic();
};