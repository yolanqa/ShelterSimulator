#include <iostream>
#include <ostream>
#include <vector>
#include <memory>

#include "Animal.h"
#include "Padoc.h"
#include "Adoptie.h"
#include "Hrana.h"
#include "Adapost.h"
#include "Ingrijitor.h"
#include "Caine.h"
#include "Pisica.h"
#include "Peste.h"
#include "Exceptii.h"
#include "Iepure.h"
#include"SImulator.h"


int main() {
    std::string nume_adapost;
    double buget;

    std::cout << "Numele adapostului: ";
    std::getline(std::cin, nume_adapost);
    std::cout << "Buget initial: ";
    std::cin >> buget;

    Hrana hrana("carne", 200.0, 30.0);
    Simulator sim(nume_adapost, buget, hrana);
    sim.ruleaza();

    return 0;
    }