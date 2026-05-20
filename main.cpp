#include <iostream>

#include <ostream>
#include <vector>
#include <memory>

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
#include "Iepure.h"
int main() {

    std::string nume_adapost;
    double buget_adapost;
    int luni_simulare;

    std::string nume_caine;
    std::string grupa_caine;

    std::string nume_peste;
    std::string apa_peste;

    std::string nume_pisica;
    std::string rasa_pisica;

    std::string nume_ingrijitor;
    std::string post_ingrijitor;
    int vechime_ingrijitor;
    double salariu_ingrijitor;

    std::cout << "Introduceti numele adapostului: ";
    std::getline(std::cin, nume_adapost);

    std::cout << "Introduceti bugetul adapostului: ";
    std::cin >> buget_adapost;

    std::cout << "Introduceti numarul de luni pentru simulare: ";
    std::cin >> luni_simulare;
    std::cin.ignore();

    std::cout << "Introduceti numele noului caine: ";
    std::getline(std::cin, nume_caine);

    std::cout << "Introduceti grupa cainelui: ";
    std::getline(std::cin, grupa_caine);

    std::cout << "Introduceti numele noului peste: ";
    std::getline(std::cin, nume_peste);

    std::cout << "Introduceti tipul de apa in care traieste pestele: ";
    std::getline(std::cin, apa_peste);

    std::cout << "Introduceti numele noii pisici: ";
    std::getline(std::cin, nume_pisica);

    std::cout << "Introduceti rasa pisicii: ";
    std::getline(std::cin, rasa_pisica);

    std::cout << "Introduceti numele ingrijitorului: ";
    std::getline(std::cin, nume_ingrijitor);

    std::cout << "Introduceti postul ingrijitorului: ";
    std::getline(std::cin, post_ingrijitor);

    std::cout << "Introduceti vechimea ingrijitorului: ";
    std::cin >> vechime_ingrijitor;

    std::cout << "Introduceti salariul ingrijitorului: ";
    std::cin >> salariu_ingrijitor;
    std::cout<<"\n";
    std::cout << "Numarul initial de animale: " << Animal::get_nr_total_animale() << "\n";

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

    Adapost adapostul_meu(std::move(vec_padocuri), nume_adapost, buget_adapost);

    std::cout << adapostul_meu << std::endl;
    adapostul_meu.trece_timpul(luni_simulare);
    std::cout << "Dupa " << luni_simulare << " luni:\n";
    std::cout << adapostul_meu << "\n";

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

    animal1.sunet();
    animal2.sunet();

    adoptie1.aprobare();
    adoptie1.genereaza_contract();
    adoptie2.genereaza_contract();

    Adoptie adoptie3("Maria Preotu", "2026-03-10", false, 120.0, nume_caine);
    padoc.adauga_adoptie(adoptie3);

    std::cout << "Bella si Pupic sunt compatibile: " << animal1.este_compatibil(animal2) << "\n";

    Hrana hrana2("bobite", 100.0, 10.0);
    animal1.hraneste(hrana2);
    animal1.imbatraneste();
    std::cout << "Dupa hranire si procesul de imbatranire: " << animal1 << "\n";

    // folosim datele citite de la tastatura
    Caine animal3(nume_caine.c_str(), "caine", 20.0, 2, 8, 7, hrana, grupa_caine);
    padoc.adauga_animal(animal3);
    animal3.afiseaza_stare();
    animal3.sunet();

    Peste animal4(nume_peste.c_str(), "peste", 0.5, 1, 9, 3, hrana, apa_peste);
    std::cout << animal4 << "\n";
    std::cout << "Tipul apei: " << animal4.get_apa() << "\n";
    animal4.sunet();
    std::cout << "Taxa adoptie pentru peste: " << animal4.calculeaza_taxa_adoptie() << " Ron\n";

    Pisica animal5(nume_pisica.c_str(), "pisica", 3.0, 2, 8, 6, hrana, rasa_pisica);
    std::cout << animal5 << "\n";
    std::cout << "Rasa pisicii: " << animal5.get_rasa() << "\n";
    animal5.sunet();
    std::cout << "Taxa adoptie pentru pisica: " << animal5.calculeaza_taxa_adoptie() << " Ron\n";

    std::cout << "Bella este data spre adoptie: " << animal1.este_de_adoptat() << "\n";

    Iepure animal6("Fluffy", "iepure", 1.5, 1, 9, 8, hrana, "alb");
    std::cout << animal6 << "\n";
    std::cout << "Culoarea: " << animal6.get_culoare() << "\n";
    animal6.sunet();
    std::cout << "Taxa adoptie iepure: " << animal6.calculeaza_taxa_adoptie() << " Ron\n";
    const Animal* recomandat = padoc.animal_recomandat();
    if (recomandat != nullptr)
        std::cout << "Recomandat pentru adoptie: " << *recomandat << "\n";
    else
        std::cout << "Recomandat pentru adoptie: nullptr\n";

    padoc.hraneste_toate(hrana2);
    padoc.sorteaza_dupa_stare_sanatate();
    std::cout << "Animale sortate dupa stare de sanatate:\n";
    std::cout << padoc << "\n";


    std::cout << "Venituri pentru adoptiile aprobate: " << padoc.venituri_adoptii() << " Ron\n";

    adapost.raport();
    adapost.afiseaza_padocuri();

    Padoc padoc2({}, {}, 3, "hamsteri", 150.0);
    adapost.adauga_padoc(padoc2);
    adapost.afiseaza_padocuri();

    std::cout << "Poate cumpara hrana: " << adapost.poate_cumpara_hrana(200.0) << "\n";

    std::cout << "Taxa adoptie Bella: " << animal1.calculeaza_taxa_adoptie() << " Ron\n";
    std::cout << "Taxa adoptie Pupic: " << animal2.calculeaza_taxa_adoptie() << " Ron\n";

    Ingrijitor ingrijitor(nume_ingrijitor.c_str(), vechime_ingrijitor, post_ingrijitor, salariu_ingrijitor);
    std::cout << ingrijitor << "\n";
    std::cout << "Vechimea: " << ingrijitor.vechime_in_adapost() << "\n";
    ingrijitor.afisare_salariu();
    ingrijitor.alocare_padocuri(padoc, hrana2);

    const Animal* a = new Caine("Rex", "caine", 25.0, 3, 8, 7, hrana, "paza");
    const Caine* c = dynamic_cast<const Caine*>(a);
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