//
// Created by theobarrague on 11/01/19.
//

#define _USE_MATH_DEFINES

#include <sstream>
#include <cmath>
#include <src/transformations/Transformation.h>
#include "Cercle.h"

Cercle::Cercle(const Couleur &couleur, const Vecteur2D &centre, float rayon)
    : FormeSimple(couleur) {
  setRayon(rayon);
  _points.push_back(centre);
}

float Cercle::getRayon() const {
  return _rayon;
}

void Cercle::setRayon(float rayon) {
  if (rayon <= 0)
    throw std::runtime_error("Le rayon du cercle doit être > 0");
  _rayon = rayon;
}

Cercle::~Cercle() {

}

Cercle::operator std::string() const {
  std::ostringstream ss;
  ss << "Cercle [(" << getCouleur().getRouge() << "," << _couleur.getVert() << "," << _couleur.getBleu() << "),("
     << getPoint(0).getX() << "," << getPoint(0).getY() << ")," << getRayon() << "]";
  return ss.str();
}

Forme *Cercle::transformer(const Transformation &transformation) const {
  return transformation.visiter(*this);
}

Forme *Cercle::cloner() const {
  return new Cercle(*this);
}

double Cercle::calculerAire() const {
  return M_PI * (_rayon * _rayon);
}
