//
// Created by theobarrague on 11/12/18.
//

#include "Rond.h"
#include "../exceptions/FormeException.h"

Rond::Rond(double xCentre, double yCentre, double rayon) {
    setXCentre(xCentre);
    setYCentre(yCentre);
    setRayon(rayon);

    if ( rayon < 0 )
        throw FormeException("Impossible de créer un rond avec un rayon < 0");
}

Rond::~Rond() {

}

Rond::operator std::string() const {
    return "Rond [" + std::to_string(_xCentre) + ", " + std::to_string(_yCentre) + ", " + std::to_string(_rayon) + "]";
}

void Rond::setXCentre(double xCentre) {
    _xCentre = xCentre;
}

void Rond::setYCentre(double yCentre) {
    _yCentre = yCentre;
}

void Rond::setRayon(double rayon) {
    _rayon = rayon;
}

double Rond::getXCentre() const {
    return _xCentre;
}

double Rond::getYCentre() const {
    return _yCentre;
}

double Rond::getRayon() const {
    return _rayon;
}