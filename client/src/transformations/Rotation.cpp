//
// Created by theobarrague on 11/01/19.
//

#include "Rotation.h"

Rotation::Rotation(const Vecteur2D &origine, float angle)
    : _origine(origine), _angle(angle) {

}

Forme *Rotation::visiter(const Segment &forme) const {
  return new Segment(forme.getCouleur(),
                     forme.getPoint(0).rotation(_origine, _angle),
                     forme.getPoint(1).rotation(_origine, _angle));
}

Forme *Rotation::visiter(const Cercle &forme) const {
  return new Cercle(forme.getCouleur(), forme.getPoint(0).rotation(_origine, _angle), forme.getRayon());
}

Forme *Rotation::visiter(const Polygone &forme) const {
  Polygone *p = new Polygone(forme.getCouleur());
  for (int i = 0; i < forme.getNbPoints(); i++) {
    p->ajouterSommet(forme.getPoint(i).rotation(_origine, _angle));
  }
  return forme.cloner();
}

Forme *Rotation::visiter(const Triangle &forme) const {
  return new Triangle(forme.getCouleur(),
                      forme.getPoint(0).rotation(_origine, _angle),
                      forme.getPoint(1).rotation(_origine, _angle),
                      forme.getPoint(2).rotation(_origine, _angle));
}
