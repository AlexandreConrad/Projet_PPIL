//
// Created by theobarrague on 11/01/19.
//

#include "Forme.h"
#include <sstream>
#include <Surface.h>
#include <Sauvegarde.h>

Forme::~Forme() {

}

void Forme::dessiner(Surface &surface) {
  surface.dessiner(*this);
}

void Forme::sauvegarder(Sauvegarde &sauvegarde) {
  sauvegarde.sauvegarder(*this);
}

std::ostream &operator<<(std::ostream &os, const Forme &forme) {
  return os << std::string(forme);
}

Forme::operator std::string() const {
  std::ostringstream ss;
  ss << "Forme []";
  return ss.str();
}