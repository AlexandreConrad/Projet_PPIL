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