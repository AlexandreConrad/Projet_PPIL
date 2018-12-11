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
	abstract boolean peutTraiter(/*Information à remplir*/);
	
	/*Fonction de traitement s'il peut traiter l'information*/
	abstract void /*Forme*/ traitementSpecialise();
	
	/*Fonction de test pour l'information*/
	public void traiter(/*Information*/) {
		if(peutTraiter() == true) {
			return traitementSpecialise();
		}else if (getSuivant() != null ) {
			return getSuivant().traiter();
		}else {
			throw Erreur();
		}
	}
}
