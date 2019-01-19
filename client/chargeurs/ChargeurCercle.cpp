//
// Created by theob on 15/01/2019.
//

#include "ChargeurCercle.h"
#include <Cercle.h>
#include <iostream>
#include <regex>

bool ChargeurCercle::peutTraiter(std::string information) {
  return information.rfind("Cercle", 0) == 0;
}

Forme *ChargeurCercle::traitementSpecialise(std::string information) {
  // Cercle [(0,0,0),(0,0),10]
  std::regex regex(
      "\\[\\(([0-9]+),([0-9]+),([0-9]+)\\),\\(([0-9\\.\\-]+),([0-9\\.\\-]+)\\),"
      "([0-9\\.\\-]+)\\]");
  std::smatch matchs;
  std::regex_search(information, matchs, regex);

  int r = std::stoi(matchs[1].str(), nullptr);
  int v = std::stoi(matchs[2].str(), nullptr);
  int b = std::stoi(matchs[3].str(), nullptr);
  float x1 = std::stof(matchs[4].str(), nullptr);
  float y1 = std::stof(matchs[5].str(), nullptr);
  float rayon = std::stof(matchs[6].str(), nullptr);
  return new Cercle(Couleur(r, v, b), Vecteur2D(x1, y1), rayon);
}
