#include "Iepure.h"

Iepure::Iepure(const std::string& nume, const std::string& specie, double greutate,
               int varsta, int stare_sanatate, int nivel_sociabilitate,
               const Hrana& hrana_preferata, const std::string& culoare)
    : Animal(nume, specie, greutate, varsta, stare_sanatate, nivel_sociabilitate, hrana_preferata),
      culoare(culoare) {
    if (culoare.empty() || culoare == "null")
        throw CuloareInvalidaException(culoare);
}

const std::string& Iepure::get_culoare() const { return culoare; }

void Iepure::sunet() const {
    if (get_stare_sanatate() <= 3)
        std::cout << "Iepurele sta nemiscat - posibil bolnav!\n";
    else if (get_nivel_sociabilitate() <= 4)
        std::cout << "Iepurele bate din picioare - este agitat!\n";
    else
        std::cout << "Iepurele este calm si activ!\n";
}

Animal* Iepure::clone() const {
    return new Iepure(*this);
}

double Iepure::calculeaza_taxa_adoptie() const {
    double taxa_baza = 80.0;
    taxa_baza += get_varsta() * 2.0;
    taxa_baza -= (10 - get_stare_sanatate()) * 5.0;
    if (culoare == "alb") taxa_baza += 50.0;
    if (culoare == "negru") taxa_baza += 30.0;
    if (taxa_baza > 0)
        return taxa_baza;

    return 0;
}

void Iepure::print(std::ostream& os) const {
    Animal::print(os);
    os << " | culoare: " << culoare;
}

