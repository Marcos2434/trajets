// TRAJET_COMPOSE_CPP

/*************************************************************************
                           TrajetCompose.cpp  -  Fichier d'implémentation
                                -------------------
                        TrajetCompose est une classe qui hérite de Trajet
        La classe TrajetCompose permet de représenter un trajet composé de plusieurs
        trajets simples. La classe TrajetCompose fournit des méthodes
        pour afficher le trajet, ainsi que pour obtenir le point de départ et
        le point d'arrivée du trajet.

                             -------------------
    début                : 20/11/2023
    copyright            : (C) 2023 par Marcos Bauch Mira
    e-mail               : marcosbauch2434@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher() const {
    for (unsigned int i = 0; i < nombreTrajets; i++) {
        trajets[i]->Afficher();
        if (i + 1 != nombreTrajets) cout << " - ";
    }
}

char TrajetCompose::GetDepart() const {return trajets[0]->GetDepart();}

char TrajetCompose::GetArrivee() const {return trajets[nombreTrajets - 1]->GetArrivee();}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(Trajet** trajets, unsigned int nombreTrajets)
    : trajets(trajets), nombreTrajets(nombreTrajets) {
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
}

TrajetCompose::TrajetCompose(const TrajetCompose& other)
    : trajets(other.trajets), nombreTrajets(other.nombreTrajets) {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
    #endif
}



TrajetCompose::~TrajetCompose() {
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
    for (unsigned int i = 0; i < nombreTrajets; i++) {
        delete trajets[i];
    }
    delete[] trajets;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

