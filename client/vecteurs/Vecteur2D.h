//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_VECTEUR2D_H
#define CLIENT_PPIL_VECTEUR2D_H

#include <string>

/**
 * Représente un point 2D
 */
class Vecteur2D {
 public:
  /**
   * Constructeur par défaut
   * @param x La position en ordonnée
   * @param y La position en abscisse
   */
  Vecteur2D(float x = 0, float y = 0);

  /**
   * Défini la position en ordonnée
   * @param x La position en ordonnée
   */
  void setX(float x);

  /**
   * Défini la position en abscisse
   * @param y La position en abscisse
   */
  void setY(float y);

  /**
   * @return La position en ordonnée
   */
  float getX() const;

  /**
   * @return La position en abscisse
   */
  float getY() const;

  /**
   * Effectue une homothetie du point
   * @param origine L'origine de l'homothetie
   * @param rapport Le rapport de l'homothetie
   * @return Un vecteur transformé
   */
  Vecteur2D homothetie(const Vecteur2D &origine, float rapport) const;

  /**
   * Effectue une rotation du point
   * @param origine L'origine de la rotation
   * @param angle L'angle en radians de la rotation
   * @return Un vecteur transformé
   */
  Vecteur2D rotation(const Vecteur2D &origine, float angle) const;

  /**
   * Surcharge de l'opérateur + pour l'addition de deux vecteurs
   * @param vecteur2D Le vecteur à ajouter
   * @return Le vecteur caclulé
   */
  Vecteur2D operator+(const Vecteur2D &vecteur2D) const;

  /**
   * Surcharge de l'opérateur - pour la soustraction de deux vecteurs
   * @param vecteur2D Le vecteur à soustraire
   * @return Le vecteur caclulé
   */
  Vecteur2D operator-(const Vecteur2D &vecteur2D) const;

  /**
   * Surcharge de l'opérateur string()
   * @return Le texte décrivant le vecteur
   */
  virtual operator std::string() const;

  /**
   * Surcharge de l'opérateur << pour l'affichage dans un flux
   * @param os Le flux de sortie
   * @param vecteur2D Le vecteur à afficher
   * @return Le flux modifié
   */
  friend std::ostream &operator<<(std::ostream &os, const Vecteur2D &vecteur2D);

 private:
  /**
   * Représente l'ordonnée
   */
  float _x;

  /**
   * Représente l'abscisse
   */
  float _y;
};

#endif //CLIENT_PPIL_VECTEUR2D_H