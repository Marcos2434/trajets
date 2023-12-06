// TRAJET SIMPLE

/*************************************************************************
                           TrajetSimple.h  -  Fichier d'en-tête
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

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if !defined(TRAJET_SIMPLE_H)
#define TRAJET_SIMPLE_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

//------------------------------------------------------------------------

class TrajetSimple : public Trajet {

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

        TrajetSimple(char depart, char arrivee, const char* moyenTransport);
        // Mode d'emploi : Construit un trajet simple.
        // Contrat : Aucun.

        TrajetSimple(const TrajetSimple& other);
        // Mode d'emploi : Construit un trajet simple par copie.
        // Contrat : Aucun.

        ~TrajetSimple();
        // Mode d'emploi : Détruit l'objet TrajetSimple.
        // Contrat : Aucun.
    

//------------------------------------------------------------------ PRIVE
private:
    char depart;
    char arrivee;
    const char* moyenTransport;


protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés



    #ifdef MAP
        // rien à déclarer
    #endif
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJET_SIMPLE_H