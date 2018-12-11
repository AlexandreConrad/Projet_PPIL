//
// Created by theobarrague on 11/12/18.
//

#ifndef CLIENT_ROND_H
#define CLIENT_ROND_H

#include "Forme.h"


class Rond : public Forme {
public:
    /* Constructeur */
    Rond(double xCentre = 0, double yCentre = 0, double rayon = 0);

    /* Destructeur */
    ~Rond();

    /* Getters */
    double getXCentre() const;
    double getYCentre() const;
    double getRayon() const;

    /* Méthodes métier */

    /* Autres méthodes utiles */
    operator std::string() const;

private:
    double _xCentre;
    double _yCentre;
    double _rayon;

    /* Setters */
    void setXCentre(double xCentre);
    void setYCentre(double yCentre);
    void setRayon(double rayon);
};


#endif //CLIENT_ROND_H
