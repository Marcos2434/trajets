// CATALOGUE_CPP

/*************************************************************************
                           Catalogue.cpp -  Fichier d'implémentation
                                -------------------
        Ce fichier contient la déclaration de la classe Catalogue, qui 
        représente une collection d'objets Trajet. La classe Catalogue 
        fournit des méthodes pour ajouter et afficher des objets Trajet, 
        ainsi que pour effectuer des recherches simples et avancées.

                             -------------------
    début                : 20/11/2023
    copyright            : (C) 2023 par Marcos Bauch Mira
    e-mail               : marcosbauch2434@gmail.com
*************************************************************************/
//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AjouterTrajet(Trajet* trajet) {
    // on vérifie si le tableau est plein
    // si oui, on double la capacité
    if (nombreTrajets >= capacite) {
        capacite == 0 ? ++capacite : capacite *= 2;

        // reallocation de la mémoire
        Trajet** nouveauTableau = new Trajet*[capacite];
        for (unsigned int i = 0; i < nombreTrajets; i++) {
            nouveauTableau[i] = trajets[i]; // on copie les pointeurs du tableau originale au nouveau
        }
        // on libère la mémoire allouée pour le tableau originale s'il y en a
        if (capacite > 1) {
            delete[] trajets;
        }
        trajets = nouveauTableau;
    }
    // on ajoute le trajet au tableau
    trajets[nombreTrajets++] = trajet;
}

void Catalogue::ajouterTrajetBuffer(Trajet* trajet) {
    // on vérifie si le tableau est plein
    // si oui, on double la capacité
    if (nombreTrajetsBuffer >= capaciteBuffer) {
        capaciteBuffer == 0 ? ++capaciteBuffer : capaciteBuffer *= 2;

        // reallocation de la mémoire
        Trajet** nouveauTableau = new Trajet*[capaciteBuffer];
        for (unsigned int i = 0; i < nombreTrajetsBuffer; i++) {
            nouveauTableau[i] = buffer[i]; // on copie les pointeurs du tableau originale au nouveau
        }
        // on libère la mémoire allouée pour le tableau originale s'il y en a
        if (capaciteBuffer > 1) {
            delete[] buffer;
        }
        buffer = nouveauTableau;
    }
    // on ajoute le trajet au tableau
    buffer[nombreTrajetsBuffer++] = trajet;
}

void Catalogue::Afficher() const {
    // on affiche tous les trajets
    for (unsigned int i = 0; i < nombreTrajets; i++) {
        cout << "Trajet no." << i+1 << ": ";
        trajets[i]->Afficher();
        cout << endl;
    }
}

void Catalogue::RechercheSimple(char departVoyageSouhaite, char arriveeVoyageSouhaite) const {
    // on affiche tous les trajets qui correspondent au voyage souhaité de manière simple
    for (unsigned int i = 0; i < nombreTrajets; i++)
        if (departVoyageSouhaite == trajets[i]->GetDepart() && arriveeVoyageSouhaite == trajets[i]->GetArrivee()) {
            trajets[i]->Afficher();
            cout << endl;
        }
}

void Catalogue::RechercheAvancee(char departVoyageSouhaite, char arriveeVoyageSouhaite) {
    // on affiche tous les trajets qui correspondent au voyage souhaité
    for (unsigned int i = 0; i < nombreTrajets; i++) {
        if (trajets[i]->GetDepart() == departVoyageSouhaite && trajets[i]->GetArrivee() == arriveeVoyageSouhaite) {
            if (nombreTrajetsBuffer > 0) {
                for (unsigned int j = 0; j < nombreTrajetsBuffer; j++) {
                    buffer[j]->Afficher();
                }
                cout << ' ';
            }
            trajets[i]->Afficher();
            cout << endl;
            continue;
        }

        if (trajets[i]->GetDepart() == departVoyageSouhaite) {
            ajouterTrajetBuffer(trajets[i]);
            RechercheAvancee(trajets[i]->GetArrivee(), arriveeVoyageSouhaite);
            nombreTrajetsBuffer = 0;
        }
    }
}

