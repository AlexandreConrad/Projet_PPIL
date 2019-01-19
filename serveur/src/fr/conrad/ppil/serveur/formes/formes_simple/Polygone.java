package fr.conrad.ppil.serveur.formes.formes_simple;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.dessinateur.Dessinateur;
import fr.conrad.ppil.serveur.formes.Forme;

/**
 * Forme géométrique en forme de Polygone , n'importe quel forme qui dispose de plus de 3 points
 * @author alexandre
 *
 */
public class Polygone extends Forme{
	
	/**
	 * Constructeur du polygone, envoie au père la couleur
	 * @param couleurPolygone
	 * @throws Exception
	 */
	public Polygone(Couleur couleurPolygone) throws Exception {
		super(couleurPolygone);
	}

	@Override
	public void dessiner(Dessinateur dessinateur) throws Exception {
		// TODO Auto-generated method stub
		dessinateur.dessiner(this);
	}
	
}
