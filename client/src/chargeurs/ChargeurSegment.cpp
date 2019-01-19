//
// Created by theob on 15/01/2019.
//

#include "ChargeurSegment.h"
#include <Segment.h>
#include <iostream>
#include <regex>

bool ChargeurSegment::peutTraiter(std::string information) {
  return information.rfind("Segment", 0) == 0;
}

Forme *ChargeurSegment::traitementSpecialise(std::string information) {
  // Segment [(0,0,0),(0,0),(500,500)]
  std::regex regex(
      "\\[\\(([0-9]+),([0-9]+),([0-9]+)\\),\\(([0-9\\.\\-]+),([0-9\\.\\-]+)\\),"
      "\\(([0-9\\.\\-]+),([0-9\\.\\-]+)\\)\\]");
  std::smatch matchs;
  std::regex_search(information, matchs, regex);

  int r = std::stoi(matchs[1].str(), nullptr);
  int v = std::stoi(matchs[2].str(), nullptr);
  int b = std::stoi(matchs[3].str(), nullptr);
  float x1 = std::stof(matchs[4].str(), nullptr);
  float y1 = std::stof(matchs[5].str(), nullptr);
  float x2 = std::stof(matchs[6].str(), nullptr);
  float y2 = std::stof(matchs[7].str(), nullptr);
  return new Segment(Couleur(r, v, b), Vecteur2D(x1, y1), Vecteur2D(x2, y2));
}
