//
// Created by theob on 15/01/2019.
//

#ifndef CLIENT_PPIL_CHARGEURCERCLE_H
#define CLIENT_PPIL_CHARGEURCERCLE_H

#include "ChargeurForme.h"

class ChargeurCercle : public ChargeurForme {
 public:
  virtual bool peutTraiter(std::string information);
  virtual Forme *traitementSpecialise(std::string information);
};

#endif  // CLIENT_PPIL_CHARGEURCERCLE_H
