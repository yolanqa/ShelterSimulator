//
// Created by Lenovo ThinkBook on 5/21/2026.
//

#include "SImulator.h"
#include "Caine.h"
#include "Pisica.h"
#include "Peste.h"
#include "Iepure.h"
#include "Exceptii.h"
#include <iostream>

    void Simulator::titlu(const std::string& text) {
        std::cout << "\n=== " << text << " ===\n";
    }

    void Simulator::invalid() {std::cout << "Optiune invalida!\n";
    }

    int Simulator::citesteInt(const std::string& mesaj) {
        int val;
        std::cout << mesaj;
        while (!(std::cin >> val)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input invalid!\n" << mesaj;
        }
        std::cin.ignore();
        return val;
    }

    std::string Simulator::citesteString(const std::string& mesaj) {
        std::string val;
        std::cout << mesaj;

        std::getline(std::cin, val);
        return val;
    }

    Simulator::Simulator(const std::string& nume_adapost, double buget, const Hrana& hrana)
        : hrana_default(hrana), activ(true) {
        std::vector<std::unique_ptr<Padoc>> padocuri_initiale;
        Padoc p_initial({}, {}, 10, "general", 300.0);
        padocuri_initiale.push_back(std::make_unique<Padoc>(p_initial));
        adapost = new Adapost(std::move(padocuri_initiale), nume_adapost, buget);
    }

    Simulator::~Simulator() {
        delete adapost;
    }

    void Simulator::meniuAnimale() {
        titlu("GESTIUNE ANIMALE");
        std::cout << "1. Adauga padoc nou\n"
                << "2. Adauga animal in primul padoc\n"
                << "3. Hraneste toate animalele\n"
                << "4. Sorteaza dupa stare sanatate\n"
                << "0. Inapoi\n";
        int opt = citesteInt("> ");
        switch (opt) {
            case 1: {
                std::string tip = citesteString("Tip animale in padoc: ");
                double buget_padoc = citesteInt("Buget padoc: ");
                int capacitate = citesteInt("Capacitate padoc: ");
                Padoc p({}, {}, capacitate, tip, buget_padoc);
                try {
                    adapost->adauga_padoc(p);
                    std::cout << "Padoc adaugat!\n";
                } catch (const BugetInsuficientException& e) {
                    std::cout << "Eroare: " << e.what() << "\n";
                }
                break;
            }
            case 2: {
                titlu("SELECTEAZA ANIMAL");
                std::cout << "1. Caine\n2. Pisica\n3. Peste\n4. Iepure\n";
                int alegere = citesteInt("> ");
                std::string nume = citesteString("Nume animal: ");
                try {
                    if (alegere == 1) {
                        std::string grupa = citesteString("Grupa (de paza/de frumusete): ");
                        Caine c(nume.c_str(), "caine", 20.0, 2, 8, 7, hrana_default, grupa);
                        adapost->adauga_animal_in_primul_padoc(c);
                    } else if (alegere == 2) {
                        std::string rasa = citesteString("Rasa (persana/siameza/bengaleza): ");
                        Pisica p(nume.c_str(), "pisica", 4.0, 2, 8, 6, hrana_default, rasa);
                        adapost->adauga_animal_in_primul_padoc(p);
                    } else if (alegere == 3) {
                        std::string apa = citesteString("Tip apa (dulce/sarata): ");
                        Peste p(nume.c_str(), "peste", 0.5, 1, 9, 3, hrana_default, apa);
                        adapost->adauga_animal_in_primul_padoc(p);
                    } else if (alegere == 4) {
                        std::string culoare = citesteString("Culoare (alb/negru): ");
                        Iepure i(nume.c_str(), "iepure", 1.5, 1, 9, 8, hrana_default, culoare);
                        adapost->adauga_animal_in_primul_padoc(i);
                    } else invalid();
                } catch (const AdapostException& e) {
                    std::cout << "Eroare: " << e.what() << "\n";
                }
                break;
            }
            case 3:
                adapost->hraneste_toate(hrana_default);
                std::cout << "Animale hranite!\n";
                break;
            case 4:
                adapost->sorteaza_animale_primul_padoc();
                std::cout << "Sortat!\n";
                break;
            case 0: break;
            default: invalid();
        }
    }

    void Simulator::meniuAdoptii() {
        titlu("ADOPTII");
        std::cout << "1. Afiseaza animal recomandat\n"
                << "2. Afiseaza animale adoptabile\n"
                << "3. Afiseaza taxa medie adoptie\n"
                << "0. Inapoi\n";
        int opt = citesteInt("> ");
        switch (opt) {
            case 1:
                adapost->afiseaza_animal_recomandat();
                break;
            case 2:
                std::cout << "Animale adoptabile: " << adapost->numar_animale_adoptabile() << "\n";
                break;
            case 3:
                std::cout << "Taxa medie: " << adapost->taxa_medie_adoptie() << " Ron\n";
                break;
            case 0: break;
            default: invalid();
        }
    }

    void Simulator::meniuStatistici() {
        titlu("STATISTICI");
        std::cout << *adapost;
        std::cout << "Total animale: " << adapost->total_animale() << "\n";
        std::cout << "Cost de intretinere: " << adapost->cost_intretinere() << " Ron\n";
        std::cout << "Cel mai aglomerat padoc: " << adapost->cel_mai_aglomerat_padoc() << "\n";
        std::cout << "Total adaposturi create: " << Adapost::get_nr_total_adaposturi() << "\n";
        std::cout << "Total animale create: " << Animal::get_contor_id() << "\n";
    }

    void Simulator::meniuSimulare() {
        titlu("SIMULARE");
        int luni = citesteInt("Introduceti numarul de luni: ");
        adapost->trece_timpul(luni);
        std::cout << "Simulare finalizata!\n";
        std::cout << *adapost;
    }

    void Simulator::ruleaza() {
        while (activ) {
            titlu("MENIU PRINCIPAL - " + adapost->get_nume());
            std::cout << "1. Gestiune animale\n"
                    << "2. Adoptii\n"
                    << "3. Statistici\n"
                    << "4. Simuleaza trecerea timpului\n"
                    << "5. Afiseaza padocuri\n"
                    << "0. Iesire\n";
            int opt = citesteInt("> ");
            switch (opt) {
                case 1: meniuAnimale();    break;
                case 2: meniuAdoptii();    break;
                case 3: meniuStatistici(); break;
                case 4: meniuSimulare();   break;
                case 5: adapost->afiseaza_padocuri(); break;
                case 0:
                    activ = false;
                    std::cout << "Pa pa!\n";
                    break;
                default: invalid();
            }
        }
    }