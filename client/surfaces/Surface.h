//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_SURFACE_H
#define CLIENT_PPIL_SURFACE_H

class Forme;

/**
 * Représente une surface dessinable
 */
class Surface {
 public:
  /**
   * Dessine la forme
   * @param forme La forme à dessiner
   */
  virtual void dessiner(const Forme &forme) = 0;
};

#endif  // CLIENT_PPIL_SURFACE_H
