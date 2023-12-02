// TrajetSimple.cpp

#include "TrajetSimple.h"
#include <iostream>

using namespace std;

TrajetSimple::TrajetSimple(char depart, char arrivee, const char* moyenTransport)
    : depart(depart), arrivee(arrivee), moyenTransport(moyenTransport) {
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
}

void TrajetSimple::Afficher() const {cout << "de " << depart << " à " << arrivee << " en " << moyenTransport;}

char TrajetSimple::getDepart() const {return depart;}

char TrajetSimple::getArrivee() const {return arrivee;}
