//
// Created by theobarrague on 11/12/18.
//

#include "Croix.h"
#include "FormeException.h"
#include <exception>


Croix::Croix(double gauche, double haut, double droit, double bas) : _gauche(0), _haut(0), _droit(0), _bas(0) {
    setGauche(gauche);
    setHaut(haut);
    setDroit(droit);
    setBas(bas);

    if ( _gauche > _droit || _bas < _haut )
        throw FormeException("Impossible de créer une croix : côté gauche à droite du côté droit ou côté bas au dessus du côté haut");
}

Croix::~Croix() {

}

Croix::operator std::string() const {
    return "Croix [" + std::to_string(_gauche) + ", " + std::to_string(_haut) + ", " + std::to_string(_droit) + ", " +
           std::to_string(_bas) + "]";
}

void Croix::setGauche(double gauche) {
    _gauche = gauche;
}

void Croix::setHaut(double haut) {
    _haut = haut;
}

void Croix::setDroit(double droit) {
    _droit = droit;
}

void Croix::setBas(double bas) {
    _bas = bas;
}

double Croix::getGauche() const {
    return _gauche;
}

double Croix::getHaut() const {
    return _haut;
}

double Croix::getDroit() const {
    return _droit;
}

double Croix::getBas() const {
    return _bas;
}