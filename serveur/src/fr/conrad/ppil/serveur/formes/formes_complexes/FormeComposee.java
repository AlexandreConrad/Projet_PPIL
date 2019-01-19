package fr.conrad.ppil.serveur.formes.formes_complexes;

import java.util.ArrayList;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.dessinateur.Dessinateur;
import fr.conrad.ppil.serveur.formes.Forme;

/**
 * Classe pour les formes composées
 * @author alexa
 *
 */
public class FormeComposee extends Forme {
	
	/**
	 * Donnée membre , Liste de Formes
	 */
	private ArrayList<Forme> _Formes = new ArrayList<Forme>();

	/**
	 * Constructeur de forme Composée , il envoie à forme la couleur
	 * @param color
	 * @throws Exception
	 */
	public FormeComposee(Couleur color) throws Exception {
		super(color);
	}

	/* Getters */
	
	/**
	 * Retourne une des formes de la forme composée à la position i
	 * @param i
	 * @return
	 */
	public Forme getForme(int i) {
		return _Formes.get(i);
	}
	
	/**
	 * Retourne le nombre de forme de la FormeComposée
	 * @return
	 */
	public int getNbFormes() {
		return _Formes.size();
	}
	
	/* Méthodes */
	
	/**
	 * Ajout une forme à la liste de forme
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
