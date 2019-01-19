package fr.conrad.ppil.serveur.formes.formes_simple;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.dessinateur.Dessinateur;
import fr.conrad.ppil.serveur.formes.Forme;
import fr.conrad.ppil.serveur.vecteur.Point;

/**
 * Forme géométrique en forme de cercle
 * @author alexandre
 *
 */
public class Cercle extends Forme{

	/**
	 * Représente le rayon du cercle , dois être supérieur à >= à 0
	 */
	private float _Rayon;
	
	/**
	 * Constructeur du cercle
	 * @param couleurCercle
	 * @param rayon
	 * @param centre
	 * @throws Exception
	 */
	public Cercle(Couleur couleurCercle, float rayon,Point centre) throws Exception {
		
		/* Appel du constructeur père , car c'est une classe abstraite */
		super(couleurCercle);
		
		/* Ajout du centre */
		this.addPoint(centre);
		
		/* Ajout du rayon */
		this.setRayon(rayon);
	
	}

	/*Getter*/
	
	/**
	 * Retourne le rayon du cercle
	 * @return
	 */
	public float getRayon() {
		return _Rayon;
	}
	
	
	/*Setter*/
	
	/**
	 * Initialisation du rayon
	 * retourne une erreur s'il est inférieur à 0
	 * @param rayon
	 * @throws Exception
	 */
	private void setRayon(float rayon) throws Exception {
		if ( rayon < 0 )
			throw new FormeException("Le rayon du cercle est invalide ( doit être >= à 0 )");
		_Rayon = rayon;
	}

	@Override
	public void dessiner(Dessinateur dessinateur) throws Exception {
		dessinateur.dessiner(this);
	}
}
