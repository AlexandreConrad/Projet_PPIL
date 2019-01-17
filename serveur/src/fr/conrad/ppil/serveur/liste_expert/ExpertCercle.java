package fr.conrad.ppil.serveur.liste_expert;

public class ExpertCercle extends ChargeurForme{

	public ExpertCercle() {}
	
	
	@Override
	boolean peutTraiter(String information) {
		
		/*sous chaine des 6 premiers caractères */
		String provisoire = information.substring(0,6);
		
		/*Si la chaine est égale à cercle , il retourne vrai*/
		return (provisoire.equals("Cercle"));
	}

	@Override
	FormeGeometrique traitementSpecialise(String information) {
		System.out.println("Traitement spécialisé reussi , je suis un Cercle");

		/*Création de la sous chaine coordonnée qui contient tous les chiffres */
		String provisoire = information.substring(7);
		String coordonnee = provisoire.replaceAll("]", "");
		 
		/*Tableau temp qui contient à chaque case une coordonnée*/
		String prov[] = coordonnee.split(",");
		   
		/*Création du centre du cercle*/
		Point centre = new Point(Float.parseFloat(prov[0]),Float.parseFloat(prov[1]));
	   
		/*On crée la forme et on la retourne*/
		FormeGeometrique cercle = new FormeCercle(centre,Float.parseFloat(prov[2]));
		return cercle;
	}
}
