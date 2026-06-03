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
bool Iepure::accepta_hrana(const Hrana& h) const {
    if (h.get_tip() == "morcovi" || h.get_tip() == "salata") return true;
    std::cout << get_nume() << " refuza " << h.get_tip() << "\n";
    return false;
}

double Iepure::calculeaza_taxa_adoptie() const {
    double taxa = 80.0;
    if (culoare == "negru")
        taxa += 40.0;
    taxa += get_nivel_sociabilitate() * 4.8;

    if (get_varsta() <= 1)
        taxa += 20.0;
    return taxa;
}
//iepurii negri sunt mai scumpi - (sunt mai rari)
void Iepure::print(std::ostream& os) const {
    Animal::print(os);
    os << " | culoare: " << culoare;
}

