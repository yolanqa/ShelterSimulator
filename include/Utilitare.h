//
// Created by Lenovo ThinkBook on 6/7/2026.
//

#pragma once
#include "Registru.h"

template <typename T>
T maximul(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template <typename T>
T minimul(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <typename T>
void afiseaza_registru(const Registru<T>& r) {
    for (int i = 0; i < r.size(); i++)
        std::cout << "  [" << i << "] " << r.get(i) << "\n";
}


