package fr.conrad.ppil.serveur.liste_expert;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.formes.Forme;
import fr.conrad.ppil.serveur.formes.formes_simple.Polygone;
import fr.conrad.ppil.serveur.vecteur.Point;

/**
 * Chargeur du Polugone
 * @author alexandre
 *
 */
public class ChargeurPolygone extends ChargeurForme{

	/**
	 * Information toujours reçu sous forme "Polygone [(1.0,2.0,3.0),(x,y),(x,y),....]" 
	 */
	
	/**
	 * Constructeur par défaut
	 */
	public ChargeurPolygone() {}
	
	@Override
	boolean peutTraiter(String information) {
		/* Si la chaine commence par polygone, il retourne vrai */
		return (information.startsWith("Polygone"));
	}

	@Override
	Forme traitementSpecialise(String information) throws Exception {
		
		/* Découpage du string reçu */
		String temp[] = modificationString(information, information.indexOf("[") + 1);
		
		/* Récupération de la longeur du tableau */
		int taille = temp.length;
		
		/* Création de la couleur du polygone */
		Couleur couleurPolygone = new Couleur(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]),Integer.parseInt(temp[2]));
		
		/* On crée la forme et on la retourne */
		Forme polygone = new Polygone(couleurPolygone);
		
		/* Création des points du Polygone , 3 première case occupé par les couleurs */
		for(int i = 3 ; i < taille ; i+=2) {
			Point p = new Point(Float.parseFloat(temp[i]),Float.parseFloat(temp[i+1]));
			polygone.addPoint(p);
		}
	
		return polygone;
	}

}
