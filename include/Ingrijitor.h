//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#pragma once

#include<cstring>
#include <ostream>
#include <string>
#include "Padoc.h"
#include "Hrana.h"
#include "Caine.h"
#include "Pisica.h"
#include "Peste.h"

#include "Iepure.h"
class Ingrijitor {
    char* nume;
    int vechime;
    std::string post;
    double salariu;


    void copy_nume(const char* src);

public:
    Ingrijitor(const char *nume, const int vechime, const std::string& post, const double salariu);

    Ingrijitor(const Ingrijitor &other);


    Ingrijitor & operator=(const Ingrijitor &other);

    ~Ingrijitor();

    void afisare_salariu() const;
    static void aplica_tratament(Animal* a);

    bool vechime_in_adapost()const;

    void alocare_padocuri(Padoc& p,const Hrana& h)const;

    friend std::ostream & operator<<(std::ostream &os, const Ingrijitor &obj);

};