void Catalogue::Sauvegarder(const string nomFichicer, const int mode) const {
    // on ouvre le fichier
    ofstream fichier(nomFichicer);
    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier " << nomFichicer << endl;
        return;
    }

    string typeTrajetAutorise;
    char departAutorise, arriveeAutorise;
    unsigned int n, m;

    if (mode == 2) {
        while (typeTrajetAutorise != "TS" && typeTrajetAutorise != "TC") {
            cout << "Veuillez entrer le type de trajet autorisé (TS ou TC): ";
            cin >> typeTrajetAutorise;
        }
    } else if (mode == 3) {
        cout << "Veuillez entrer la ville de départ autorisée: ";
        cin >> departAutorise;
        cout << "Veuillez entrer la ville d'arrivée autorisée: ";
        cin >> arriveeAutorise;
    } else if (mode == 4) {
        cout << "Veuillez entrer l'intervalle inférieur (n): ";
        cin >> n;
        cout << "Veuillez entrer l'intervalle supérieur (m): ";
        cin >> m;
    }

    // on écrit les trajets dans le fichier s'ils correspondent au mode de sauvegarde
    for (size_t i = 0; i < nombreTrajets; i++) {
        TrajetSimple *trajetSimple = dynamic_cast<TrajetSimple*>(trajets[i]);
        TrajetCompose *trajetCompose = dynamic_cast<TrajetCompose*>(trajets[i]);

        if (trajetSimple != nullptr && ( mode == 1 || mode == 4 ||
            (mode == 2 && typeTrajetAutorise == "TS" )
            || (mode == 3 && (trajetSimple->GetDepart() == departAutorise && trajetSimple->GetArrivee() == arriveeAutorise))
            )) 
            {
            
            if (mode == 4 && (i < n-1 || i > m-1)) continue;
            
            // on écrit le trajet simple dans le fichier
            fichier << "TS, " 
            << trajetSimple->GetDepart() 
            << ", " << trajetSimple->GetArrivee() 
            << ", " << trajetSimple->GetMoyenTransport() << endl;
        
        } else if (
            trajetCompose != nullptr 
            && (mode == 1 || mode == 4 || ((mode == 2 && typeTrajetAutorise == "TC")
            || (mode == 3 && (trajetCompose->GetDepart() == departAutorise && trajetCompose->GetArrivee() == arriveeAutorise)
            )))) {

            if (mode == 4 && (i < n-1 || i > m-1)) continue;
            
            fichier << "TC, ";
            for (unsigned int i = 0; i < trajetCompose->GetNombreTrajets(); i++) {
                
                fichier 
                << trajetCompose->GetTrajets()[i]->GetDepart() 
                << ", " << trajetCompose->GetTrajets()[i]->GetArrivee() 
                << ", " << trajetCompose->GetTrajets()[i]->GetMoyenTransport();

                if (i < trajetCompose->GetNombreTrajets() - 1) {
                    fichier << ", ";
                }
            }
            fichier << endl;
        }
    }

    // fermeture du fichier
    fichier.close();
}

void Catalogue::Charger(const string nomFichier, const int mode) {
    // on ouvre le fichier
    ifstream fichier(nomFichier);
    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier " << nomFichier << endl;
        return;
    }


    string typeTrajetAutorise;
    char departAutorise, arriveeAutorise;
    unsigned int n, m;

    if (mode == 2) {
        while (typeTrajetAutorise != "TS" && typeTrajetAutorise != "TC") {
            cout << "Veuillez entrer le type de trajet autorisé (TS ou TC): ";
            cin >> typeTrajetAutorise;
        }
    } else if (mode == 3) {
        cout << "Veuillez entrer la ville de départ autorisée: ";
        cin >> departAutorise;
        cout << "Veuillez entrer la ville d'arrivée autorisée: ";
        cin >> arriveeAutorise;
    } else if (mode == 4) {
        cout << "Veuillez entrer l'intervalle inférieur (n): ";
        cin >> n;
        cout << "Veuillez entrer l'intervalle supérieur (m): ";
        cin >> m;
    }

    // on lit le fichier ligne par ligne
    string ligne;
    unsigned int i = 0;
    while (getline(fichier, ligne)) {
        if (mode == 4 && (i < n-1 || i > m-1)) {
            i++;
            continue;
        };

        // on extrait les données de la ligne
        stringstream ss(ligne);

        vector<string> row;
        string field;
        while (getline(ss, field, ',')) {
            // ajouter le champ, sans les espaces, à la ligne 
            field.erase(remove_if(field.begin(), field.end(), ::isspace), field.end());
            row.push_back(field);
        }

        string typeTrajet;
        typeTrajet = row[0];

       


        // filtrer les trajets qui ne correspondent pas au mode de chargement
        if (mode == 2 && typeTrajet != typeTrajetAutorise) continue;
        

        // on crée le trajet
        if (typeTrajet == "TS") {
            
            char d = row[1][0];
            char a = row[2][0];

            if (mode == 3 && (d != departAutorise || a != arriveeAutorise)) continue;

            const char* mt = new char[row[3].length() + 1];
            mt = row[3].c_str();
            AjouterTrajet(new TrajetSimple(d, a, mt));
            i++;
        } else if (typeTrajet == "TC") {
            
            char d = row[1][0];
            char a = row[row.size() - 2][0];

            if (mode == 3 && (d != departAutorise || a != arriveeAutorise)) continue;

            unsigned int nombreTrajets = (row.size() - 1) / 3;
            Trajet** trajets = new Trajet*[nombreTrajets];
            unsigned int j;
            for (unsigned int i = 0; i < nombreTrajets; i++) {
                j = (i * 3) + 1;
                char d = row[j][0];
                char a = row[j+1][0];
                const char* mt = new char[row[j+2].length() + 1];
                strcpy(const_cast<char*>(mt), row[j+2].c_str());
                trajets[i] = new TrajetSimple(d, a, mt);
            }
            
            AjouterTrajet(new TrajetCompose(trajets, nombreTrajets));
            i++;
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue() : trajets(nullptr), nombreTrajets(0), capacite(0) {
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
}

Catalogue::Catalogue(Trajet** trajets, unsigned int nombreTrajets, unsigned int capacite)
    : trajets(trajets), nombreTrajets(nombreTrajets), capacite(capacite) {
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
}

Catalogue::Catalogue(const Catalogue& other) : trajets(other.trajets), nombreTrajets(other.nombreTrajets), capacite(other.capacite) {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Catalogue>" << endl;
    #endif
};

Catalogue::~Catalogue() {
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    // on libère la mémoire allouée pour les trajets
    if (capacite > 0) {
        for (unsigned int i = 0; i < nombreTrajets; i++) {
            delete trajets[i];
        }
        delete[] trajets;
    }
    // on libère la mémoire allouée pour le buffer
    if (capaciteBuffer > 0) {
        for (unsigned int i = 0; i < nombreTrajetsBuffer; i++) {
            delete buffer[i];
        }
        delete[] buffer;
    }
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

