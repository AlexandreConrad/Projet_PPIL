//
// Created by theobarrague on 11/12/18.
//

#ifndef CLIENT_CROIX_H
#define CLIENT_CROIX_H

#include "Forme.h"


class Croix : public Forme {
public:
    /* Constructeur */
    Croix(double gauche, double haut, double droit, double bas);

    /* Destructeur */
    ~Croix();

    /* Getters */
    double getGauche() const;
    double getHaut() const;
    double getDroit() const;
    double getBas() const;

    /* Méthodes métier */

    /* Autres méthodes utiles */
    operator std::string() const;

private:
    double _gauche;
    double _haut;
    double _droit;
    double _bas;

    void setGauche(double gauche);
    void setHaut(double haut);
    void setDroit(double droit);
    void setBas(double bas);
};


#endif //CLIENT_CROIX_H
