//
// Created by theobarrague on 11/12/18.
//

#ifndef CLIENT_RONDEXCEPTION_H
#define CLIENT_RONDEXCEPTION_H

#include "../FormeException.h"


class RondException : public FormeException {
public:
    RondException(const char* message);
    const char* what() const throw();
};


#endif //CLIENT_RONDEXCEPTION_H
