package fr.conrad.ppil.serveur.formes.formes_complexes;

import java.util.ArrayList;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.dessinateur.Dessinateur;
import fr.conrad.ppil.serveur.formes.Forme;

/**
 * Classe pour les formes compos�es
 * @author alexa
 *
 */
public class FormeComposee extends Forme {
	
	/**
	 * Donn�e membre , Liste de Formes
	 */
	private ArrayList<Forme> _Formes = new ArrayList<Forme>();

	/**
	 * Constructeur de forme Compos�e , il envoie � forme la couleur
	 * @param color
	 * @throws Exception
	 */
	public FormeComposee(Couleur color) throws Exception {
		super(color);
	}

	/* Getters */
	
	/**
	 * Retourne une des formes de la forme compos�e � la position i
	 * @param i
	 * @return
	 */
	public Forme getForme(int i) {
		return _Formes.get(i);
	}
	
	/**
	 * Retourne le nombre de forme de la FormeCompos�e
	 * @return
	 */
	public int getNbFormes() {
		return _Formes.size();
	}
	
	/* M�thodes */
	
	/**
	 * Ajout une forme � la liste de forme
	 * @param f
	 */
	public void ajouterForme(Forme f) {
		_Formes.add(f);
	}

	@Override
	public void dessiner(Dessinateur dessinateur) throws Exception {
		dessinateur.dessiner(this);
	}
	
}
