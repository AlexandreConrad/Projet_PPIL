package fr.conrad.ppil.serveur.liste_expert;

public class ExpertPolygone extends ChargeurForme{

	public ExpertPolygone() {}
	
	@Override
	boolean peutTraiter(String information) {
		
		/*sous chaine des 8 premiers caractères */
		String provisoire = information.substring(0,8);
		
		/*Si la chaine est égale à polygone , il retourne vrai*/
		return (provisoire.equals("Polygone"));
	}

	@Override
	FormeGeometrique traitementSpecialise(String information) {
		System.out.println("Traitement spécialisé reussi , je suis un Polygone");

		/*Création de la sous chaine coordonnée qui contient tous les chiffres */
		String provisoire = information.substring(9);
		String coordonnee = provisoire.replaceAll("]", "");
		 
		/*Tableau temp qui contient à chaque case une coordonnée*/
		String prov[] = coordonnee.split(",");
		   
		/*Création du centre du Polygone*/
	   
		/*On crée la forme et on la retourne*/
		FormeGeometrique polygone = new FormePolygone();
		return polygone;
	}
}
