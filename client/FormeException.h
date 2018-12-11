//
// Created by theobarrague on 11/12/18.
//

#ifndef CLIENT_FORMEEXCEPTION_H
#define CLIENT_FORMEEXCEPTION_H

#include <exception>
#include <iostream>

class FormeException : public std::exception {
public:
    FormeException(const char* message);
    const char* what() const throw();

private:
    std::string _message;
};


#endif //CLIENT_FORMEEXCEPTION_H
