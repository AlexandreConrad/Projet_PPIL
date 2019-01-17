package fr.conrad.ppil.serveur.liste_expert;

public class ExpertSegment extends ChargeurForme{

	/*Information toujours reçu sous forme "Segment [(1.0,2.0,3.0),(x,y),(x,y)]" */
	
	public ExpertSegment() {}
	
	@Override
	boolean peutTraiter(String information) {
		
		/*sous chaine des 7 premiers caractères */
		String provisoire = information.substring(0,7);
		
		/*Si la chaine est égale à ségement , il retourne vrai*/
		return (provisoire.equals("Segment"));
	}

	@Override
	FormeGeometrique traitementSpecialise(String information) {
		
		/*Information terminal*/
		System.out.println("Traitement spécialisé reussi , je suis un Ségment");

		/*Création de la sous chaine coordonnée qui contient tous les chiffres */
		String provisoire = information.substring(8);
		String coordonnee = provisoire.replaceAll("]", "");
		 
		/*Tableau temp qui contient à chaque case une coordonnée*/
		String prov[] = coordonnee.split(",");
	   
		/*Création des deux points du segment*/
		Point p1 = new Point(Float.parseFloat(prov[0]),Float.parseFloat(prov[1]));
		Point p2 = new Point(Float.parseFloat(prov[2]),Float.parseFloat(prov[3]));
	   
		/*On crée la forme et on la retourne*/
		FormeGeometrique segment = new FormeSegment(p1,p2);
		return segment;
	}
}
