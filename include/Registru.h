//
// Created by Lenovo ThinkBook on 6/7/2026.
//

#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>

class Registru {
    std::vector<T> elemente;


public:
    bool contine(const T& val) const {
        for (int i = 0; i < static_cast<int>(elemente.size()); i++)
            if (elemente[i] == val)
                return true;
        return false;
    }
    void adauga(const T& element) {
        elemente.push_back(element);
    }

    const T& get(int index) const {
        if (index < 0 || index >= static_cast<int>(elemente.size()))
            throw std::out_of_range("Index invalid in Registru");
        return elemente[index];
    }

    int size() const {
        return static_cast<int>(elemente.size());
    }

    bool gol() const {
        return elemente.empty();
    }

    const T& ultimul() const {
        if (elemente.empty())
            throw std::out_of_range("Registru gol");
        return elemente.back();
    }

    void sterge_ultimul() {
        if (!elemente.empty())
            elemente.pop_back();
    }

    void afiseaza_toate() const {
        for (int i = 0; i < static_cast<int>(elemente.size()); i++)
            std::cout << i + 1 << ". " << elemente[i] << "\n";
    }

    const T& primul() const {
        if (elemente.empty())
            throw std::out_of_range("Registru gol");
        return elemente.front();
    }

    void inlocuieste(int index, const T& element) {
        if (index < 0 || index >= static_cast<int>(elemente.size()))
            throw std::out_of_range("Index invalid in Registru");
        elemente[index] = element;
    }

    void goleste() {
        elemente.clear();
    }
    void combina(const Registru<T>& altul) {
        for (int i = 0; i < altul.size(); i++)
            elemente.push_back(altul.get(i));
    }

    //indexul primului element egal cu val
    int cauta(const T& val) const {
        for (int i = 0; i < static_cast<int>(elemente.size()); i++)
            if (elemente[i] == val)
                return i;
        return -1;
    }

    int numara(const T& val) const {
        int count = 0;
        for (int i = 0; i < static_cast<int>(elemente.size()); i++)
            if (elemente[i] == val)
                count++;
        return count;
    }

    // in Registru<T>
    template <typename Pred>
    int numara_daca(Pred conditie) const {
        int count = 0;
        for (const auto& e : elemente)
            if (conditie(e))
                count++;
        return count;
    }

    template <typename Pred>
    Registru<T> filtreaza(Pred conditie) const {
        Registru<T> rezultat;
        for (const auto& e : elemente)
            if (conditie(e))
                rezultat.adauga(e);
        return rezultat;
    }
};