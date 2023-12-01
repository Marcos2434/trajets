// TrajetSimple.h

#if !defined(TRAJET_SIMPLE_H)
#define TRAJET_SIMPLE_H

#include "Trajet.h"

class TrajetSimple : public Trajet {
public:
    TrajetSimple(char depart, char arrivee, const char* moyenTransport);
    void Afficher() const override;
    char getDepart() const override;
    char getArrivee() const override;

private:
    char depart;
    char arrivee;
    const char* moyenTransport;
};

#ifdef MAP
    // rien à déclarer
#endif

#endif // TRAJET_SIMPLE_H
