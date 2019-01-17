package fr.conrad.ppil.serveur.liste_expert;

public class ExpertPolygone extends ChargeurForme{

	public ExpertPolygone() {}
	
	@Override
	boolean peutTraiter(String information) {
		
		/*sous chaine des 8 premiers caract�res */
		String provisoire = information.substring(0,8);
		
		/*Si la chaine est �gale � polygone , il retourne vrai*/
		return (provisoire.equals("Polygone"));
	}

	@Override
	FormeGeometrique traitementSpecialise(String information) {
		System.out.println("Traitement sp�cialis� reussi , je suis un Polygone");

		/*Cr�ation de la sous chaine coordonn�e qui contient tous les chiffres */
		String provisoire = information.substring(9);
		String coordonnee = provisoire.replaceAll("]", "");
		 
		/*Tableau temp qui contient � chaque case une coordonn�e*/
		String prov[] = coordonnee.split(",");
		   
		/*Cr�ation du centre du Polygone*/
	   
		/*On cr�e la forme et on la retourne*/
		FormeGeometrique polygone = new FormePolygone();
		return polygone;
	}
}
