//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_TRANSFORMATION_H
#define CLIENT_PPIL_TRANSFORMATION_H

class Polygone;
class Forme;
class Segment;
class Cercle;
class Triangle;

/**
 * Représente une transformation générique
 */
class Transformation {
 public:
  /**
   * Une transformation sur un segment
   * @param forme Le segment à transformer
   * @return Un segment transformé
   */
  virtual Forme *visiter(const Segment &forme) const = 0;

  /**
   * Une transformation sur un cercle
   * @param forme Le cercle à transformer
   * @return Un cercle transformé
   */
  virtual Forme *visiter(const Cercle &forme) const = 0;

  /**
   * Une transformation sur un polygone
   * @param forme Le polygone à transformer
   * @return Un polygone transformé
   */
  virtual Forme *visiter(const Polygone &forme) const = 0;

  /**
   * Une transformation sur un triangle
   * @param forme Le triangle à transformer
   * @return Un triangle transformé
   */
  virtual Forme *visiter(const Triangle &forme) const = 0;
};

#endif //CLIENT_PPIL_TRANSFORMATION_H