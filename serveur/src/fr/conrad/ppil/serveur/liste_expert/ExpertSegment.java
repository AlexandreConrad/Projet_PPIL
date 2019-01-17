package fr.conrad.ppil.serveur.liste_expert;

public class ExpertSegment extends ChargeurForme{

	/*Information toujours re�u sous forme "Segment [(1.0,2.0,3.0),(x,y),(x,y)]" */
	
	public ExpertSegment() {}
	
	@Override
	boolean peutTraiter(String information) {
		
		/*sous chaine des 7 premiers caract�res */
		String provisoire = information.substring(0,7);
		
		/*Si la chaine est �gale � s�gement , il retourne vrai*/
		return (provisoire.equals("Segment"));
	}

	@Override
	FormeGeometrique traitementSpecialise(String information) {
		
		/*Information terminal*/
		System.out.println("Traitement sp�cialis� reussi , je suis un S�gment");

		/*Cr�ation de la sous chaine coordonn�e qui contient tous les chiffres */
		String provisoire = information.substring(8);
		String coordonnee = provisoire.replaceAll("]", "");
		 
		/*Tableau temp qui contient � chaque case une coordonn�e*/
		String prov[] = coordonnee.split(",");
	   
		/*Cr�ation des deux points du segment*/
		Point p1 = new Point(Float.parseFloat(prov[0]),Float.parseFloat(prov[1]));
		Point p2 = new Point(Float.parseFloat(prov[2]),Float.parseFloat(prov[3]));
	   
		/*On cr�e la forme et on la retourne*/
		FormeGeometrique segment = new FormeSegment(p1,p2);
		return segment;
	}
}
