package fr.conrad.ppil.serveur;
import fr.conrad.ppil.serveur.liste_expert.ChargeurForme;
import fr.conrad.ppil.serveur.liste_expert.ExpertCercle;
import fr.conrad.ppil.serveur.liste_expert.ExpertPolygone;
import fr.conrad.ppil.serveur.liste_expert.ExpertSegment;
import fr.conrad.ppil.serveur.liste_expert.ExpertTriangle;

public class Main {
	
 
	public static void main(String[] main){
	    
	   /*Cr�ation de notre ma�tre pour la chaine de responsabilit�*/
	   ChargeurForme chargeurSegment = new ExpertSegment();
	   ChargeurForme chargeurCercle = new ExpertCercle();
	   ChargeurForme chargeurTriangle = new ExpertTriangle();
	   ChargeurForme chargeurPolygone = new ExpertPolygone();
	   
	   /*Initilialisation des suivant*/
	   chargeurSegment.setSuivant(chargeurCercle);
	   chargeurCercle.setSuivant(chargeurTriangle);
	   chargeurTriangle.setSuivant(chargeurPolygone);
	   
	   /*Cr�ation provisoire des diff�rentes informations re�u en entr�e*/
	   String informationSegement = "Segment[25,45,85,25]";
	   String informationCercle = "Cercle[52,48,40]";
	   String informationTriangle = "Triangle[10,15,20,10,15,20]";
	   String informationPolygone = "Polygone[20,20,20,40]";
	   
	   /*Envoie de la premi�re information � l'expert*/
	   try {
		chargeurSegment.traiter(informationSegement);
	   } catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
	   }
	   
	   /*Envoie de la deuxi�me information � l'expert*/
	   try {
		chargeurSegment.traiter(informationCercle);
	   } catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
	   }
	   
	   /*Envoie de la troisi�me information � l'expert*/
	   try {
		chargeurSegment.traiter(informationTriangle);
	   } catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
	   }	
	   
	   /*Envoie de la 4�me information � l'expert*/
	   try {
		chargeurSegment.traiter(informationPolygone);
	   } catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
	   }	
	}
}
