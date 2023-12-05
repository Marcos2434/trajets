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

char TrajetCompose::GetDepart() const {return trajets[0]->GetDepart();}

char TrajetCompose::GetArrivee() const {return trajets[nombreTrajets - 1]->GetArrivee();}
