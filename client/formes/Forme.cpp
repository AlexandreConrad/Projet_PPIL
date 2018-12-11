//
// Created by theobarrague on 11/12/18.
//

#include "Forme.h"

Forme::Forme() {

}

Forme::~Forme() {

}

void Forme::dessiner() {
    std::cout << "Envoi de la forme au serveur" << std::endl << " > " << std::string(*this) << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Forme& forme) {
    return os << std::string(forme);
}