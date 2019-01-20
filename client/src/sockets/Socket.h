//
// Created by theobarrague on 14/01/19.
//

#ifndef CLIENT_PPIL_SOCKET_H
#define CLIENT_PPIL_SOCKET_H

#ifdef _WIN32
#include <winsock2.h>
#elif defined (__linux__)
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
#endif

/**
 * Représente une connexion réseau
 * Classe singleton
 */
class Socket {
 public:
  /**
   * Destructeur
   */
  ~Socket();

  /**
   * @return L'instance de la classe
   */
  static Socket &getInstance();

  /**
   * Créer une socket et la connecte à l'hôte et au port spéicifié
   * @param hote L'hôte à utiliser
   * @param port Le port à utiliser
   * @return Une socket connettée
   */
  SOCKET creerSocket(const char *hote, int port);

  /**
   * Envoi un message sur une socket
   * @param socket La socket à utiliser
   * @param message Le message à envoyer
   */
  void envoyer(SOCKET socket, const char *message);

 private:
  /**
   * Constructeur ( privé car classe singleton )
   */
  Socket();

  /**
   * Représente l'instance de la classe
   */
  static Socket *_instance;
};

#endif //CLIENT_PPIL_SOCKET_H
