//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_SEGMENT_H
#define CLIENT_PPIL_SEGMENT_H

#include "FormeSimple.h"

/**
 * Représente un segment
 */
class Segment : public FormeSimple {
 public:
  /**
   * Constructeur par défaut
   * @param couleur La couleur à utiliser
   * @param point1 Le point de départ
   * @param point2 Le point d'arrivée
   */
  Segment(const Couleur &couleur = Couleur(),
          const Vecteur2D &point1 = Vecteur2D(),
          const Vecteur2D &point2 = Vecteur2D());

  /**
   * Destructeur
   */
  virtual ~Segment();

  /**
   * @see Forme::operator std::string()
   */
  virtual operator std::string() const;

  /**
   * @see Forme::transformer
   */
  virtual Forme *transformer(const Transformation &transformation) const;

  /**
   * @see Forme::cloner
   */
  virtual Forme *cloner() const;
};

#endif //CLIENT_PPIL_SEGMENT_H