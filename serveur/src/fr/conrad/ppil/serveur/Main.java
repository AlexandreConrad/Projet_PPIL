package fr.conrad.ppil.serveur;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.net.BindException;
import java.net.ServerSocket;
import java.net.Socket;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.dessinateur.Dessinateur;
import fr.conrad.ppil.serveur.dessinateur.DessinateurAWT;
import fr.conrad.ppil.serveur.formes.Forme;
import fr.conrad.ppil.serveur.formes.formes_simple.Segment;
import fr.conrad.ppil.serveur.liste_expert.ChargeurCercle;
import fr.conrad.ppil.serveur.liste_expert.ChargeurForme;
import fr.conrad.ppil.serveur.liste_expert.ChargeurFormeComposee;
import fr.conrad.ppil.serveur.liste_expert.ChargeurPolygone;
import fr.conrad.ppil.serveur.liste_expert.ChargeurSegment;
import fr.conrad.ppil.serveur.vecteur.Point;

public class Main {

	/**
	 * Point d'entr�e du programme
	 * @param args
	 */
	public static void main(String[] args) {
		
		try {
			
			/* Recherche d'un port disponible */
			int port = 25000;
			ServerSocket serverSocket = null;
			while ( true ) {
				try {
					serverSocket = new ServerSocket(port);
					break;
				} catch ( BindException e ) {
					System.err.println("Port " + port + " d�j� utilis�.");
				}
			}
			
			System.out.println("Serveur en �coute sur le port " + port);
			
		
			/* Cr�ation de notre cha�ne de responsabilit� */
			ChargeurForme chargeurForme = new ChargeurSegment();
			ChargeurForme chargeurCercle = new ChargeurCercle();
			ChargeurForme chargeurPolygone = new ChargeurPolygone();
			ChargeurForme chargeurFormeComposee = new ChargeurFormeComposee();
		
			/* Initilialisation des suivants */
			chargeurForme.setSuivant(chargeurCercle);
			chargeurCercle.setSuivant(chargeurPolygone);
			chargeurPolygone.setSuivant(chargeurFormeComposee);
		
			/*
			String informationcompo = "FormeComposee[Segment [(0,0,255),(25,45),(85,60)], Cercle [(0,255,0),(150,150),(150)], Polygone [(155,155,155),(150,140),(200,200),(100,200)], Polygone [(255,5,5),(100,100),(400,100),(400,400),(100,400)]]";
			String informationSegement = "Segment [(0,0,255),(25,45),(85.80,60.40)]";
			String informationCercle = "Cercle [(0,255,0),(150,150),(150)]";
			String informationTriangle = "Polygone [(155,155,155),(150,140),(200.10,200.15),(100,200)]";
			String informationRectangle = "Polygone [(255,5,5),(100,100),(400,100),(400,400),(100,400)]"; 
			*/
			
			/* Cr�ation du dessinateur */
			Dessinateur dessinateur = new DessinateurAWT();
			//Forme maForme = chargeurForme.traiter(informationcompo);
			//maForme.dessiner(dessinateur);
			
			//Segment seg = new Segment(new Couleur(255, 0, 0), new Point(1, 1), new Point(100, 100));
			//seg.dessiner(dessinateur);

			
			while ( true ) {
				Socket socket = serverSocket.accept(); // on accepte la connection
				Thread t = new Thread(new ClientProcessor(socket, chargeurForme, dessinateur));// on cr�e une instance
                t.start();
                
				System.out.println("Nouveau client !");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}

}
