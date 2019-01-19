package fr.conrad.ppil.serveur.formes.formes_simple;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.dessinateur.Dessinateur;
import fr.conrad.ppil.serveur.formes.Forme;
import fr.conrad.ppil.serveur.vecteur.Point;

/**
 * Forme géométrique en forme de Segment ,  elle dois disposer de seulement deux points
 * @author alexandre
 *
 */
public class Segment extends Forme{

	/**
	 * Constructeur du segment, envoie au père la couleur
	 * @param couleur
	 * @param x1
	 * @param x2
	 * @throws Exception
	 */
	public Segment(Couleur couleur,Point x1 , Point x2) throws Exception {
		
		/* Appel du constructeur du père car elle est abstraite */
		super(couleur);
		
		/* Ajout des points du segment */
		this.addPoint(x1);
		this.addPoint(x2);
	}

	@Override
	public void dessiner(Dessinateur dessinateur) throws Exception {
		// TODO Auto-generated method stub
		dessinateur.dessiner(this);
	}
}
