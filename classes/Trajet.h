// Trajet.h

#if !defined(TRAJET_H)
#define TRAJET_H

class Trajet {
    // Classe abstraite de base pour les trajets simples et composés
    
    public:
        virtual void Afficher() const = 0;
        virtual char GetDepart() const = 0;
        virtual char GetArrivee() const = 0;
        virtual ~Trajet() {};

    protected:
};

#endif // TRAJET_H
