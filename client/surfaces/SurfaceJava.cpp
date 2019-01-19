//
// Created by theobarrague on 11/01/19.
//

#include "SurfaceJava.h"
#include <formes/Forme.h>
#include <cstring>
#include <iostream>
#include <sstream>

SurfaceJava::SurfaceJava(std::string hote, int port, int longueur, int hauteur)
    : _hote(hote), _port(port) {
  _sock = Socket::getInstance().creerSocket(hote.c_str(), port);

  std::string configurationFenetre = "WinSize (";
  configurationFenetre += longueur;
  configurationFenetre += ",";
  configurationFenetre += hauteur;
  configurationFenetre += ");";
  Socket::getInstance().envoyer(_sock, configurationFenetre.c_str());
}

void SurfaceJava::dessiner(const Forme &forme) {
  std::string message = std::string(forme);
  message += ";";
  Socket::getInstance().envoyer(_sock, message.c_str());
}