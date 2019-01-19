//
// Created by theob on 15/01/2019.
//

#ifndef CLIENT_PPIL_SAUVEGARDETEXTE_H
#define CLIENT_PPIL_SAUVEGARDETEXTE_H

#include <src/surfaces/Surface.h>
#include <string>
#include "Sauvegarde.h"

class SauvegardeTexte : public Sauvegarde {
 public:
  SauvegardeTexte(const char *chemin);
  void sauvegarder(const Forme &forme);

 private:
  const char *_chemin;
};

#endif //CLIENT_PPIL_SAUVEGARDETEXTE_H
