//
// Created by theobarrague on 11/01/19.
//

#include "Polygone.h"
#include <sstream>
#include <transformations/Transformation.h>

Polygone::Polygone(const Couleur &couleur)
    : FormeSimple(couleur) {

}

Polygone::~Polygone() {

}

void Polygone::ajouterSommet(const Vecteur2D &vecteur2D) {
  _points.push_back(vecteur2D);
}

Polygone::operator std::string() const {
  std::ostringstream ss;
  ss << "Polygone [(" << getCouleur().getRouge() << "," << _couleur.getVert() << "," << _couleur.getBleu() << "),";
  for (int i = 0; i < getNbPoints(); i++) {
    ss << "(" << getPoint(i).getX() << "," << getPoint(i).getY() << ")";
    if (i + 1 < getNbPoints())
      ss << ",";
  }
  ss << "]";
  return ss.str();
}

Forme *Polygone::transformer(const Transformation &transformation) const {
  return transformation.visiter(*this);
}

Forme *Polygone::cloner() const {
  return new Polygone(*this);
}