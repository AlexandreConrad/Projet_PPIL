//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_COULEURS_H
#define CLIENT_PPIL_COULEURS_H

#include <string>

/**
 * Représente une couleur caractérisée par une quantité de rouge, vert et bleu
 * Les valeurs sont comprises entre 0-255
 */
class Couleur {
 public:
  /**
   * Constructeur par défaut.
   * Lance une exception si les paramètres ne sont pas dans la borne 0-255
   * @param rouge La quantité de rouge
   * @param vert La quantité de vert
   * @param bleu La quantité de bleu
   */
  Couleur(int rouge = 0, int vert = 0, int bleu = 0);

  /**
   * @return La quantité de rouge
   */
  int getRouge() const;

  /**
   * @return La quantité de vert
   */
  int getVert() const;

  /**
   * @return La quantité de bleu
   */
  int getBleu() const;

  /**
   * @param rouge La quantité de rouge comprise entre 0-255
   */
  void setRouge(int rouge);

  /**
   * @param vert La quantité de vert comprise entre 0-255
   */
  void setVert(int vert);

  /**
   * @param bleu La quantité de bleu comprise entre 0-255
   */
  void setBleu(int bleu);

  /**
   * Surcharge de l'opérateur << pour la sortie sur un flux
   * @param os Le flux de sortie
   * @param couleur La couleur à afficher
   * @return Le flux de sortie modifié
   */
  friend std::ostream &operator<<(std::ostream &os, const Couleur &couleur);

  /**
   * Surchage de l'opérateur string() pour l'affichage
   * @return Le texte décrivant la couleur
   */
  virtual operator std::string() const;

  /**
   * @return Une instance de couleur noir
   */
  static Couleur getCouleurNoir();

  /**
   * @return Une instance de couleur rouge
   */
  static Couleur getCouleurRouge();

  /**
   * @return Une instance de couleur vert
   */
  static Couleur getCouleurVert();

  /**
   * @return Une instance de couleur bleu
   */
  static Couleur getCouleurBleu();

  /**
   * @return Une instance de couleur bleu
   */
  static Couleur getCouleurJaune();

  /**
   * @return Une instance de couleur cyan
   */
  static Couleur getCouleurCyan();

 private:
  /**
   * Représente la quantité de rouge comprise entre 0-255
   */
  int _rouge;

  /**
   * Représente la quantité de vert comprise entre 0-255
   */
  int _vert;

  /**
   * Représente la quantité de bleu comprise entre 0-255
   */
  int _bleu;
};

#endif //CLIENT_PPIL_COULEURS_H