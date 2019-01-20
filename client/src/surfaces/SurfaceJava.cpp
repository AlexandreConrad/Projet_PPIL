//
// Created by theobarrague on 11/01/19.
//

#include "SurfaceJava.h"
#include <src/formes/Forme.h>
#include <cstring>
#include <iostream>
#include <sstream>

SurfaceJava::SurfaceJava(std::string hote, int port, int longueur, int hauteur)
    : _hote(hote), _port(port), _message("") {
  _sock = Socket::getInstance().creerSocket(hote.c_str(), port);

  /*std::string configurationFenetre = "WinSize (";
  configurationFenetre += longueur;
  configurationFenetre += ",";
  configurationFenetre += hauteur;
  configurationFenetre += ");";
  Socket::getInstance().envoyer(_sock, configurationFenetre.c_str());*/
}

void SurfaceJava::dessiner(const Forme &forme) {
  _message += std::string(forme);
  _message += ";";
}

void SurfaceJava::miseAJour() {
  Socket::getInstance().envoyer(_sock, _message.c_str());
}