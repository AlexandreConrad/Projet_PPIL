//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_TRANSLATION_H
#define CLIENT_PPIL_TRANSLATION_H

#include <src/vecteurs/Vecteur2D.h>
#include <src/formes/simples/Segment.h>
#include <src/formes/simples/Cercle.h>
#include <src/formes/simples/Triangle.h>
#include <src/formes/simples/Polygone.h>
#include "Transformation.h"

class Translation : public Transformation {
 public:
  Translation(const Vecteur2D &vecteur2D = Vecteur2D());

  virtual Forme *visiter(const Segment &forme) const;
  virtual Forme *visiter(const Cercle &forme) const;
  virtual Forme *visiter(const Polygone &forme) const;
  virtual Forme *visiter(const Triangle &forme) const;

 private:
  Vecteur2D _vecteur2D;
};

#endif //CLIENT_PPIL_TRANSLATION_H
