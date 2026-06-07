//
// Created by Lenovo ThinkBook on 6/7/2026.
//

#pragma once
#include <vector>
#include <stdexcept>

template <typename T>
class Registru {
    std::vector<T> elemente;

public:
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
};