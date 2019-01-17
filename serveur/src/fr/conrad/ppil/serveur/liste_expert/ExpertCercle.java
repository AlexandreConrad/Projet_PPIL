package fr.conrad.ppil.serveur.liste_expert;

public class ExpertCercle extends ChargeurForme{

	public ExpertCercle() {}
	
	
	@Override
	boolean peutTraiter(String information) {
		
		/*sous chaine des 6 premiers caract�res */
		String provisoire = information.substring(0,6);
		
		/*Si la chaine est �gale � cercle , il retourne vrai*/
		return (provisoire.equals("Cercle"));
	}

	@Override
	FormeGeometrique traitementSpecialise(String information) {
		System.out.println("Traitement sp�cialis� reussi , je suis un Cercle");

		/*Cr�ation de la sous chaine coordonn�e qui contient tous les chiffres */
		String provisoire = information.substring(7);
		String coordonnee = provisoire.replaceAll("]", "");
		 
		/*Tableau temp qui contient � chaque case une coordonn�e*/
		String prov[] = coordonnee.split(",");
		   
		/*Cr�ation du centre du cercle*/
		Point centre = new Point(Float.parseFloat(prov[0]),Float.parseFloat(prov[1]));
	   
		/*On cr�e la forme et on la retourne*/
		FormeGeometrique cercle = new FormeCercle(centre,Float.parseFloat(prov[2]));
		return cercle;
	}
}
