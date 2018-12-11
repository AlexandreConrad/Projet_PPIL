//
// Created by theobarrague on 11/12/18.
//

#include "CroixException.h"


CroixException::CroixException(const char* message) : FormeException(message) {

}

const char* CroixException::what() const throw() {
    return FormeException::what();
}