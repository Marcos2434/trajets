// TrajetCompose.cpp

#include "TrajetCompose.h"
#include <iostream>

using namespace std;

TrajetCompose::TrajetCompose(Trajet** trajets, unsigned int nombreTrajets)
    : trajets(trajets), nombreTrajets(nombreTrajets) {
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
}

void TrajetCompose::Afficher() const {
    for (unsigned int i = 0; i < nombreTrajets; i++) {
        trajets[i]->Afficher();
        if (i + 1 != nombreTrajets) cout << " - ";
    }
}

char TrajetCompose::getDepart() const {return trajets[0]->getDepart();}

char TrajetCompose::getArrivee() const {return trajets[nombreTrajets - 1]->getArrivee();}
