//
// Created by theob on 15/01/2019.
//

#include "ChargeurFormeComposee.h"
#include <iostream>
#include <regex>
#include "src/formes/complexes/FormeComposee.h"

ChargeurFormeComposee::ChargeurFormeComposee(ChargeurForme *chargeur) {
  _chargeur = chargeur;
}

bool ChargeurFormeComposee::peutTraiter(std::string information) {
  return information.rfind("FormeComposee", 0) == 0;
}

Forme *ChargeurFormeComposee::traitementSpecialise(std::string information) {
  // FormeComposee [Cercle [...],Segment[...]]
  std::regex regex("\\[(.+)\\]");
  std::smatch matchs;
  std::regex_search(information, matchs, regex);

  information = matchs[1].str();

  std::string delimiter = ", ";

  FormeComposee *formeComposee = new FormeComposee();

  size_t pos = 0;
  std::string token;
  while ((pos = information.find(delimiter)) != std::string::npos) {
    token = information.substr(0, pos);
    formeComposee->ajouterForme(*_chargeur->charger(token));
    information.erase(0, pos + delimiter.length());
  }
  formeComposee->ajouterForme(*_chargeur->charger(information));

  return formeComposee;
}