package fr.conrad.ppil.serveur.formes;

import java.util.ArrayList;

import fr.conrad.ppil.serveur.couleurs.Couleur;
import fr.conrad.ppil.serveur.dessinateur.Dessinateur;
import fr.conrad.ppil.serveur.vecteur.Point;

/**
 * Classe de Forme
 * @author alexa
 *
 */
public abstract class Forme {
	
	/**
	 * Donn�es membres 
	 * La couleur de la forme 
	 * Liste de Points pour la forme
	 */
	private Couleur _CouleurFormeSimple;
	private ArrayList<Point> _ListePoints;
	
	/**
	 * Constructeur de Forme qui prend en unique param�tre une couleur
	 * @param color
	 * @throws Exception
	 */
	public Forme(Couleur color) throws Exception {
		this.setCouleur(color);
		_ListePoints = new ArrayList<Point>();
	}
	
	/*Setters*/
	
	/**
	 * Ajouts de la couleur
	 * @param color
	 */
	private void setCouleur(Couleur color) {
		_CouleurFormeSimple = color;
	}
	
	
	/*Getter*/
	
	/**
	 * R�cup�re la classe couleur de la forme
	 * @return
	 */
	public Couleur getCouleurFormeSimple() {
		return _CouleurFormeSimple;
	}
	
	/**
	 * R�cup�re la taille du tableau de points
	 * @return
	 */
	public int getTailleTab() {
		return _ListePoints.size();
	}
	
	/*M�thodes*/
	
	/**
	 * Ajout de points � notre polygone
	 * @param p
	 */
	public void addPoint(Point p) {
		_ListePoints.add(p);
	}
	
	/**
	 * R�cup�re le points d'un polygone � un certains points
	 * @param position
	 * @return
	 */
	public Point getElement(int position) {
		return _ListePoints.get(position);
	}
	
	/**
	 * Affiche avec un d�ssinateur. Appelle la proc�dure afficher du fils
	 * @param dessinateur
	 * @throws Exception
	 */
	public abstract void dessiner(Dessinateur dessinateur) throws Exception;

}
