package fr.conrad.ppil.serveur.liste_expert;

import fr.conrad.ppil.serveur.formes.Forme;

/**
 * Chargeur Forme Expert , s'occupe de transmettre les informations au fils
 * @author alexandre
 *
 */
public abstract class ChargeurForme {
	
	/**
	 * Donn�e membre
	 */
	private ChargeurForme _Suivant;
	
	/**
	 * Constructeur par d�faut
	 */
	public ChargeurForme() {}
	
	/*Getter du suivant*/
	
	/**
	 * R�cup�re le suivant de la liste d'expert
	 * @return
	 */
	public ChargeurForme getSuivant() {
		return _Suivant;
	}
	
	/*Setter du suivant*/
	
	/**
	 * Initialise le suivant
	 * @param prochain
	 * @return
	 */
	public ChargeurForme setSuivant(ChargeurForme prochain) {
		this._Suivant = prochain;
		return _Suivant;
	}
	
	/**
	 * Fonction abstraite qui test s'il correspond
	 * @param information
	 * @return
	 */
	abstract boolean peutTraiter(String information);
	
	/**
	 * Fonction abstraire qui r�alise le traitement si la forme correspond
	 * @param information
	 * @return
	 * @throws Exception
	 */
	abstract Forme traitementSpecialise(String information) throws Exception;
	
	/**
	 * Fonction qui retourne la forme apr�s traitement par la chaine de responsabilit�
	 * @param information
	 * @return
	 * @throws Exception
	 */
	public Forme traiter(String information) throws Exception {
		if(peutTraiter(information) == true) {
			return traitementSpecialise(information);
		}else if (getSuivant() != null ) {
			return getSuivant().traiter(information);
		}else {
			throw new Exception("Aucun traitement n\'a p� �tre r�alis�!");
		}
	}
	
	/*M�thodes*/
	
	/**
	 * Modification du string re�u en entr�e , d�coupage de la chaine et retourner dans un tableau de string
	 * @param information
	 * @param dep
	 * @return
	 */
	public String[] modificationString(String information , int dep) {
		
		/* Cr�ation de la sous chaine coordonn�e qui contient toutes les informations */
		String provisoire = information.substring(dep);
		String coordonnee = provisoire.replace("]", "").replace("(","").replace(")","");
		 
		/* Tableau temp qui contient � chaque case un chiffre */
		/* Les 3 premiers pour la couleur et le reste sont les points */
		String temp[] = coordonnee.split(",");
		
		return temp;
	}
}
