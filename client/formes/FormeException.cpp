//
// Created by theobarrague on 11/12/18.
//

#include "FormeException.h"


FormeException::FormeException(const char *message) : _message(message) {

}

const char* FormeException::what() const throw() {
    return _message.c_str();
}