//
// Created by theobarrague on 11/01/19.
//

#include "Segment.h"
#include <sstream>
#include <src/transformations/Transformation.h>

Segment::Segment(const Couleur &couleur, const Vecteur2D &point1, const Vecteur2D &point2)
    : FormeSimple(couleur) {
  _points.push_back(point1);
  _points.push_back(point2);
}

Segment::~Segment() {

}

Segment::operator std::string() const {
  std::ostringstream ss;
  ss << "Segment [(" << getCouleur().getRouge() << "," << _couleur.getVert() << "," << _couleur.getBleu() << "),("
     << getPoint(0).getX() << "," << getPoint(0).getY() << "),(" << getPoint(1).getX() << "," << getPoint(1).getY()
     << ")]";
  return ss.str();
}

Forme *Segment::transformer(const Transformation &transformation) const {
  return transformation.visiter(*this);
}

Forme *Segment::cloner() const {
  return new Segment(*this);
}