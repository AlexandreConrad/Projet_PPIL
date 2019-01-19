//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_POLYGONE_H
#define CLIENT_PPIL_POLYGONE_H

#include "FormeSimple.h"

/**
 * Représente un polygone
 */
class Polygone : public FormeSimple {
 public:
  /**
   * Constructeur par défaut
   * @param couleur La couleur à utiliser
   */
  Polygone(const Couleur &couleur = Couleur());

  /**
   * Ajoute un sommet à la liste des points
   * @param vecteur2D Le sommet à ajouter
   */
  void ajouterSommet(const Vecteur2D &vecteur2D);

  /**
   * Destructeur
   */
  virtual ~Polygone();

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

#endif //CLIENT_PPIL_POLYGONE_H