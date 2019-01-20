//
// Created by theob on 15/01/2019.
//

#ifndef CLIENT_PPIL_CHARGEURFORME_H
#define CLIENT_PPIL_CHARGEURFORME_H

#include <Forme.h>
#include <stdexcept>
#include <string>

class ChargeurForme {
 public:
  virtual bool peutTraiter(std::string information) = 0;
  virtual Forme *charger(std::string information) {
    if (peutTraiter(information))
      return traitementSpecialise(information);
    else if (_suivant != nullptr)
      return _suivant->charger(information);
    else
      throw std::runtime_error("Impossible de charger la forme inconnue.");
  }
  virtual Forme *traitementSpecialise(std::string information) = 0;
  ChargeurForme *setSuivant(ChargeurForme *suivant) {
    _suivant = suivant;
    return _suivant;
  }

 private:
  ChargeurForme *_suivant = nullptr;
};

#endif  // CLIENT_PPIL_CHARGEURFORME_H
