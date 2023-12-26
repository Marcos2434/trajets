// TRAJET_H

/*************************************************************************
                           Trajet.h  -  Fichier d'en-tête
                                -------------------
        Ce fichier contient la déclaration de la classe Trajet, qui
        représente un trajet. La classe Trajet fournit des méthodes pour
        afficher le trajet, ainsi que pour obtenir le point de départ et
        le point d'arrivée du trajet.
        C'est une classe abstraite de base pour les trajets simples et composés

                             -------------------
    début                : 20/11/2023
    copyright            : (C) 2023 par Marcos Bauch Mira
    e-mail               : marcosbauch2434@gmail.com
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

//------------------------------------------------------------------------

class Trajet {

//----------------------------------------------------------------- PUBLIC

public:
    
//----------------------------------------------------- Méthodes publiques

        virtual void Afficher() const = 0;
        // Mode d'emploi : Affiche le trajet.
        // Contrat : Aucun.

        virtual char GetDepart() const = 0;
        // Mode d'emploi : Retourne le point de départ du trajet.
        // Contrat : Aucun.

        virtual char GetArrivee() const = 0;
        // Mode d'emploi : Retourne le point d'arrivée du trajet.
        // Contrat : Aucun.

        virtual char* GetMoyenTransport() const = 0;
        // Mode d'emploi : Retourne le moyen de transport du trajet.
        // Contrat : Aucun.

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

        virtual ~Trajet();
        // Mode d'emploi : Détruit l'objet Trajet.
        // Contrat : Aucun.
    

//------------------------------------------------------------------ PRIVE
private:


protected:
        Trajet(); // On protège car il ne faut pas instancier de trajet (o-24)
        // Mode d'emploi : Constructeur par défaut.
        // Contrat : Aucun.
//----------------------------------------------------- Méthodes protégées
        
//----------------------------------------------------- Attributs protégés



    #ifdef MAP
        // rien à déclarer
    #endif
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJET_H


