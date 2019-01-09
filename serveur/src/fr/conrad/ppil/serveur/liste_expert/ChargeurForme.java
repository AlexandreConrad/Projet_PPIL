package fr.conrad.ppil.serveur.liste_expert;

public abstract class ChargeurForme {

	private ChargeurForme suivant;
	
	/*Constructeur*/
	public ChargeurForme() {
		
	}
	
	/*Accès au suivant*/
	public ChargeurForme getSuivant() {
		return suivant;
	}
	
	/*Nouveau suivant*/
	public ChargeurForme setSuivant(ChargeurForme prochain) {
		this.suivant = prochain;
		return suivant;
	}
	
	/*Fonction abstraite pour savoir s'il peut traiter l'information*/
	/*Information toujours sous forme "Croix [ x , y , z , w ]"s*/
	abstract boolean peutTraiter(String information);
	
	/*Fonction de traitement s'il peut traiter l'information*/
	abstract FormeGeometrique traitementSpecialise(String information);
	
	/*Fonction de test pour l'information*/
	public FormeGeometrique traiter(String information) throws Exception {
		if(peutTraiter(information) == true) {
			return traitementSpecialise(information);
		}else if (getSuivant() != null ) {
			return getSuivant().traiter(information);
		}else {
			throw new Exception("Aucun traitement n\' pu être réalisé!");
		}
	}
}
