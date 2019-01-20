//
// Created by theobarrague on 12/01/19.
//

#include <sstream>
#include "FormeSimple.h"

FormeSimple::FormeSimple(const Couleur &couleur)
    : _couleur(couleur) {

}

FormeSimple::~FormeSimple() {

}

const Vecteur2D &FormeSimple::getPoint(int i) const {
  return _points.at(i);
}

int FormeSimple::getNbPoints() const {
  return _points.size();
}

const Couleur &FormeSimple::getCouleur() const {
  return _couleur;
}

FormeSimple::operator std::string() const {
  std::ostringstream ss;
  ss << Forme::operator std::string() << " + FormeSimple [couleur=" << _couleur << ", points=[";
  std::vector<Vecteur2D>::const_iterator it = _points.begin();
  while (it != _points.end()) {
    ss << *it;
    it++;
    if (it != _points.end())
      ss << ", ";
  }
  ss << "]]";
  return ss.str();
}

double FormeSimple::calculerAire() const {
  if (_points.size() < 3)
    return 0;

  double aire(0);
  for (int i = 0; i < _points.size() - 1; i++) {
    aire += _points[i].getX() * _points[i + 1].getY() - _points[i + 1].getX() * _points[i].getY();
  }
  aire +=
      _points[_points.size() - 1].getX() * _points[0].getY() - _points[0].getX() * _points[_points.size() - 1].getY();

  return 1. / 2. * aire;
}