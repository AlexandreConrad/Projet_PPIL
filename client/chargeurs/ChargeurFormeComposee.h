//
// Created by theob on 15/01/2019.
//

#ifndef CLIENT_PPIL_CHARGEURFORMECOMPOSEE_H
#define CLIENT_PPIL_CHARGEURFORMECOMPOSEE_H

#include "ChargeurForme.h"

class ChargeurFormeComposee : public ChargeurForme {
 public:
  ChargeurFormeComposee(ChargeurForme *chargeur);
  virtual bool peutTraiter(std::string information);
  virtual Forme *traitementSpecialise(std::string information);

 private:
  ChargeurForme *_chargeur;
};

#endif  // CLIENT_PPIL_CHARGEURFORMECOMPOSEE_H
