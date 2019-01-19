package fr.conrad.ppil.serveur.liste_expert;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.formes.Forme;
import fr.conrad.ppil.serveur.formes.formes_simple.Segment;
import fr.conrad.ppil.serveur.vecteur.Point;

/**
 * Chargeur Segment
 * @author alexandre
 *
 */
public class ChargeurSegment extends ChargeurForme{

	/**
	 * Information toujours reçu sous forme "Segment [(255,255,255),(x,y),(x,y)]" 
	 **/
	
	/**
	 * Constructeur par défaut
	 */
	public ChargeurSegment() {}
	
	@Override
	boolean peutTraiter(String information) {
		/* Si la chaine commence par segment, il retourne vrai */
		return (information.startsWith("Segment"));
	}

	@Override
	Forme traitementSpecialise(String information) throws Exception {
		
		/* Découpage du string reç u*/
		String temp[] = modificationString(information, information.indexOf("[") + 1);
		
		/* Création des deux points du segment */
		Point p1 = new Point(Float.parseFloat(temp[3]),Float.parseFloat(temp[4]));
		Point p2 = new Point(Float.parseFloat(temp[5]),Float.parseFloat(temp[6]));
	   
		/* Création de la couleur du segement */
		Couleur couleurSegment = new Couleur(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]),Integer.parseInt(temp[2]));
		
		/* On crée la forme et on la retourne */
		return new Segment(couleurSegment,p1,p2);
	}
}
