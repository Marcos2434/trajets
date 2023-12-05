// Catalogue.h

#if !defined(CATALOGUE_H)
#define CATALOGUE_H

#include "Trajet.h"

class Catalogue {
public:
    Catalogue();
    Catalogue(Trajet** trajets, unsigned int nombreTrajets, unsigned int capacite);
    ~Catalogue();

    Catalogue(const Catalogue& other);

    void AjouterTrajet(Trajet* trajet);
    void Afficher() const;
    void RechercheSimple(char departVoyageSouhaite, char arriveeVoyageSouhaite) const;
    void RechercheAvancee(char departVoyageSouhaite, char arriveeVoyageSouhaite);

private:
    Trajet** trajets;
    unsigned int nombreTrajets;
    unsigned int capacite;

    Trajet** buffer;
    unsigned int nombreTrajetsBuffer = 0;
    unsigned int capaciteBuffer = 0;

    void ajouterTrajetBuffer(Trajet* trajet);

#ifdef MAP
    // Add your MAP-related code here
#endif
};

#endif // CATALOGUE_H
