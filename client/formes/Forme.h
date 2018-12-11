//
// Created by theobarrague on 11/12/18.
//

#ifndef CLIENT_FORME_H
#define CLIENT_FORME_H

#include <iostream>


class Forme {
public:
    /* Constructeur */
    Forme();

    /* Destructeur */
    virtual ~Forme() = 0;

    /* Méthodes métier */
    void dessiner();

    /* Autres méthodes utiles */
    virtual operator std::string() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Forme& forme);
};


#endif //CLIENT_FORME_H
