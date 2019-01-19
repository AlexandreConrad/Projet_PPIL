//
// Created by theobarrague on 11/01/19.
//

#include "Triangle.h"
#include <transformations/Transformation.h>

Triangle::Triangle(const Couleur &couleur, const Vecteur2D &point1,
                   const Vecteur2D &point2, const Vecteur2D &point3)
    : Polygone(couleur) {
  ajouterSommet(point1);
  ajouterSommet(point2);
  ajouterSommet(point3);
}

Triangle::~Triangle() {

}

void Triangle::ajouterSommet(const Vecteur2D &vecteur2D) {
  Polygone::ajouterSommet(vecteur2D);
}

Forme *Triangle::transformer(const Transformation &transformation) const {
  return transformation.visiter(*this);
}

Forme *Triangle::cloner() const { return new Triangle(*this); }