//
// Created by theob on 15/01/2019.
//

#ifndef CLIENT_PPIL_SAUVEGARDE_H
#define CLIENT_PPIL_SAUVEGARDE_H

class Forme;

class Sauvegarde {
 public:
  virtual void sauvegarder(const Forme &forme) = 0;
};

#endif //CLIENT_PPIL_SAUVEGARDE_H
