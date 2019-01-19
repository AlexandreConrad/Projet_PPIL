//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_CERCLE_H
#define CLIENT_PPIL_CERCLE_H

#include "FormeSimple.h"

/**
 * Représente un Cercle
 */
class Cercle : public FormeSimple {
 public:
  /**
   * Constructeur par défaut
   * @param couleur La couleur du cercle
   * @param centre Le centre du cercle
   * @param rayon Le rayon du cercle
   */
  Cercle(const Couleur &couleur = Couleur(), const Vecteur2D &centre = Vecteur2D(), float rayon = 0);

  /**
   * @return Le rayon du cercle
   */
  float getRayon() const;

  /**
   * Défini le rayon du cercle
   * Lance une exception si le rayon est <= 0
   * @param rayon Le nouveau rayon du cercle
   */
  void setRayon(float rayon);

  /**
   * Destructeur
   */
  virtual ~Cercle();

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

 private:
  /**
   * Représente le rayon du cercle
   */
  float _rayon;
};

#endif //CLIENT_PPIL_CERCLE_H