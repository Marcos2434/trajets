// CATALOGUE_H

/*************************************************************************
                           Catalogue.h  -  Fichier d'en-tête
                                -------------------
        Ce fichier contient la déclaration de la classe Catalogue, qui 
        représente une collection d'objets Trajet. La classe Catalogue 
        fournit des méthodes pour ajouter et afficher des objets Trajet, 
        ainsi que pour effectuer des recherches simples et avancées.

                             -------------------
    début                : 20/11/2023
    copyright            : (C) 2023 par Marcos Bauch Mira
    e-mail               : marcosbauch2434@gmail.com
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

//------------------------------------------------------------------------

class Catalogue {

//----------------------------------------------------------------- PUBLIC

public:
    
//----------------------------------------------------- Méthodes publiques

    void AjouterTrajet(Trajet* trajet);
    // Mode d'emploi : ajoute un trajet au catalogue
    // Contrat : le trajet doit être valide

    void Afficher() const;
    // Mode d'emploi : affiche tous les trajets du catalogue
    // Contrat : aucun

    void RechercheSimple(char departVoyageSouhaite, char arriveeVoyageSouhaite) const;
    // Mode d'emploi : affiche tous les trajets du catalogue qui ont le même
    // Contrat : aucun

    void RechercheAvancee(char departVoyageSouhaite, char arriveeVoyageSouhaite); // pas const car on doit changer le buffer
    // Mode d'emploi : affiche tous les trajets du catalogue qui ont le même
    // Contrat : aucun

    void Charger(const string nomFichier, const int mode);

    void Sauvegarder(const string nomFichier, const int mode) const;

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Mode d'emploi : constructeur par défaut
    // Contrat : aucun

    Catalogue(Trajet** trajets, unsigned int nombreTrajets, unsigned int capacite);
    // Mode d'emploi : constructeur par données
    // Contrat : aucun

    Catalogue(const Catalogue& other);
    // Mode d'emploi : constructeur par copie
    // Contrat : aucun

    ~Catalogue();
    // Mode d'emploi : destructeur
    // Contrat : aucun


//------------------------------------------------------------------ PRIVE
private:
    Trajet** trajets;
    unsigned int nombreTrajets;
    unsigned int capacite;

    Trajet** buffer;
    unsigned int nombreTrajetsBuffer = 0;
    unsigned int capaciteBuffer = 0;

    void ajouterTrajetBuffer(Trajet* trajet);

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés


    #ifdef MAP
        // rien à déclarer
    #endif

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // CATALOGUE_H

