//
// Created by theobarrague on 11/01/19.
//

#include <sstream>
#include <cmath>
#include "Vecteur2D.h"

Vecteur2D::operator std::string() const {
  std::ostringstream ss;
  ss << "Vecteur2D [x=" << _x << ", y=" << _y << "]";
  return ss.str();
}

Vecteur2D::Vecteur2D(float x, float y) {
  setX(x);
  setY(y);
}

std::ostream &operator<<(std::ostream &os, const Vecteur2D &vecteur2D) {
  return os << std::string(vecteur2D);
}

void Vecteur2D::setX(float x) {
  _x = x;
}

void Vecteur2D::setY(float y) {
  _y = y;
}

float Vecteur2D::getX() const {
  return _x;
}

float Vecteur2D::getY() const {
  return _y;
}

Vecteur2D Vecteur2D::operator+(const Vecteur2D &vecteur2D) const {
  return Vecteur2D(_x + vecteur2D.getX(), _y + vecteur2D.getY());
}

Vecteur2D Vecteur2D::operator-(const Vecteur2D &vecteur2D) const {
  return Vecteur2D(-_x, -_y);
}

Vecteur2D Vecteur2D::homothetie(const Vecteur2D &origine, float rapport) const {
  float x = origine.getX() + ((_x - origine.getX()) * rapport);
  float y = origine.getY() + ((_y - origine.getY()) * rapport);
  return Vecteur2D(x, y);
}

Vecteur2D Vecteur2D::rotation(const Vecteur2D &origine, float angle) const {
  Vecteur2D v1 = *this - origine;
  float x = (v1.getX() * ((float) cos(angle)) + v1.getY() * ((float) sin(angle)) + origine.getX());
  float y = (-v1.getX() * ((float) sin(angle)) + v1.getY() * ((float) cos(angle)) + origine.getY());
  return Vecteur2D(x, y);
}
