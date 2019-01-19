//
// Created by theobarrague on 11/01/19.
//

#include "Homothetie.h"
#include <formes/simples/Cercle.h>
#include <formes/simples/Segment.h>
#include <formes/simples/Triangle.h>

Homothetie::Homothetie(const Vecteur2D &origine, float rapport)
    : _origine(origine), _rapport(rapport) {

}

Forme *Homothetie::visiter(const Segment &forme) const {
  return new Segment(forme.getCouleur(),
                     forme.getPoint(0).homothetie(_origine, _rapport),
                     forme.getPoint(1).homothetie(_origine, _rapport));
}

Forme *Homothetie::visiter(const Cercle &forme) const {
  return new Cercle(forme.getCouleur(), forme.getPoint(0).homothetie(_origine, _rapport), forme.getRayon() * _rapport);
}

Forme *Homothetie::visiter(const Polygone &forme) const {
  Polygone *p = new Polygone(forme.getCouleur());
  for (int i = 0; i < forme.getNbPoints(); i++) {
    p->ajouterSommet(forme.getPoint(i).homothetie(_origine, _rapport));
  }
  return p;
}

Forme *Homothetie::visiter(const Triangle &forme) const {
  return new Triangle(forme.getCouleur(),
                      forme.getPoint(0).homothetie(_origine, _rapport),
                      forme.getPoint(1).homothetie(_origine, _rapport),
                      forme.getPoint(2).homothetie(_origine, _rapport));
}
