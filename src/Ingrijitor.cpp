//
// Created by Lenovo ThinkBook on 4/6/2026.
//
#include <iostream>
#include <string>
#include "Hrana.h"
#include "Ingrijitor.h"
#include "Padoc.h"
#include<cstring>


    void Ingrijitor::copy_nume(const char* src) {
        if (src) {
            nume = new char[strlen(src)+1];
            strcpy(nume, src);
        }
        else {
            nume = nullptr;
        }
    }

    Ingrijitor::Ingrijitor(const char *nume, const int vechime, const std::string& post, const double salariu)
        :
          vechime(vechime),
          post(post),
          salariu(salariu) {copy_nume(nume);}


    Ingrijitor::Ingrijitor(const Ingrijitor &other)
        :vechime(other.vechime), post(other.post),
          salariu(other.salariu) {copy_nume(other.nume);}



    Ingrijitor& Ingrijitor::operator=(const Ingrijitor &other) {
        if (this != &other){
            delete [] nume;

            copy_nume(other.nume);
            vechime = other.vechime;
            post = other.post;
            salariu = other.salariu;
        }
        return *this;
    }
    Ingrijitor::~Ingrijitor() {delete [] nume;}

    void Ingrijitor::afisare_salariu() const {
        std::cout<<(nume?nume:"(null)")<<": "<<salariu<<" Ron\n";
    }

    bool Ingrijitor::vechime_in_adapost()const {
        if (vechime < 5)
            return false;
        else
            return true;
    }

    void Ingrijitor::alocare_padocuri(Padoc& p,const Hrana& h)const {
        std::cout<<(nume?nume:"(null)")<<" are macar un padoc de hranit.\n";
        p.hraneste_toate(h);
    }

    std::ostream & operator<<(std::ostream &os, const Ingrijitor &obj) {
         os << "nume: " << (obj.nume?obj.nume:"(null)")
            << " | vechime: " << obj.vechime
            << " | post: " << obj.post
            << " | salariu: " << obj.salariu;
    }


