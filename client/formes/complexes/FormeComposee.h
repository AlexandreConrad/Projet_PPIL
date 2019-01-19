//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_FORMECOMPOSEE_H
#define CLIENT_PPIL_FORMECOMPOSEE_H

#include <formes/Forme.h>
#include <vector>

/**
 * Représente une forme composée d'autres formes
 */
class FormeComposee : public Forme {
 public:
  /**
   * Constructeur par défaut
   */
  FormeComposee();

  /**
   * Constructeur par recopie
   * @param formeComposee La forme à recopier
   */
  FormeComposee(const FormeComposee &formeComposee);

  /**
   * @param pos La position dans la liste
   * @return La forme à la position pos dans la liste des formes
   */
  const Forme &getForme(int i) const;

  /**
   * @param forme La forme à ajouter
   */
  void ajouterForme(const Forme &forme);

  /**
   * Destructeur
   */
  virtual ~FormeComposee();

  /**
   * @see Forme::operator std::string
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
  std::vector<Forme *> _formes;
};

#endif //CLIENT_PPIL_FORMECOMPOSEE_H
