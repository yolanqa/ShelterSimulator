//
// Created by Lenovo ThinkBook on 6/12/2026.
//

#include "AdapostBuilder.h"

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