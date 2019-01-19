//
// Created by theobarrague on 12/01/19.
//

#ifndef CLIENT_PPIL_FORMESIMPLE_H
#define CLIENT_PPIL_FORMESIMPLE_H

#include <src/couleurs/Couleur.h>
#include <src/vecteurs/Vecteur2D.h>
#include <vector>
#include <src/formes/Forme.h>

/**
 * Représente une forme composée de points et d'une couleur
 */
class FormeSimple : public Forme {
 public:
  /**
   * Constructeur par défaut
   * @param couleur La couleur à utiliser
   */
  FormeSimple(const Couleur &couleur = Couleur());

  /**
   * @param pos La position dans la liste
   * @return Le point à la position pos dans la liste des points
   */
  const Vecteur2D &getPoint(int pos) const;

  /**
   * @return Le nombre de points dans la forme
   */
  int getNbPoints() const;

  /**
   * @return La couleur de la forme
   */
  const Couleur &getCouleur() const;

  /**
   * Destructeur
   */
  virtual ~FormeSimple();

  /**
   * @see Forme::operator std::string()
   */
  virtual operator std::string() const;

  /**
   * @see Forme::transformer
   */
  virtual Forme *transformer(const Transformation &transformation) const = 0;

  /**
   * @see Forme::cloner
   */
  virtual Forme *cloner() const = 0;

  /**
   * @see Forme::calculerAire
   */
  virtual double calculerAire() const;

 protected:
  /**
   * Représente la couleur de la forme
   */
  Couleur _couleur;

  /**
   * Représente la liste des points composant la forme
   */
  std::vector<Vecteur2D> _points;
};

#endif //CLIENT_PPIL_FORMESIMPLE_H