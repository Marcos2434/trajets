// Trajet.h

#if !defined(TRAJET_H)
#define TRAJET_H

class Trajet {
public:
    virtual void Afficher() const = 0;
    virtual char getDepart() const = 0;
    virtual char getArrivee() const = 0;
    virtual ~Trajet() {} // virtual destructor for a base class

protected:
};

#endif // TRAJET_H