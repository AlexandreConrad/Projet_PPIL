//
// Created by theobarrague on 11/01/19.
//

#ifndef CLIENT_PPIL_SURFACEJAVA_H
#define CLIENT_PPIL_SURFACEJAVA_H

#include <src/sockets/Socket.h>
#include <src/surfaces/Surface.h>
#include <string>

/**
 * Représente une surface Java accessible via tcp/ip
 */
class SurfaceJava : public Surface {
 public:
  /**
   * Constructeur par défaut
   * @param hote L'hôte à utiliser
   * @param port Le port à utiliser
   * @param longueur La longueur de la fenêtre
   * @param hauteur La hauteur de la fenêtre
   */
  SurfaceJava(std::string hote = std::string("localhost"), int port = 25000,
              int longueur = 800, int hauteur = 600);

  /**
   * @see Surface::dessiner
   */
  virtual void dessiner(const Forme &forme);

  /**
   * Met à jour la surface Java ( envoi toutes les informations au serveur )
   */
  void miseAJour();

 private:
  /**
   * Représente l'hôte
   */
  std::string _hote;

  /**
   * Représente le port
   */
  int _port;

  /**
   * Représente la connexion réseau
   */
  SOCKET _sock;

  /**
   * Message à envoyer au serveur Java
   */
  std::string _message;
};

#endif  // CLIENT_PPIL_SURFACEJAVA_H
