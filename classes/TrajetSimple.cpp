// TRAJET_SIMPLE_CPP

/*************************************************************************
                           TrajetSimple.cpp  -  Fichier d'implémentation
                                -------------------
            TrajetSimple est une classe qui hérite de Trajet. Elle représente
            un trajet simple, c'est-à-dire un trajet direct entre deux villes.
            La classe TrajetSimple fournit des méthodes pour afficher le trajet,
            ainsi que pour obtenir le point de départ et le point d'arrivée du trajet.
                             -------------------
    début                : 20/11/2023
    copyright            : (C) 2023 par Marcos Bauch Mira
    e-mail               : marcosbauch2434@gmail.com
*************************************************************************/
//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const {cout << "de " << depart << " à " << arrivee << " en " << moyenTransport;}

char TrajetSimple::GetDepart() const {return depart;}

char TrajetSimple::GetArrivee() const {return arrivee;}

char* TrajetSimple::GetMoyenTransport() const {return moyenTransport;}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(char depart, char arrivee, const char* moyenTransport)
    : depart(depart), arrivee(arrivee) {

    this->moyenTransport = new char[strlen(moyenTransport) + 1];
    strcpy(this->moyenTransport, moyenTransport);

    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
}

TrajetSimple::TrajetSimple(const TrajetSimple& other)
    : depart(other.depart), arrivee(other.arrivee), moyenTransport(other.moyenTransport) {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif
}

TrajetSimple::~TrajetSimple() {
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

