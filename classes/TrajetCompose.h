// TRAJET_COMPOSE_H

/*************************************************************************
                           TrajetCompose.h  -  Fichier d'en-tête
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

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if !defined(TRAJET_COMPOSE_H)
#define TRAJET_COMPOSE_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

//------------------------------------------------------------------------

class TrajetCompose : public Trajet {

//----------------------------------------------------------------- PUBLIC

public:
    
//----------------------------------------------------- Méthodes publiques
        void Afficher() const override;
        // Mode d'emploi : Affiche le trajet.
        // Contrat : Aucun.

        char GetDepart() const override;
        // Mode d'emploi : Retourne le point de départ du trajet.
        // Contrat : Aucun.

        char GetArrivee() const override;
        // Mode d'emploi : Retourne le point d'arrivée du trajet.
        // Contrat : Aucun.

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

        TrajetCompose(Trajet** trajets, unsigned int nombreTrajets);
        // Mode d'emploi : Détruit l'objet Trajet.
        // Contrat : Aucun.

        TrajetCompose(const TrajetCompose& other);
        // Mode d'emploi : Détruit l'objet Trajet.
        // Contrat : Aucun.

        virtual ~TrajetCompose();
        // Mode d'emploi : Détruit l'objet Trajet.
        // Contrat : Aucun.
    

//------------------------------------------------------------------ PRIVE
private:
    Trajet** trajets;
    unsigned int nombreTrajets;


protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    #ifdef MAP
        // rien à déclarer
    #endif
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJET_COMPOSE_H