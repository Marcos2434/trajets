#include <iostream>
#include <cstring>
#include <limits>

#include "classes/Trajet.h"
#include "classes/TrajetSimple.h"
#include "classes/TrajetCompose.h"
#include "classes/Catalogue.h"

using namespace std;


int main() {
    /*
    // Creation des trajets simples
    TrajetSimple TS1('A', 'B', "MT1");
    TrajetSimple TS2('B', 'C', "MT1");

    // TS1.Afficher();
    // TS2.Afficher();

    // Creation des trajets composés

    Trajet* trajets1[] = {
        new TrajetSimple('B', 'Y', "MT3"),
        new TrajetSimple('Y', 'C', "MT2")
    };
    
    Trajet* trajets2[] = {
        new TrajetSimple('A', 'Z', "MT2"),
        new TrajetSimple('Z', 'C', "MT1")
    };

    TrajetCompose TC1(trajets1, 2);
    TrajetCompose TC2(trajets2, 2);


    // Construction du catalogue
    // L’ajout de trajets simples ou composés au catalogue courant
    Catalogue catalogue;

    // ajout des trajets simples
    catalogue.AjouterTrajet(&TS1);
    catalogue.AjouterTrajet(&TS2);

    // ajout des trajets composés
    catalogue.AjouterTrajet(&TC1);
    catalogue.AjouterTrajet(&TC2);

    // catalogue.Afficher();

    char departVoyageSouhaite = 'A';
    char arriveeVoyageSouhaite = 'C';
    // catalogue.RechercheSimple(departVoyageSouhaite, arriveeVoyageSouhaite);
    catalogue.RechercheAvancee(departVoyageSouhaite, arriveeVoyageSouhaite);
    cout << endl;
    */




    //system("clear");
    // ASCII art for "Bienvenue!"
    cout << ".______    __   _______ .__   __. ____    ____  _______ .__   __.  __    __   _______  __ \n";
    cout << "|   _  \\  |  | |   ____||  \\ |  | \\   \\  /   / |   ____||  \\ |  | |  |  |  | |   ____||  |\n";
    cout << "|  |_)  | |  | |  |__   |   \\|  |  \\   \\/   /  |  |__   |   \\|  | |  |  |  | |  |__   |  |\n";
    cout << "|   _  <  |  | |   __|  |  . `  |   \\      /   |   __|  |  . `  | |  |  |  | |   __|  |  |\n";
    cout << "|  |_)  | |  | |  |____ |  |\\   |    \\    /    |  |____ |  |\\   | |  `--'  | |  |____ |__|\n";
    cout << "|______/  |__| |_______||__| \\__|     \\__/     |_______||__| \\__|  \\______/  |_______|(__)\n";
    cout << "\n\n";

    Catalogue catalogue;
    char departVoyageSouhaite, arriveeVoyageSouhaite;                                                      
    
    while(true) {
        cout << "Veuillez bien choisir une option du menu suivant:" << endl;
        const char* options[] = {
            "Ajouter un trajet au catalogue courant", 
            "Afficher le catalogue courant",
            "Recherche le parcours",
            "Quitter le Program"
        };
        unsigned int nb_options = 4;
        for (unsigned int i = 0; i < nb_options; i++) {
            cout << i+1 << ". " << options[i] << endl;
        }
        int option;
        cout << "\n> ";
        cin >> option;
        system("clear");

        switch(option) {
            case 1: {
                cout << "Quel type de trajet veuillez vous definir?" << "\n1. Simple" << "\n2. Compose" << "\n> ";
                int optionTypeTrajet;
                cin >> optionTypeTrajet;
                switch(optionTypeTrajet) {
                    case 1: {
                        cout << "Veuillez definir le trajet simple" << endl;
                        char depart, arrivee, moyenTransport[10];
                        cout << "Depart (Ex. A): ";
                        cin >> depart;
                        cout << "Arrivee (Ex. B): ";
                        cin >> arrivee;
                        cout << "Moyen de transport (Ex. MT1): ";
                        cin >> moyenTransport;
                        catalogue.AjouterTrajet(new TrajetSimple(depart, arrivee, moyenTransport));
                        break;
                    }
                    case 2: {
                        cout << "Veuillez definir le trajet compose" << endl;
                        unsigned int nombreTrajets;
                        char depart, arrivee, moyenTransport[10];
                        cout << "Nombre de trajets: ";
                        cin >> nombreTrajets;
                        Trajet** trajets = new Trajet*[nombreTrajets];
                        for (unsigned int i = 0; i < nombreTrajets; i++) {
                            cout << "Trajet no." << i+1 << endl;
                            cout << "Depart: ";
                            cin >> depart;
                            cout << "Arrivee: ";
                            cin >> arrivee;
                            cout << "Moyen de transport: ";
                            cin >> moyenTransport;
                            trajets[i] = new TrajetSimple(depart, arrivee, moyenTransport);
                        }
                        catalogue.AjouterTrajet(new TrajetCompose(trajets, nombreTrajets));
                        
                        for (unsigned int i = 0; i < nombreTrajets; i++) {
                            delete trajets[i];
                        }
                        delete[] trajets;
                        break;
                    }
                    default: {
                        cout << "Veuillez choisir une option valide (1 ou 2)" << endl;
                        break;
                    }
                }
                break;
            }
            case 2: {
                cout << "\nCatalogue des trajets:" << endl;
                catalogue.Afficher();
                cout << endl << "Appuyez sur une touche pour continuer..." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
            }
            case 3: {
                cout << "Veuillez definir le trajet compose" << endl;
                cout << "Depart: ";
                cin >> departVoyageSouhaite;
                cout << "Arrivee: ";
                cin >> arriveeVoyageSouhaite;
                cout << endl;
                catalogue.RechercheAvancee(departVoyageSouhaite, arriveeVoyageSouhaite);
                cout << endl;
                cout << endl << "Appuyez sur une touche pour continuer..." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
            }
            case 4: {
                cout << "\nMerci d'avoir utilise ce programme, à bientôt!\n" << endl;
                return 0;
            }
            default: {
                break;
            }
        }
        system("clear");
    }



};