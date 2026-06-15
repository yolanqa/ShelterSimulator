//
// Created by Lenovo ThinkBook on 6/12/2026.
//

#include "AdapostBuilder.h"
#include <stdexcept>
AdapostBuilder::AdapostBuilder() : nume("Adapost"), buget(0.0) {}
AdapostBuilder& AdapostBuilder::cu_nume(const std::string& n) {
    nume = n;
    return *this;
}
AdapostBuilder& AdapostBuilder::cu_buget(double b) {
    buget = b;
    return *this;}

AdapostBuilder& AdapostBuilder::adauga_padoc(const Padoc& p) {
    padocuri.push_back(std::make_unique<Padoc>(p));
    return *this;}

Adapost* AdapostBuilder::construieste() {
    return new Adapost(std::move(padocuri), nume, buget);
}
AdapostBuilder& AdapostBuilder::reset() {
    nume = "Adapost";
    buget = 0.0;
    padocuri.clear();
    return *this;
    }

int AdapostBuilder::numar_padocuri_adaugate() const {
    return static_cast<int>(padocuri.size());
}
std::unique_ptr<Adapost> AdapostBuilder::construieste_unic() {
    if (buget < 0)
        throw std::invalid_argument("Buget negativ");
    if (padocuri.empty())
        throw std::runtime_error("Adapost fara padocuri");
    return std::make_unique<Adapost>(std::move(padocuri), nume, buget);
}