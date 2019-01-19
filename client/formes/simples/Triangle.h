//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_TRIANGLE_H
#define CLIENT_PPIL_TRIANGLE_H

#include "Polygone.h"

class Triangle : public Polygone {
 public:
  /**
   * Constructeur par défaut
   * @param couleur La couleur à utiliser
   * @param point1 Le permier point
   * @param point2 Le deuxième point
   * @param point3 Le troisième point
   */
  Triangle(const Couleur &couleur = Couleur(),
           const Vecteur2D &point1 = Vecteur2D(),
           const Vecteur2D &point2 = Vecteur2D(),
           const Vecteur2D &point3 = Vecteur2D());

  /**
   * Destructeur
   */
  virtual ~Triangle();

  /**
   * @see Forme::transformer
   */
  virtual Forme *transformer(const Transformation &transformation) const;

  /**
   * @see Forme::cloner
   */
  virtual Forme *cloner() const;

 private:
  void ajouterSommet(const Vecteur2D &vecteur2D);
};

#endif  // CLIENT_PPIL_TRIANGLE_H