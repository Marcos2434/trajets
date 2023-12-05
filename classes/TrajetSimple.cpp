// TrajetSimple.cpp

#include "TrajetSimple.h"
#include <iostream>

using namespace std;

TrajetSimple::TrajetSimple(char& depart, char& arrivee, const char* moyenTransport)
    : depart(depart), arrivee(arrivee), moyenTransport(moyenTransport) {
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

void TrajetSimple::Afficher() const {cout << "de " << depart << " à " << arrivee << " en " << moyenTransport;}

char TrajetSimple::GetDepart() const {return depart;}

char TrajetSimple::GetArrivee() const {return arrivee;}
