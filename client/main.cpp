#include <iostream>
#include <exception>
#include "formes/Formes.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string ip;
    int port;

    std::cout << "Adresse du serveur ( 127.0.0.1 par défaut ) : ";
    std::getline(std::cin, ip);

    bool continuer = true;
    do {
        try {
            std::cout << "Port du serveur ( 1069 par défaut ) : ";
            std::string temp;
            std::getline(std::cin, temp);
            port = std::stoi(temp, nullptr, 10);
            continuer = false;
        } catch (std::exception &e) {

        }
    } while ( continuer );

    Forme* croix = new Croix(40, 40, 100, 100);
    std::cout << *croix << std::endl;

    Forme* rond = new Rond(300, 300, 30);
    std::cout << *rond << std::endl;

    croix->dessiner();
    rond->dessiner();

    return EXIT_SUCCESS;
}