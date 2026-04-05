#include <iostream>
#include <cstring>
#include <ostream>
#include <vector>
#include "include/Example.h"


class Hrana {
private:
    std::string tip;
    double cantitate;
    double valoare_nutritiva;

public:
    Hrana(const std::string &tip, const double cantitate, const double valoare_nutritiva)
        : tip(tip), cantitate(cantitate), valoare_nutritiva(valoare_nutritiva) {}

    Hrana(const Hrana &other)
        : tip(other.tip), cantitate(other.cantitate), valoare_nutritiva(other.valoare_nutritiva) {}

    Hrana &operator=(const Hrana &other) {
        if (this == &other) return *this;
        tip = other.tip;
        cantitate = other.cantitate;
        valoare_nutritiva = other.valoare_nutritiva;
        return *this;
    }

    ~Hrana() = default;

    [[nodiscard]] double get_valoare_nutritiva() const { return valoare_nutritiva; }

    friend std::ostream &operator<<(std::ostream &os, const Hrana &obj) {
        return os << "tip: " << obj.tip
                  << " cantitate: " << obj.cantitate
                  << " valoare_nutritiva: " << obj.valoare_nutritiva;
    }
};


class Animal {
private:
    char *nume;
    std::string specie;
    double greutate;
    int varsta;
    int stare_sanatate;
    int nivel_sociabilitate;
    Hrana hrana_preferata;

    void copiaza_nume(const char *src) {
        if (src) {
            nume = new char[strlen(src) + 1];
            strcpy(nume, src);
        } else {
            nume = nullptr;
        }
    }

public:
    Animal(const char *nume, const std::string &specie, const double greutate,
           const int varsta, const int stare_sanatate, const int nivel_sociabilitate,
           const Hrana &hrana_preferata)
        : specie(specie), greutate(greutate), varsta(varsta),
          stare_sanatate(stare_sanatate), nivel_sociabilitate(nivel_sociabilitate),
          hrana_preferata(hrana_preferata) {
        copiaza_nume(nume);
    }

    Animal(const Animal &other)
        : specie(other.specie), greutate(other.greutate), varsta(other.varsta),
          stare_sanatate(other.stare_sanatate), nivel_sociabilitate(other.nivel_sociabilitate),
          hrana_preferata(other.hrana_preferata) {
        copiaza_nume(other.nume);
    }

    Animal &operator=(const Animal &other) {
        if (this == &other) return *this;
        delete[] nume;
        copiaza_nume(other.nume);
        specie = other.specie;
        greutate = other.greutate;
        varsta = other.varsta;
        stare_sanatate = other.stare_sanatate;
        nivel_sociabilitate = other.nivel_sociabilitate;
        hrana_preferata = other.hrana_preferata;
        return *this;
    }

    ~Animal() { delete[] nume; }

    [[nodiscard]] double get_greutate() const { return greutate; }
    [[nodiscard]] int get_stare_sanatate() const { return stare_sanatate; }
    [[nodiscard]] int get_nivel_sociabilitate() const { return nivel_sociabilitate; }
    [[nodiscard]] std::string get_specie() const { return specie; }
    [[nodiscard]] std::string get_nume() const { return nume ? std::string(nume) : ""; }

    void hraneste(const Hrana &h) {
        greutate += h.get_valoare_nutritiva() * 0.1;
    }

    void imbatraneste() {
        varsta++;
        if (greutate > 5.0) greutate -= 0.5;
    }

    bool este_compatibil(const Animal &other) const {
        return this->specie == other.specie;
    }

    void afiseaza_stare() const {
        std::cout << "Starea lui " << (nume ? nume : "(null)") << ": ";
        if (stare_sanatate <= 3)
            std::cout << "stare critica\n";
        else if (stare_sanatate <= 6)
            std::cout << "stare cat-de-cat buna\n";
        else
            std::cout << "stare buna\n";
    }

    bool este_de_adoptat() const {
        if (stare_sanatate >= 5 && varsta <= 10) { return true;}
        else return false;
    }

    friend std::ostream &operator<<(std::ostream &os, const Animal &obj) {
        return os << "nume: " << (obj.nume ? obj.nume : "(null)")
                  << " specie: " << obj.specie
                  << " greutate: " << obj.greutate
                  << " varsta: " << obj.varsta
                  << " stare_sanatate: " << obj.stare_sanatate
                  << " nivel_sociabilitate: " << obj.nivel_sociabilitate
                  << " hrana_preferata: [" << obj.hrana_preferata << "]";
    }
};

