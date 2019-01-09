package fr.conrad.ppil.serveur;
import fr.conrad.ppil.serveur.liste_expert.ChargeurForme;
import fr.conrad.ppil.serveur.liste_expert.ExpertCercle;
import fr.conrad.ppil.serveur.liste_expert.ExpertPolygone;
import fr.conrad.ppil.serveur.liste_expert.ExpertSegment;
import fr.conrad.ppil.serveur.liste_expert.ExpertTriangle;

public class Main {
	
 
	public static void main(String[] main){
	    
	   /*Création de notre maître pour la chaine de responsabilité*/
	   ChargeurForme chargeurSegment = new ExpertSegment();
	   ChargeurForme chargeurCercle = new ExpertCercle();
	   ChargeurForme chargeurTriangle = new ExpertTriangle();
	   ChargeurForme chargeurPolygone = new ExpertPolygone();
	   
	   /*Initilialisation des suivant*/
	   chargeurSegment.setSuivant(chargeurCercle);
	   chargeurCercle.setSuivant(chargeurTriangle);
	   chargeurTriangle.setSuivant(chargeurPolygone);
	   
	   /*Création provisoire des différentes informations reçu en entrée*/
	   String informationSegement = "Segment[25,45,85,25]";
	   String informationCercle = "Cercle[52,48,40]";
	   String informationTriangle = "Triangle[10,15,20,10,15,20]";
	   String informationPolygone = "Polygone[20,20,20,40]";
	   
	   /*Envoie de la première information à l'expert*/
	   try {
		chargeurSegment.traiter(informationSegement);
	   } catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
	   }
	   
	   /*Envoie de la deuxième information à l'expert*/
	   try {
		chargeurSegment.traiter(informationCercle);
	   } catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
	   }
	   
	   /*Envoie de la troisième information à l'expert*/
	   try {
		chargeurSegment.traiter(informationTriangle);
	   } catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
	   }	
	   
	   /*Envoie de la 4ème information à l'expert*/
	   try {
		chargeurSegment.traiter(informationPolygone);
	   } catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
	   }	
	}
}
