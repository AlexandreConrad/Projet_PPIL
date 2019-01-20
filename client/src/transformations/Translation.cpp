//
// Created by theobarrague on 11/01/19.
//

#include "Translation.h"

Translation::Translation(const Vecteur2D &vecteur2D)
    : _vecteur2D(vecteur2D) {

}

Forme *Translation::visiter(const Segment &forme) const {
  return new Segment(forme.getCouleur(), forme.getPoint(0) + _vecteur2D, forme.getPoint(1) + _vecteur2D);
}

Forme *Translation::visiter(const Cercle &forme) const {
  return new Cercle(forme.getCouleur(), forme.getPoint(0) + _vecteur2D, forme.getRayon());
}

Forme *Translation::visiter(const Polygone &forme) const {
  Polygone *p = new Polygone(forme.getCouleur());
  for (int i = 0; i < forme.getNbPoints(); i++) {
    p->ajouterSommet(forme.getPoint(i) + _vecteur2D);
  }
  return p;
}

Forme *Translation::visiter(const Triangle &forme) const {
  return new Triangle(forme.getCouleur(),
                      forme.getPoint(0) + _vecteur2D,
                      forme.getPoint(1) + _vecteur2D,
                      forme.getPoint(2) + _vecteur2D);
}