class Adoptie {
private:
    std::string nume_adoptator;
    std::string data_adoptie;
    bool aprobata;
    double taxa;
    std::string nume_animal;

public:
    Adoptie(const std::string &nume_adoptator, const std::string &data_adoptie,
            const bool aprobata, const double taxa, const std::string &nume_animal)
        : nume_adoptator(nume_adoptator), data_adoptie(data_adoptie),
          aprobata(aprobata), taxa(taxa), nume_animal(nume_animal) {}

    void aprobare() {
        aprobata = true;
        std::cout << "Adoptia facuta pentru " << nume_animal << " a fost aprobata!\n";
    }

    void genereaza_contract() const {
        std::cout << "Contract Adoptie\n";
        std::cout << "Adoptator: " << nume_adoptator << "\n";
        std::cout << "Animal: " << nume_animal << "\n";
        std::cout << "Data: " << data_adoptie << "\n";
        std::cout << "Taxa: " << taxa << " Ron\n";
        std::cout << "Statut: " << (aprobata ? "Aprobata": "In asteptare") << "\n";

    }

    [[nodiscard]] bool este_aprobata() const { return aprobata; }
    [[nodiscard]] double get_taxa() const { return taxa; }

    friend std::ostream &operator<<(std::ostream &os, const Adoptie &obj) {
        return os << "adoptator: " << obj.nume_adoptator
                  << " animal: " << obj.nume_animal
                  << " data: " << obj.data_adoptie
                  << " taxa: " << obj.taxa
                  << " aprobata: " << obj.aprobata;
    }
};

class Padoc {
private:
    std::vector<Animal> vector_animale;
    std::vector<Adoptie> vector_adoptii;
    int capacitate;
    std::string tip_animale;
    double buget_sectiune;

public:
    Padoc(const std::vector<Animal> &animale, const std::vector<Adoptie> &adoptii,
             const int capacitate, const std::string &tip_animale, const double buget_sectiune)
        : vector_animale(animale), vector_adoptii(adoptii),
          capacitate(capacitate), tip_animale(tip_animale), buget_sectiune(buget_sectiune) {}

    bool adauga_animal(const Animal &a) {
        if (static_cast<int>(vector_animale.size()) < capacitate) {
            vector_animale.push_back(a);
            return true;
        }
        std::cout << "Padocul este plin! Nu se poate adauga un alt animal.\n";
        return false;
    }

    void hraneste_toate(const Hrana &h) {
        for (auto &an: vector_animale)
            an.hraneste(h);
    }

    double venituri_adoptii() const {
        double total = 0;
        for (const auto &ad: vector_adoptii)
            if (ad.este_aprobata())
                total += ad.get_taxa();
        return total;
    }
    void adauga_adoptie(const Adoptie &a) {
        vector_adoptii.push_back(a);
        std::cout << "Adoptia a fost adaugata cu succes!\n";
    }

    [[nodiscard]] int get_numar_animale() const {
        return static_cast<int>(vector_animale.size());
    }

    Animal* animal_recomandat() {
        for (auto &a: vector_animale) {
            if (a.este_de_adoptat()) return &a;
        }
        return nullptr;
    }



    friend std::ostream &operator<<(std::ostream &os, const Padoc &obj) {
        return os << "tipul animalelor: " << obj.tip_animale
                  << " capacitate: " << obj.capacitate
                  << " animale prezente in padoc: " << obj.vector_animale.size()
                  << " buget per padoc: " << obj.buget_sectiune;
    }

    ~Padoc() = default;
};

class Adapost {
private:
    std::vector<Padoc> padocuri;
    std::string nume;
    double buget;

public:
    Adapost(const std::vector<Padoc> &padocuri, const std::string &nume, const double buget)
        : padocuri(padocuri), nume(nume), buget(buget) {}

    double cost_intretinere() const {
        return padocuri.size() * 50.0;
    }

    bool poate_cumpara_hrana(const double pret) const {
        return buget >= cost_intretinere() + pret;
    }

    void raport() const {
        std::cout << "Raport: " << nume << "\n";
        std::cout << "Numar padocuri: " << padocuri.size() << "\n";
        int total_animale = 0;
        for (const auto &s : padocuri)
            total_animale += s.get_numar_animale();
        std::cout << "Total animale: " << total_animale << "\n";
        std::cout << "Cost intretinere: " << cost_intretinere() << " Ron\n";
        std::cout << "Buget ramas: " << buget - cost_intretinere() << " Ron\n";

    }



    friend std::ostream &operator<<(std::ostream &os, const Adapost &obj) {
        return os << "nume: " << obj.nume
                  << " buget: " << obj.buget
                  << " padocuri: " << obj.padocuri.size();
    }

    ~Adapost() = default;
};

class Ingrijitor {
    char* nume;
    int vechime;
    std::string post;
    double salariu;


