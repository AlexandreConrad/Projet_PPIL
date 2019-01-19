//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_FORME_H
#define CLIENT_PPIL_FORME_H

#include <string>

class Surface;
class Sauvegarde;
class Transformation;

class Transformation;

/**
 * Représente une forme géométrique 2D
 */
class Forme {
 public:
  /**
   * Dessine la forme sur la surface
   * @param surface La surface sur laquelle dessiner
   */
  void dessiner(Surface &surface);

  /**
   * Sauvegarde la forme dans un objet sauvegarde
   * @param sauvegarde L'objet sauvegarde à utiliser
   */
  void sauvegarder(Sauvegarde &sauvegarde);

  /**
   * Calcule l'aire de la forme
   * @return l'aire de la forme en unité
   */
  virtual double calculerAire() const = 0;

  /**
   * Surcharge de l'opérateur << pour la sortie sur un flux
   * @param os Le flux de sortie
   * @param forme La forme à afficher
   * @return Le flux de sortie modifié
   */
  friend std::ostream &operator<<(std::ostream &os, const Forme &forme);

  /**
   * Destructeur
   */
  virtual ~Forme();

  /**
   * Surcharge de l'opérateur string()
   * @return Le texte décrivant la forme
   */
  virtual operator std::string() const;

  /**
   * Effectue une transformation sur la forme
   * @param transformation La transformation à utiliser
   * @return La forme transformée
   */
  virtual Forme *transformer(const Transformation &transformation) const = 0;

  /**
   * @return Une copie de la forme
   */
  virtual Forme *cloner() const = 0;
};

#endif //CLIENT_PPIL_FORME_H
