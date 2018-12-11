//
// Created by theobarrague on 11/12/18.
//

#include "RondException.h"


RondException::RondException(const char* message) : FormeException(message) {

}

const char* RondException::what() const throw() {
    return FormeException::what();
}