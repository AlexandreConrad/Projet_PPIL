package fr.conrad.ppil.serveur.liste_expert;

public class ExpertTriangle extends ChargeurForme{

	public ExpertTriangle() {}
	
	@Override
	boolean peutTraiter(String information) {
		
		/*sous chaine des 8 premiers caract�res */
		String provisoire = information.substring(0,8);
		
		/*Si la chaine est �gale � triangle , il retourne vrai*/
		return (provisoire.equals("Triangle"));
	}

	@Override
	FormeGeometrique traitementSpecialise(String information) {
		System.out.println("Traitement sp�cialis� reussi , je suis un Triangle");

		/*Cr�ation de la sous chaine coordonn�e qui contient tous les chiffres */
		String provisoire = information.substring(9);
		String coordonnee = provisoire.replaceAll("]", "");
		 
		/*Tableau temp qui contient � chaque case une coordonn�e*/
		String prov[] = coordonnee.split(",");
		 
		/*Cr�ation des trois points du triangle*/
		Point p1 = new Point(Float.parseFloat(prov[0]),Float.parseFloat(prov[1]));
		Point p2 = new Point(Float.parseFloat(prov[2]),Float.parseFloat(prov[3]));
		Point p3 = new Point(Float.parseFloat(prov[4]),Float.parseFloat(prov[5]));
		
		/*On cr�e la forme et on la retourne*/
		FormeGeometrique triangle = new FormeTriangle(p1,p2,p3);
		return triangle;
	}
}
