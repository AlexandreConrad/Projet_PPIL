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
	 * Information toujours re�u sous forme "Cercle [(1.0,2.0,3.0),(x,y),rayon)]" 
	 */
	
	@Override
	boolean peutTraiter(String information) {
		/*Si la chaine est �gale � Cercle , il retourne vrai*/
		return information.startsWith("Cercle");
	}

	@Override
	Forme traitementSpecialise(String information) throws Exception {
		
		/* D�coupage du string re�u */
		String temp[] = modificationString(information, information.indexOf("[") + 1);
		
		/* Cr�ation du centre du cercle */
		Point centre = new Point(Float.parseFloat(temp[3]),Float.parseFloat(temp[4]));
	   
		/* Cr�ation de la couleur du cercle */
		Couleur couleurCercle = new Couleur(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]),Integer.parseInt(temp[2]));
		
		/* On cr�e la forme et on la retourne */	
		return new Cercle(couleurCercle, Float.parseFloat(temp[5]), centre);
	}
	
}
