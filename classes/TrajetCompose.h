// TrajetCompose.h

#if !defined(TRAJET_COMPOSE_H)
#define TRAJET_COMPOSE_H

#include "Trajet.h"

class TrajetCompose : public Trajet {
public:
    TrajetCompose(Trajet** trajets, unsigned int nombreTrajets);
    void Afficher() const override;
    char GetDepart() const override;
    char GetArrivee() const override;

private:
    Trajet** trajets;
    unsigned int nombreTrajets;
};

#ifdef MAP
    // rien à déclarer
#endif

#endif // TRAJET_COMPOSE_H
