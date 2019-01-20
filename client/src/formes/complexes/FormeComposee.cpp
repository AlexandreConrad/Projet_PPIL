//
// Created by theobarrague on 11/01/19.
//

#include <sstream>
#include "FormeComposee.h"

FormeComposee::FormeComposee() {

}

FormeComposee::FormeComposee(const FormeComposee &formeComposee) {
  for (std::vector<Forme *>::iterator it = _formes.begin(); it != _formes.end(); it++)
    _formes.push_back((*it)->cloner());
}

const Forme &FormeComposee::getForme(int i) const {
  return *_formes.at(i);
}

void FormeComposee::ajouterForme(const Forme &forme) {
  _formes.push_back(forme.cloner());
}

FormeComposee::~FormeComposee() {
  for (std::vector<Forme *>::iterator it = _formes.begin(); it != _formes.end(); it++)
    delete *it;
}

FormeComposee::operator std::string() const {
  std::ostringstream ss;
  ss << "FormeComposee [";
  std::vector<Forme *>::const_iterator it = _formes.begin();
  while (it != _formes.end()) {
    ss << **it;
    it++;
    if (it != _formes.end())
      ss << ", ";
  }
  ss << "]";
  return ss.str();
}

Forme *FormeComposee::transformer(const Transformation &transformation) const {
  FormeComposee *formeComposee = new FormeComposee();
  for (std::vector<Forme *>::const_iterator it = _formes.begin(); it != _formes.end(); it++)
    formeComposee->ajouterForme(*(*it)->transformer(transformation));
  return formeComposee;
}

Forme *FormeComposee::cloner() const {
  return new FormeComposee(*this);
}
double FormeComposee::calculerAire() const {
  double aire(0);
  for (Forme *f : _formes)
    aire += f->calculerAire();
  return aire;
}


