package fr.conrad.ppil.serveur.liste_expert;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.formes.Forme;
import fr.conrad.ppil.serveur.formes.formes_simple.Cercle;
import fr.conrad.ppil.serveur.vecteur.Point;

/**
 * Chargeur Expert du Cercle
 * @author alexandre
 *
 */
public class ChargeurCercle extends ChargeurForme{

	/**
	 * Information toujours reçu sous forme "Cercle [(1.0,2.0,3.0),(x,y),rayon)]" 
	 */
	
	@Override
	boolean peutTraiter(String information) {
		/*Si la chaine est égale à Cercle , il retourne vrai*/
		return information.startsWith("Cercle");
	}

	@Override
	Forme traitementSpecialise(String information) throws Exception {
		
		/* Découpage du string reçu */
		String temp[] = modificationString(information, information.indexOf("[") + 1);
		
		/* Création du centre du cercle */
		Point centre = new Point(Float.parseFloat(temp[3]),Float.parseFloat(temp[4]));
	   
		/* Création de la couleur du cercle */
		Couleur couleurCercle = new Couleur(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]),Integer.parseInt(temp[2]));
		
		/* On crée la forme et on la retourne */	
		return new Cercle(couleurCercle, Float.parseFloat(temp[5]), centre);
	}
	
}
