//
// Created by theobarrague on 14/01/19.
//

#include "Socket.h"
#include <stdexcept>

Socket *Socket::_instance = nullptr;

Socket::Socket() {
#ifdef _WIN32
  WSADATA wsa;
  if (WSAStartup(MAKEWORD(2, 2), &wsa) < 0) {
    throw std::runtime_error("Impossible de démarrer la bibliothèque WinSock.");
  }
#endif
}

Socket::~Socket() {
#ifdef _WIN32
  WSACleanup();
#endif
}

Socket &Socket::getInstance() {
  if (_instance == nullptr)
    _instance = new Socket();
  return *_instance;
}

SOCKET Socket::creerSocket(const char *hote, int port) {
  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

  struct hostent *hostinfo = NULL;
  SOCKADDR_IN sin = {0};

  hostinfo = gethostbyname(hote);
  if (hostinfo == NULL)
    throw std::runtime_error("Impossible de résoudre le nom de l'hôte.");

  sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
  sin.sin_port = htons(port);
  sin.sin_family = AF_INET;

  if (connect(sock, (SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
    throw std::runtime_error("Impossible de se connecter à l'hôte spécifié.");

  return sock;
}

void Socket::envoyer(SOCKET socket, const char *message) {
  if (send(socket, message, strlen(message), 0) < 0)
    throw std::runtime_error("Impossible d'envoyer le message au serveur.");
}
