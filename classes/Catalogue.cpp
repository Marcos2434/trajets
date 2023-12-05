// Catalogue.cpp

#include "Catalogue.h"
#include <iostream>

using namespace std;

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
