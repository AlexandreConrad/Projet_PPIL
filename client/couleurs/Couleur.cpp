//
// Created by theobarrague on 11/01/19.
//

#include "Couleur.h"
#include <sstream>

Couleur::Couleur(int rouge, int vert, int bleu) {
  setRouge(rouge);
  setVert(vert);
  setBleu(bleu);
}

Couleur::operator std::string() const {
  std::ostringstream ss;
  ss << "Couleur [rouge=" << _rouge << ", vert=" << _vert << ", bleu=" << _bleu << "]";
  return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Couleur &couleur) {
  return os << std::string(couleur);
}

int Couleur::getRouge() const {
  return _rouge;
}

int Couleur::getVert() const {
  return _vert;
}

int Couleur::getBleu() const {
  return _bleu;
}

void Couleur::setRouge(int rouge) {
  if (rouge < 0 || rouge > 255)
    throw std::runtime_error("La quantité de rouge doit être comprise entre 0-255");
  _rouge = rouge;
}

void Couleur::setVert(int vert) {
  if (vert < 0 || vert > 255)
    throw std::runtime_error("La quantité de vert doit être comprise entre 0-255");
  _vert = vert;
}

void Couleur::setBleu(int bleu) {
  if (bleu < 0 || bleu > 255)
    throw std::runtime_error("La quantité de bleu doit être comprise entre 0-255");
  _bleu = bleu;
}

Couleur Couleur::getCouleurNoir() {
  return Couleur(0, 0, 0);
}

Couleur Couleur::getCouleurRouge() {
  return Couleur(255, 0, 0);
}

Couleur Couleur::getCouleurVert() {
  return Couleur(0, 255, 0);
}

Couleur Couleur::getCouleurBleu() {
  return Couleur(0, 0, 255);
}

Couleur Couleur::getCouleurJaune() {
  return Couleur(255, 255, 0);
}

Couleur Couleur::getCouleurCyan() {
  return Couleur(0, 255, 255);
}