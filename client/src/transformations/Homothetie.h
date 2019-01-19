//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_HOMOTHETIE_H
#define CLIENT_PPIL_HOMOTHETIE_H

#include "Transformation.h"
#include <src/vecteurs/Vecteur2D.h>

class Segment;
class Cercle;
class Polygone;
class Triangle;

/**
 * Représente une homothetie géométrique ( un zoom )
 */
class Homothetie : public Transformation {
 public:
  /**
   * Constructeur par défaut
   * @param origine L'origine de l'homothetie
   * @param rapport Le rapport de l'homothetie
   */
  Homothetie(const Vecteur2D &origine, float rapport = 1);

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
   * Représente l'origine de l'homothetie
   */
  Vecteur2D _origine;

  /**
   * Représente le rapport de l'homothetie
   */
  float _rapport;
};

#endif //CLIENT_PPIL_HOMOTHETIE_H