#include <iostream>
#include <cstring>
#include <limits>

#include "classes/Trajet.h"
#include "classes/TrajetSimple.h"
#include "classes/TrajetCompose.h"
#include "classes/Catalogue.h"

using namespace std;

#define MAX_INPUT_CHARACTERS 20 

int main() {
    /* 

    Des Executions bases pour tester et developper (ignorer)


    // Example de creation des trajets simples
    TrajetSimple TS1('A', 'B', "MT1");
    TrajetSimple TS2('B', 'C', "MT1");

    // TS1.Afficher();
    // TS2.Afficher();

    // Example de creation des trajets composés

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


    // Example de construction du catalogue
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

    // system("clear");
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
    
    // Interface utilisateur
    while(true) {
        cout << "Veuillez bien choisir une option du menu suivant:" << endl;
        const char* options[] = {
            "Ajouter un trajet au catalogue courant", 
            "Afficher le catalogue courant",
            "Recherche le parcours",
            "Charger un catalogue de trajets (lecture d'un fichier)",
            "Sauvegarder un catalogue courant (écriture dans un fichier)",
            "Quitter le Program"
        };
        unsigned int nb_options = 6;
        for (unsigned int i = 0; i < nb_options; i++) {
            cout << i+1 << ". " << options[i] << endl;
        }
        int option;
        cout << "\n> ";
        cin >> option;
        // system("clear");

        switch(option) {
            case 1: {
                cout << "Quel type de trajet veuillez vous definir?" << "\n1. Simple" << "\n2. Compose" << "\n> ";
                int optionTypeTrajet;
                cin >> optionTypeTrajet;
                switch(optionTypeTrajet) {
                    case 1: {
                        cout << "Veuillez definir le trajet simple" << endl;
                        cout << "Attention! Les stations sont définies comme des caractères" << endl;
                        char depart, arrivee, moyenTransport[MAX_INPUT_CHARACTERS];
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
                        unsigned int nombreTrajets;
                        cout << "Combien de trajets simples voulez-vous ajouter au trajet compose?" << endl;
                        cin >> nombreTrajets;

                        Trajet** trajets = new Trajet*[nombreTrajets];
                        char depart, arrivee, moyenTransport[MAX_INPUT_CHARACTERS];

                        for (unsigned int i = 0; i < nombreTrajets; i++) {
                            if (i == 0) {
                                cout << "Depart (Ex. A): ";
                                cin >> depart;
                            }
                            cout << "Arrivee (Ex. B): ";
                            cin >> arrivee;
                            cout << "Moyen de transport (Ex. MT1): ";
                            cin >> moyenTransport;
                        
                            trajets[i] = new TrajetSimple(depart, arrivee, moyenTransport);
                            depart = arrivee;
                        }

                        TrajetCompose* TC = new TrajetCompose(trajets, nombreTrajets);
                        catalogue.AjouterTrajet(TC);

                        // On libere pas la memorie car le catalogue s'en occupe à la fin du programme
                        // for (unsigned int i = 0; i < nombreTrajets; i++) {
                        //     delete trajets[i];
                        // }
                        // delete[] trajets;
                        
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

                int optionTypeRecherche;
                cout << "Quel type de recherche voulez-vous effectuer?" << "\n1. Simple" << "\n2. Avancee" << "\n> ";
                cin >> optionTypeRecherche;
                switch(optionTypeRecherche) {
                    case 1: {
                        cout << "Attention! Les stations sont définies comme des caractères" << endl;
                        cout << "Depart: ";
                        cin >> departVoyageSouhaite;
                        cout << "Arrivee: ";
                        cin >> arriveeVoyageSouhaite;
                        cout << endl;
                        catalogue.RechercheSimple(departVoyageSouhaite, arriveeVoyageSouhaite);
                        cout << endl;
                        cout << endl << "Appuyez sur une touche pour continuer..." << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    }
                    case 2: {
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
                    default: {
                        cout << "Veuillez choisir une option valide (1 ou 2)" << endl;
                        break;
                    }
                }
                break;
            }
            case 4: {
                cout << "Veuillez choisir un fichier à charger: ";
                char nomFichier[MAX_INPUT_CHARACTERS];
                cin >> nomFichier;
                
                cout 
                << "1. Sans critère de sélection" << endl
                << "2. Selon le type des trajets" << endl
                << "3. Selon la ville de départ et / ou la ville d'arrivée" << endl
                << "4. Selon une sélection de trajets" << endl;

                cout << "Veuillez choisir un le mode de chargement: ";
                int optionTypeChargement;
                cin >> optionTypeChargement;

                catalogue.Charger(nomFichier, optionTypeChargement);
                break;
            }
            case 5:{
                cout << "Veuillez choisir un nombre du fichier à sauvegarder: ";
                char nomFichier[MAX_INPUT_CHARACTERS];
                cin >> nomFichier;
                cout 
                << "1. Sans critère de sélection" << endl
                << "2. Selon le type des trajets" << endl
                << "3. Selon la ville de départ et / ou la ville d'arrivée" << endl
                << "4. Selon une sélection de trajets" << endl;

                cout << "Veuillez choisir un le mode de chargement: ";
                int optionTypeChargement;
                cin >> optionTypeChargement;
                catalogue.Sauvegarder(nomFichier, optionTypeChargement);
                break;
            }
            case 6: {
                cout << "\nMerci d'avoir utilise ce programme, à bientôt!\n" << endl;
                return 0;
            }
            default: {
                break;
            }
        }
        // system("clear");
    }
};