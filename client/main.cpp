#include <Cercle.h>
#include <ChargeurCercle.h>
#include <Homothetie.h>
#include <Rotation.h>
#include <SauvegardeTexte.h>
#include <SurfaceJava.h>
#include <formes/complexes/FormeComposee.h>
#include <cmath>
#include <fstream>
#include <iostream>
#ifdef _WIN32
#endif

const double PI = 3.141592653;

int main() {
  //
  // Défini le format d'encodage en UTF-8 pour Windows
  //
#ifdef _WIN32
  SetConsoleOutputCP(65001);
#endif

  //
  // Sans cette ligne, rien ne fonctionne ( :blague: )
  //
  std::cout << "Hello world!" << std::endl << std::endl;

  //
  // Création de quelques couleurs
  //
  Couleur noir = Couleur::getCouleurNoir();
  Couleur rouge = Couleur::getCouleurRouge();
  Couleur vert = Couleur::getCouleurVert();
  Couleur bleu = Couleur::getCouleurBleu();

  //
  // Création de quelques transformations
  //
  Translation translation(Vecteur2D(-50, 50));
  Rotation rotation(Vecteur2D(250, 250), 0 * PI / 180);
  Homothetie homothetie(Vecteur2D(0, 0), 2);

  //
  // Création des formes
  //
  Segment segment(noir, Vecteur2D(250, 250), Vecteur2D(400, 250));
  Cercle cercle(noir, Vecteur2D(250, 250), 150);
  Polygone polygone(vert);
  polygone.ajouterSommet(Vecteur2D(100, 100));
  polygone.ajouterSommet(Vecteur2D(300, 100));
  polygone.ajouterSommet(Vecteur2D(300, 300));
  polygone.ajouterSommet(Vecteur2D(100, 300));
  Triangle triangle(bleu, Vecteur2D(250, 250), Vecteur2D(400, 400), Vecteur2D(100, 400));
  FormeComposee formeComposee;
  formeComposee.ajouterForme(segment);
  formeComposee.ajouterForme(cercle);

  //
  // TESTS
  //
  SurfaceJava surfaceJava("localhost", 25000);
  FormeComposee f;
  f.ajouterForme(*segment.transformer(Rotation(Vecteur2D(250, 250), -45 * 0 * PI / 180)));
  f.ajouterForme(*segment.transformer(Rotation(Vecteur2D(250, 250), -45 * 1 * PI / 180)));
  f.ajouterForme(*segment.transformer(Rotation(Vecteur2D(250, 250), -45 * 2 * PI / 180)));
  f.ajouterForme(*segment.transformer(Rotation(Vecteur2D(250, 250), -45 * 3 * PI / 180)));
  f.ajouterForme(*segment.transformer(Rotation(Vecteur2D(250, 250), -45 * 4 * PI / 180)));
  f.ajouterForme(*segment.transformer(Rotation(Vecteur2D(250, 250), -45 * 5 * PI / 180)));
  f.ajouterForme(*segment.transformer(Rotation(Vecteur2D(250, 250), -45 * 6 * PI / 180)));
  f.ajouterForme(*segment.transformer(Rotation(Vecteur2D(250, 250), -45 * 7 * PI / 180)));
  f.ajouterForme(cercle);
  f.transformer(Rotation(Vecteur2D(250, 250), 15 * PI / 180))->transformer(Homothetie(Vecteur2D(250, 250),
                                                                                      0.5))->dessiner(surfaceJava);
  surfaceJava.miseAJour();

  //
  // Applications des transformations
  //
  Forme *segmentTransforme = segment.transformer(rotation);
  Forme *cercleTransforme = cercle.transformer(translation);
  Forme *polygoneTransforme = polygone.transformer(homothetie);

  //
  // Affichage des formes dans la console
  //
  /*std::cout << "Quelques formes créées de façon statique :" << std::endl;
  std::cout << *segmentTransforme << std::endl;
  std::cout << *cercleTransforme << std::endl;
  std::cout << *polygoneTransforme << std::endl;
  std::cout << triangle << std::endl;
  std::cout << formeComposee << std::endl << std::endl;*/

  //
  // Sauvegarde des formes
  //
  /*std::cout << "Où enregistrer ces formes ? ";
  std::string chemin;
  std::cin >> chemin;

  SauvegardeTexte sauvegardeTexte(chemin.c_str());
  segmentTransforme->sauvegarder(sauvegardeTexte);
  cercleTransforme->sauvegarder(sauvegardeTexte);
  polygoneTransforme->sauvegarder(sauvegardeTexte);
  triangle.sauvegarder(sauvegardeTexte);
  formeComposee.sauvegarder(sauvegardeTexte);*/

  //
  // Affichage
  //
  /*std::cout << std::endl << "Affichage des formes depuis le fichier ..." << std::endl;
  try {
    //
    // Création de la surface java
    //
    SurfaceJava surfaceJava("localhost", 25000);

    //
    // Chargement et affichage des formes
    //
    ChargeurForme *chargeur = new ChargeurSegment();
    chargeur->setSuivant(new ChargeurCercle())
        ->setSuivant(new ChargeurPolygone())
        ->setSuivant(new ChargeurFormeComposee(chargeur));

    //
    // Lecture du fichier
    //
    std::ifstream fichier("formes.txt", std::ios::in);
    std::string ligne("");

    //
    // Affichage des formes sur une surface graphique
    //
    while (std::getline(fichier, ligne)) {
      Forme *forme = chargeur->charger(ligne);
      forme->dessiner(surfaceJava);
      std::cout << "Affichage de  : " << *forme << std::endl;
      delete forme;
    }

    surfaceJava.miseAJour();

    delete chargeur;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }*/

  //
  // Libération
  //
  delete segmentTransforme;
  delete cercleTransforme;
  delete polygoneTransforme;

  //
  // Fin :)
  //
  std::cout << "Terminé !" << std::endl;

  return EXIT_SUCCESS;
}