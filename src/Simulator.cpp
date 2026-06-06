//
// Created by Lenovo ThinkBook on 5/21/2026.
//

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
#include"Simulator.h"
#include "CentruInregistrare.h"
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

        return val;
    }

    std::string Simulator::citesteString(const std::string& mesaj) {
        std::string val;
        std::cout << mesaj;
        std::cin.ignore();
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
                std::cout << "1. Caine\n 2. Pisica\n 3. Peste\n 4. Iepure\n";
                int alegere = citesteInt("> ");
                std::string tip;
                if (alegere == 1) tip = "caine";
                else
                    if (alegere == 2) tip = "pisica";
                else
                    if (alegere == 3) tip = "peste";
                else
                    if (alegere == 4) tip = "iepure";
                else {
                    invalid(); break;
                }

                std::string nume = citesteString("Nume animal: ");
                std::string atribut = citesteString("Atribut specific (grupa/rasa/apa/culoare): ");

                try {
                    Animal* a = CentruInregistrare::inregistreaza(tip, nume, 20.0, 2, 8, 7, hrana_default, atribut);
                    adapost->adauga_animal_in_primul_padoc(*a);
                    delete a;
                    std::cout << "Animal inregistrat cu succes!\n";
                } catch (const AdapostException& e) {
                    std::cout << "Eroare: " << e.what() << "\n";
                } catch (const std::invalid_argument& e) {
                    std::cout << "Eroare: " << e.what() << "\n";
                }
                break;
            }
            case 3:
                adapost->hraneste_toate(hrana_default);
                adapost->sorteaza_animale_primul_padoc();
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
        std::cout << "Total animale inregistrate: " << Animal::get_nr_total_animale() << "\n";
        std::cout << "ID contor: " << Animal::get_contor_id() << "\n";
        std::cout << "Cel mai batran animal: " << adapost->animal_cel_mai_batran() << "\n";
    }

    void Simulator::meniuSimulare() {
        titlu("SIMULARE");
        int luni = citesteInt("Introduceti numarul de luni: ");
        adapost->trece_timpul(luni);
        std::cout << "Simulare finalizata!\n";
        std::cout << *adapost;
    }

    void Simulator::ruleaza() {
        adapost->afiseaza_padocuri();
        while (activ) {
            titlu("MENIU PRINCIPAL - " + adapost->get_nume());
            std::cout << "1. Gestiune animale\n"
                    << "2. Adoptii\n"
                    << "3. Statistici\n"
                    << "4. Simuleaza trecerea timpului\n"
                    << "5. Afiseaza padocuri\n"
                    << "6. Extra\n"
                    << "0. Iesire\n";
            int opt = citesteInt("> ");
            switch (opt) {
                case 1: meniuAnimale();    break;
                case 2: meniuAdoptii();    break;
                case 3: meniuStatistici(); break;
                case 4: meniuSimulare();   break;
                case 5: adapost->afiseaza_padocuri(); break;
                case 6: meniuExtra(); break;
                case 0:
                    activ = false;
                    std::cout << "Pa pa!\n";
                    break;
                default: invalid();
            }
        }
    }

    void Simulator::meniuExtra() {
        titlu("FUNCTII EXTRA");
        std::cout << "1. Verifica compatibilitate animale\n"
                  << "2. Genereaza contract adoptie\n"
                  << "3. Verifica ingrijitor\n"
                  << "4. Statistici extra\n"
                  << "5. Verifica simulare\n"
                  << "0. Inapoi\n";

        int opt = citesteInt("> ");
        switch (opt) {
            case 1: {
                Caine c1("Test1", "caine", 20.0, 2, 8, 7, hrana_default, "paza");
                Caine c2("Test2", "caine", 15.0, 3, 4, 5, hrana_default, "frumusete");
                std::cout << "Compatibili: " << c1.este_compatibil(c2) << "\n";

                Animal* a = new Caine("Rex", "caine", 25.0, 3, 8, 7, hrana_default, "paza");
                const Caine* c = dynamic_cast<const Caine*>(a);
                if (c != nullptr)
                    std::cout << "Este caine din grupa: " << c->get_grupa() << "\n";
                else
                    std::cout << "Nu este caine\n";
                delete a;
                break;
            }
            case 2: {
                Adoptie ad("Test", "2026-01-01", false, 100.0, "Test");
                ad.aprobare();
                ad.genereaza_contract();
                break;
            }
            case 3: {
                Ingrijitor ing("Test", 5, "veterinar", 3000.0);
                std::cout << ing << "\n";
                std::cout << "Vechime: " << ing.vechime_in_adapost() << "\n";
                ing.afisare_salariu();
                Padoc p_temp({}, {}, 5, "temp", 100.0);
                ing.alocare_padocuri(p_temp, hrana_default);
                //Ingrijitor ing1("Stefan", 5, "veterinar", 3000.0);
                Animal* pacient = new Caine("Rex", "caine", 25.0, 3, 4, 7, hrana_default, "paza");
                ing.aplica_tratament(pacient);
                delete pacient;
                break;
            }
            case 4: {
                std::cout << "Animale adoptabile: " << adapost->numar_animale_adoptabile() << "\n";
                std::cout << "Taxa medie adoptie: " << adapost->taxa_medie_adoptie() << " Ron\n";
                std::cout << "Cel mai aglomerat padoc: " << adapost->cel_mai_aglomerat_padoc() << "\n";
                std::cout << "Poate cumpara hrana: " << adapost->poate_cumpara_hrana(200.0) << "\n";
                break;
            }

            case 5: {
                Caine c1("Test1", "caine", 20.0, 2, 8, 7, hrana_default, "paza");
                Caine c2("Test2", "caine", 15.0, 3, 4, 5, hrana_default, "frumusete");
                c1.afiseaza_stare();
                c1.imbatraneste();

                std::cout << "Necesita ingrijire: " << c1.necesita_ingrijire_urgenta() << "\n";
                std::cout << "Compatibili: " << c1.este_compatibil(c2) << "\n";
                std::cout << "Greutate: " << c1.get_greutate() << "\n";
                std::cout << "ID: " << c1.get_id() << "\n";
                std::cout << "Specie: " << c1.get_specie() << "\n";
                std::cout << "Grupa: " << c1.get_grupa() << "\n";

                Pisica p1("TestP", "pisica", 4.0, 2, 8, 6, hrana_default, "siameza");
                std::cout << "Rasa: " << p1.get_rasa() << "\n";
                Peste pe1("TestPe", "peste", 0.5, 1, 9, 3, hrana_default, "dulce");
                std::cout << "Apa: " << pe1.get_apa() << "\n";
                Iepure i1("TestI", "iepure", 1.5, 1, 9, 8, hrana_default, "alb");

                std::cout << "Culoare: " << i1.get_culoare() << "\n";

                adapost->sorteaza_animale_primul_padoc();
                adapost->raport();
                Padoc p_test({}, {}, 3, "test", 100.0);
                Adoptie ad_test("Ion", "2026-01-01", true, 100.0, "Rex");
                p_test.adauga_adoptie(ad_test);

                std::cout << "Venituri: " << p_test.venituri_adoptii() << " Ron\n";
                std::cout << "Exista animal critic: " << p_test.exista_animal_critic() << "\n";

                Animal* a1 = new Caine("Max", "caine", 25.0, 3, 8, 7, hrana_default, "paza");
                Animal* a2 = new Iepure("Gogonas", "iepure", 1.5, 1, 9, 8, hrana_default, "alb");
                Animal* a3 = new Pisica("Mia", "pisica", 4.0, 2, 8, 6, hrana_default, "siameza");
                Animal* a4 = new Peste("Nemo", "peste", 0.5, 1, 9, 3, hrana_default, "dulce");

                a1->se_joaca_cu(a2);
                a1->se_joaca_cu(a3);
                a3->se_joaca_cu(a3);
                a4->se_joaca_cu(a1);
                a2->se_joaca_cu(a1);
                delete a1;
                delete a2;
                delete a3;
                delete a4;


                std::cout << "Categoria hranei: " << hrana_default.categorie_hrana() << "\n";
                Hrana h_morcovi("morcovi", 50.0, 10.0);
                Iepure i_test("Fluffy", "iepure", 1.5, 1, 9, 8, hrana_default, "alb");
                std::cout << "Fluffy accepta morcovi: " << i_test.accepta_hrana(h_morcovi) << "\n";
                std::cout << "Fluffy accepta carne: " << i_test.accepta_hrana(hrana_default) << "\n";


                Hrana h_peste("mancare_peste", 30.0, 15.0);
                std::cout << "Nemo accepta mancare_peste: " << pe1.accepta_hrana(h_peste) << "\n";
                std::cout << "c1 accepta carne: " << c1.accepta_hrana(hrana_default) << "\n";
                break;

            }
            case 0: break;
            default: invalid();
        }
    }