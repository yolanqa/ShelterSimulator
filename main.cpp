#include <iostream>
#include <cstring>
#include <ostream>
#include <vector>

#include "Animal.h"
#include "Padoc.h"
#include "Adoptie.h"
#include "Hrana.h"
#include "Adapost.h"
#include "Ingrijitor.h"
#include "Caine.h"
#include "Pisica.h"
#include "Peste.h"
#include "Exceptii.h"

int main() {
    std::cout<< "Numarul initial de animale: "<< Animal::get_nr_total_animale() << "\n";

    Hrana hrana("carne", 200.0, 30.0);
    Caine animal1("Bella", "caine", 25.0, 3, 8, 7, hrana, "paza");
    Pisica animal2("Pupic", "pisica", 4.0, 2, 9, 5, hrana, "siameza");

    Adoptie adoptie1("Raluca Stefanescu", "2025-12-06", false, 150.0, "Bella");
    Adoptie adoptie2("Alina Stoica", "2026-01-05", false, 100.0, "Pupic");

    std::cout << "Specia: " << animal1.get_specie() << "\n";
    std::cout << "Numele: " << animal1.get_nume() << "\n";
    std::cout << "Starea de sanatate: " << animal1.get_stare_sanatate() << "\n";
    std::cout << "Nivelul de sociabilitate: " << animal1.get_nivel_sociabilitate() << "\n";
    std::cout << "Greutatea: " << animal1.get_greutate() << "\n";

    std::vector<std::unique_ptr<Animal>> vec_animale;
    vec_animale.push_back(std::make_unique<Caine>(animal1));
    vec_animale.push_back(std::make_unique<Pisica>(animal2));
    std::vector<Adoptie> vec_adoptii = {adoptie1, adoptie2};

    Padoc padoc(vec_animale, vec_adoptii, 5, "caine/pisica", 300.0);

    std::vector<std::unique_ptr<Padoc>> vec_padocuri;
    vec_padocuri.push_back(std::make_unique<Padoc>(padoc));

    Adapost adapostul_meu(std::move(vec_padocuri), "Speranta", 2000.0);


    std::cout<<adapostul_meu<<std::endl;
    adapostul_meu.trece_timpul(12);
    std::cout<<"Dupa 12 luni: "<<"\n";
    std::cout<<adapostul_meu<<"\n";

    std::vector<std::unique_ptr<Padoc>> vec_padocuri2;
    vec_padocuri2.push_back(std::make_unique<Padoc>(padoc));
    Adapost adapost(std::move(vec_padocuri2), "Adapostul Sperantei", 500.0);


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



    Caine animal3("Dingo", "caine", 45.0, 9, 7, 9, hrana, "paza");
    padoc.adauga_animal(animal3);
    animal3.afiseaza_stare();
    std::cout<<"Bella este data inspre adoptie: "<<animal1.este_de_adoptat()<<"\n";

    const Animal* recomandat = padoc.animal_recomandat();
    if (recomandat != nullptr)
        std::cout<<"Recomandat pentru adoptie: "<<*recomandat<<"\n";
    else
        std::cout<<"Recomandat pentru adoptie: nullptr\n";

    padoc.hraneste_toate(hrana2);


    std::cout << "Venituri pentru adoptiile aprobate: " << padoc.venituri_adoptii() << " Ron\n";


    adapost.raport();

    adapost.afiseaza_padocuri();


    Padoc padoc2({}, {}, 3, "hamsteri", 150.0);
    adapost.adauga_padoc(padoc2);
    adapost.afiseaza_padocuri();



    std::cout << "Poate cumpara hrana: "
              << adapost.poate_cumpara_hrana(200.0) << "\n";


    Ingrijitor ingrijitor ("Stefan Ghetu", 5, "veterinar",6000.0);
    std::cout << ingrijitor << "\n";
    std::cout << "Vechimea: "<<ingrijitor.vechime_in_adapost() << "\n";
    ingrijitor.afisare_salariu();
    ingrijitor.alocare_padocuri(padoc, hrana2);


    Animal* a = new Caine("Rex", "caine", 25.0, 3, 8, 7, hrana, "paza");


    Caine* c = dynamic_cast<Caine*>(a);
    if (c != nullptr)
        std::cout << "Este caine din grupa: " << c->get_grupa() << "\n";
    else
        std::cout << "Nu este caine\n";

    delete a;


    try {
        Caine c_invalid("Invalid", "caine", 25.0, 3, 8, 7, hrana, "");
    } catch (const RasaInvalidaException& e) {
        std::cout << "Eroare rasa: " << e.what() << "\n";
    }

    try {
        Peste p_invalid("Nemo", "peste", 0.5, 1, 9, 3, hrana, "");
    } catch (const ApaInvalidaException& e) {
        std::cout << "Eroare apa: " << e.what() << "\n";
    }

    try {
        std::vector<std::unique_ptr<Padoc>> vec_gol;
        Adapost adapost_sarac(std::move(vec_gol), "Adapost sarac", 0.0);
        Padoc padoc_nou({}, {}, 3, "iepuri", 100.0);
        adapost_sarac.adauga_padoc(padoc_nou);
    } catch (const BugetInsuficientException& e) {
        std::cout << "Eroare buget: " << e.what() << "\n";
    }

    std::cout << "Exista animal critic: " << padoc.exista_animal_critic() << "\n";
    std::cout << "Animale adoptabile: " << padoc.numar_animale_adoptabile() << "\n";
    std::cout << "Total animale in adapost: " << adapost.total_animale() << "\n";

    return 0;
}