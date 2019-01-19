//
// Created by theob on 15/01/2019.
//

#include "ChargeurPolygone.h"
#include <Polygone.h>
#include <iostream>
#include <regex>

bool ChargeurPolygone::peutTraiter(std::string information) {
  return information.rfind("Polygone", 0) == 0;
}

Forme *ChargeurPolygone::traitementSpecialise(std::string information) {
  // Polygone [(0,0,0),...]
  std::regex regex(
      "\\[\\(([0-9]+),([0-9]+),([0-9]+)\\),(\\([0-9\\.\\-]+,[0-9\\.\\-]+\\).+)+"
      "\\]");
  std::smatch matchs;
  std::regex_search(information, matchs, regex);

  int r = std::stoi(matchs[1].str(), nullptr);
  int v = std::stoi(matchs[2].str(), nullptr);
  int b = std::stoi(matchs[3].str(), nullptr);

  Polygone *p = new Polygone(Couleur(r, v, b));

  std::regex regexNombre("([0-9\\.\\-]+)");
  std::string strPoints = matchs[4].str();
  std::vector<float> vecteurPoints;

  while (std::regex_search(strPoints, matchs, regexNombre)) {
    vecteurPoints.push_back(std::stof(matchs[0].str(), nullptr));
    strPoints = matchs.suffix().str();
  }

  for (int i = 0; i < vecteurPoints.size(); i += 2) {
    float x = vecteurPoints.at(i);
    float y = vecteurPoints.at(i + 1);
    p->ajouterSommet(Vecteur2D(x, y));
  }

  return p;
}