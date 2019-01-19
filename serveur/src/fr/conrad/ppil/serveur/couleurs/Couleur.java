package fr.conrad.ppil.serveur.couleurs;

/**
 * Représente une couleur caractérisé par un niveau de rouge, vert et bleu ( compris entre 0 et 255 )
 * @author alexandre
 *
 */
public class Couleur {
		
	/**
	 * Donnée membre pour chaque couleur
	 */
	private int _Rouge;
	private int _Vert;
	private int _Bleu;
	
	/**
	 * Constructeur d'une couleur , prend le RVB et peut retourner une erreur si les couleurs ne sont pas compris entre 0 et 255
	 * @param rouge
	 * @param vert
	 * @param bleu
	 * @throws CouleurException
	 */
	public Couleur(int rouge , int vert , int bleu) throws CouleurException {
		this.setRouge(rouge);
		this.setVert(vert);
		this.setBleu(bleu);
	}

	/* Setters */
	
	/**
	 *  Setteur du Rouge , doit être compris entre 0 et 255
	 * @param rouge
	 * @throws CouleurException
	 */
	private void setRouge(int rouge) throws CouleurException {
		if ( rouge > 255 || rouge < 0 )
			throw new CouleurException("La valeur de la couleur rouge est invalide ( doit être comprise entre 0 et 255 )");
		_Rouge = rouge;
	}
	
	/**
	 * Setteur du vert , doit être compris entre 0 et 255
	 * @param vert
	 * @throws CouleurException
	 */
	private void setVert(int vert) throws CouleurException {
		if ( vert > 255 || vert < 0 )
			throw new CouleurException("La valeur de la couleur vert est invalide ( doit être comprise entre 0 et 255 )");
		_Vert = vert;	
	}
	
	/**
	 *  Setteur de bleu , doit être compris entre 0 et 255
	 * @param bleu
	 * @throws CouleurException
	 */
	private void setBleu(int bleu) throws CouleurException {
		if ( bleu < 0 || bleu > 255 )
			throw new CouleurException("La valeur de la couleur bleu est invalide ( doit être comprise entre 0 et 255 )");
		_Bleu = bleu;
	}
	
	/* Getters */
	
	/**
	 *  Retourne l'entier qui correspond au rouge
	 * @return
	 */
	public int getRouge() {
		return _Rouge;
	}
	
	/**
	 * Retourne l'entier qui correspond au vert
	 * @return
	 */
	public int getVert() {
		return _Vert;
	}
	
	/**
	 * Retourne la partis qui correspond au bleu
	 * @return
	 */
	public int getBleu() {
		return _Bleu;
	}
	
	/**
	 * Fonction ToString de couleur
	 */
	@Override
	public String toString() {
		return "Couleur [rouge="+_Rouge+", vert="+_Vert+", bleu="+_Bleu+"]";
	}
}