    void copy_nume(const char* src) {
        if (src) {
            nume = new char[strlen(src)+1];
            strcpy(nume, src);
        }
        else {
            nume = nullptr;
        }
    }

public:
    Ingrijitor(const char *nume, const int vechime, const std::string post, const double salariu)
        :
          vechime(vechime),
          post(post),
          salariu(salariu) {copy_nume(nume);}


    Ingrijitor(const Ingrijitor &other)
        :vechime(other.vechime), post(other.post),
          salariu(other.salariu) {copy_nume(other.nume);}



    Ingrijitor & operator=(const Ingrijitor &other) {
        if (this == &other)
            return *this;
        delete [] nume;
        copy_nume(other.nume);
        vechime = other.vechime;
        post = other.post;
        salariu = other.salariu;
        return *this;
    }
    ~Ingrijitor() {delete [] nume;}

    void afisare_salariu() const {
        std::cout<<(nume?nume:"(null)")<<": "<<salariu<<" Ron\n";
    }

    bool vechime_in_adapost()const {
        if (vechime < 5) return false;
        else return true;
    }

    void alocare_padocuri(Padoc& p,const Hrana& h)const {
        std::cout<<(nume?nume:"(null")<<" are macar un padoc de hranit.\n";
        p.hraneste_toate(h);
    }

    friend std::ostream & operator<<(std::ostream &os, const Ingrijitor &obj) {
        return os
               << "nume: " << (obj.nume?obj.nume:"(null)")
               << "vechime: " << obj.vechime
               << "post: " << obj.post
               << "salariu: " << obj.salariu;
    }

};





int main() {

    Hrana hrana("carne", 200.0, 30.0);
    Animal animal1("Bella", "caine", 25.0, 3, 8, 7, hrana);
    Animal animal2("Pupic", "pisica", 4.0, 2, 9, 5, hrana);

    Adoptie adoptie1("Raluca Stefanescu", "2025-12-06", false, 150.0, "Bella");
    Adoptie adoptie2("Alina Stoica", "2026-01-05", false, 100.0, "Pupic");

    std::vector<Animal> vec_animale = {animal1, animal2};
    std::vector<Adoptie> vec_adoptii = {adoptie1, adoptie2};

    Padoc padoc(vec_animale, vec_adoptii, 5, "caine/pisica", 300.0);
    std::vector<Padoc> vec_padocuri = {padoc};

    Adapost adapost(vec_padocuri, "Adapostul Sperantei", 500.0);

    std::cout << hrana << "\n";
    std::cout << animal1 << "\n";
    std::cout << animal2 << "\n";
    std::cout << adoptie1 << "\n";
    std::cout << padoc << "\n";
    std::cout << adapost << "\n\n";


    animal1.afiseaza_stare();
    animal2.afiseaza_stare();


    adoptie1.aprobare();
    adoptie1.genereaza_contract();
    adoptie2.genereaza_contract();


    Adoptie adoptie3("Maria Preotu", "2026-03-10", false, 120.0, "Dingo");
    padoc.adauga_adoptie(adoptie3);


    std::cout << "Bella si Pupic sunt compatibile: " << animal1.este_compatibil(animal2) << "\n";


    Hrana hrana2("bobite", 100.0, 10.0);
    animal1.hraneste(hrana2);
    animal1.imbatraneste();
    std::cout << "Dupa hranire si procesul de imbatranire: " << animal1 << "\n";



    Animal animal3("Dingo ", "caine", 45.0, 9, 7, 9, hrana);
    padoc.adauga_animal(animal3);
    animal3.afiseaza_stare();
    std::cout<<"Bella este data inspre adoptie: "<<animal1.este_de_adoptat()<<"\n";

    Animal* recomandat = padoc.animal_recomandat();
    if (recomandat != nullptr)
        std::cout<<"Recomandat pentru adoptie: "<<*recomandat<<"\n";
    else
        std::cout<<"Recomandat pentru adoptie: nullptr\n";

    padoc.hraneste_toate(hrana2);


    std::cout << "Venituri pentru adoptiile aprobate: " << padoc.venituri_adoptii() << " Ron\n";


    adapost.raport();

    std::cout << "Poate cumpara hrana: "
              << adapost.poate_cumpara_hrana(200.0) << "\n";


    Ingrijitor ingrijitor ("Stefan Ghetu", 5, "veterinar",6000.0);
    std::cout << ingrijitor << "\n";
    std::cout << "Vechimea: "<<ingrijitor.vechime_in_adapost() << "\n";
    ingrijitor.afisare_salariu();
    ingrijitor.alocare_padocuri(padoc, hrana2);


    Example e1;
    e1.g();

    return 0;
}