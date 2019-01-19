//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_ROTATION_H
#define CLIENT_PPIL_ROTATION_H

#include <vecteurs/Vecteur2D.h>
#include "Translation.h"

class Segment;
class Cercle;
class Polygone;
class Triangle;

/**
 * Représente une rotation géométrique
 */
class Rotation : public Translation {
 public:
  /**
   * Constructeur par défaut
   * @param origine L'origine de la rotation
   * @param angle L'angle en radian
   */
  Rotation(const Vecteur2D &origine = Vecteur2D(), float angle = 0);

  /**
   * @see Transformation::visiter
   */
  virtual Forme *visiter(const Segment &forme) const;

  /**
   * @see Transformation::visiter
   */
  virtual Forme *visiter(const Cercle &forme) const;

  /**
   * @see Transformation::visiter
   */
  virtual Forme *visiter(const Polygone &forme) const;

  /**
   * @see Transformation::visiter
   */
  virtual Forme *visiter(const Triangle &forme) const;

 private:
  /**
   * Représente l'origine de la rotation
   */
  Vecteur2D _origine;

  /**
   * Représente l'angle de la rotation en radians
   */
  float _angle;
};

#endif //CLIENT_PPIL_ROTATION_H