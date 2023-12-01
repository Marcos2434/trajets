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
    cout << "Appel au constructeur de <Catalogue> no.2" << endl;
#endif
}

Catalogue::~Catalogue() {
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

    delete[] trajets;
    delete[] buffer;
}

void Catalogue::AjouterTrajet(Trajet* trajet) {
    if (nombreTrajets >= capacite) {
        capacite == 0 ? ++capacite : capacite *= 2;

        // reallocation de la mémoire
        Trajet** nouveauTableau = new Trajet*[capacite];
        for (unsigned int i = 0; i < nombreTrajets; i++) {
            nouveauTableau[i] = trajets[i]; // on copie les pointeurs du tableau originale au nouveau
        }
        delete[] trajets;
        trajets = nouveauTableau;
    }
    trajets[nombreTrajets++] = trajet;
}

void Catalogue::AjouterTrajetBuffer(Trajet* trajet) {
    if (nombreTrajetsBuffer >= capaciteBuffer) {
        capaciteBuffer == 0 ? ++capaciteBuffer : capaciteBuffer *= 2;

        // reallocation de la mémoire
        Trajet** nouveauTableau = new Trajet*[capaciteBuffer];
        for (unsigned int i = 0; i < nombreTrajetsBuffer; i++) {
            nouveauTableau[i] = buffer[i]; // on copie les pointeurs du tableau originale au nouveau
        }
        delete[] buffer;
        buffer = nouveauTableau;
    }
    buffer[nombreTrajetsBuffer++] = trajet;
}

void Catalogue::Afficher() const {
    for (unsigned int i = 0; i < nombreTrajets; i++) {
        cout << "Trajet no." << i+1 << ": ";
        trajets[i]->Afficher();
        cout << endl;
    }
}

void Catalogue::RechercheSimple(char departVoyageSouhaite, char arriveeVoyageSouhaite) const {
    for (unsigned int i = 0; i < nombreTrajets; i++)
        if (departVoyageSouhaite == trajets[i]->getDepart() && arriveeVoyageSouhaite == trajets[i]->getArrivee()) {
            trajets[i]->Afficher();
            cout << endl;
        }
}

void Catalogue::RechercheAvancee(char departVoyageSouhaite, char arriveeVoyageSouhaite) {
    for (unsigned int i = 0; i < nombreTrajets; i++) {
        if (trajets[i]->getDepart() == departVoyageSouhaite && trajets[i]->getArrivee() == arriveeVoyageSouhaite) {
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

        if (trajets[i]->getDepart() == departVoyageSouhaite) {
            AjouterTrajetBuffer(trajets[i]);
            RechercheAvancee(trajets[i]->getArrivee(), arriveeVoyageSouhaite);
            nombreTrajetsBuffer = 0;
        }
    }
}
