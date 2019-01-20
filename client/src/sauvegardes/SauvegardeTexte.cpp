//
// Created by theob on 15/01/2019.
//

#include <iostream>
#include "SauvegardeTexte.h"
#include <fstream>
#include <Forme.h>

SauvegardeTexte::SauvegardeTexte(const char *chemin) {
  _chemin = chemin;
}

void SauvegardeTexte::sauvegarder(const Forme &forme) {
  std::ofstream fichier;

  fichier.open(_chemin, std::ios_base::app);
  fichier << std::string(forme) << std::endl;
}
