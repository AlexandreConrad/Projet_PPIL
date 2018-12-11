#include <iostream>
#include "formes/Formes.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    Forme* croix = new Croix(40, 40, 100, 100);
    std::cout << *croix << std::endl;

    Forme* rond = new Rond(300, 300, 30);
    std::cout << *rond << std::endl;

    return EXIT_SUCCESS;
}