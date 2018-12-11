//
// Created by theobarrague on 11/12/18.
//

#ifndef CLIENT_CROIXEXCEPTION_H
#define CLIENT_CROIXEXCEPTION_H

#include "../FormeException.h"


class CroixException : public FormeException {
public:
    CroixException(const char* message);
    const char* what() const throw();
};


#endif //CLIENT_CROIXEXCEPTION_H
