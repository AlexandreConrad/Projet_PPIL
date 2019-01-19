package fr.conrad.ppil.serveur.liste_expert;

import java.util.ArrayList;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.formes.Forme;
import fr.conrad.ppil.serveur.formes.formes_complexes.FormeComposee;

/**
 * Chargeur de forme composée
 * @author alexandre
 *
 */
public class ChargeurFormeComposee extends ChargeurForme{
	
	/**
	 * information reçu est sous la forme FormeComposee [Segment [(255,255,255),(x,y),(x,y)], Cercle [(1.0,2.0,3.0),(x,y),rayon)], ...]
	 */

	@Override
	boolean peutTraiter(String information) {
		/* Si la chaine commence par FormeComposee, il retourne vrai */
		return (information.startsWith("FormeComposee"));
	}

	@Override
	Forme traitementSpecialise(String information) throws Exception {
		
		/* Découpage du string reçu */
		String prov = information.substring(information.indexOf("[") + 1, information.length()-1);
		String temp[] = prov.split("],");
		
		/* Création de notre chaîne de responsabilité */
		ChargeurForme chargeurForme = new ChargeurSegment();
		ChargeurForme chargeurCercle = new ChargeurCercle();
		ChargeurForme chargeurPolygone = new ChargeurPolygone();
		ChargeurForme chargeurFormeComposee = new ChargeurFormeComposee();
	
		/* Initilialisation des suivants */
		chargeurForme.setSuivant(chargeurCercle);
		chargeurCercle.setSuivant(chargeurPolygone);
		chargeurPolygone.setSuivant(chargeurFormeComposee);
		
		/* Liste des formes reç u*/
		ArrayList<Forme> formes = new ArrayList<Forme>();
		
		/* On applique un traitement pour avoir un découpage parfait pour l'envoie à la chaine de reponsabilité */
		for(int i = 0 ; i < temp.length ; i++) {
			String informationBis = temp[i];
			if  (i == 0) {
				informationBis += "]";
			} else if ( i + 1 < temp.length ) {
				informationBis += "]";
				informationBis = informationBis.substring(1, informationBis.length());
			} else {
				informationBis = informationBis.substring(1, informationBis.length());
			}
			
			/* Affichage des informations */
			System.out.println(informationBis);
			
			/* On récupere la forme et on l'ajoute à notre liste */
			Forme provisoireForme = chargeurForme.traiter(informationBis);
			formes.add(provisoireForme);
		}
		
		/* On envoie la forme  à forme composée */
		FormeComposee formeComposee = new FormeComposee(new Couleur(0, 0, 0));
		for ( Forme f : formes )
			formeComposee.ajouterForme(f);
	
		return formeComposee;
	}
}
