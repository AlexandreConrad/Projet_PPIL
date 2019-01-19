package fr.conrad.ppil.serveur.vecteur;

/**
 * Classe point qui permet de stocker les coordonnées x et y d'un point
 * @author alexandre
 *
 */
public class Point {
	

	/**
	 * Représente les coordonnées x et y d'un point
	 */
	private float _X;
	private float _Y;
	
	
	/**
	 * Constructeur d'un point
	 * @param x
	 * @param y
	 */
	public Point(float x , float y) {
		this.setX(x);
		this.setY(y);
	}
	
	
	/*Setters*/
	
	/**
	 * Initialise le x
	 * @param px
	 */
	private void setX(float px) {
		_X = px;
	}
	
	/**
	 * Initialise le Y
	 * @param py
	 */
	private void setY(float py) {
		_Y = py;
	}
	
	
	/*Getters*/
	
	/**
	 * Accésseur du X
	 * @return
	 */
	public float getX() {
		return _X;
	}
	
	/**
	 * Accésseur du Y
	 * @return
	 */
	public float getY() {
		return _Y;
	}
}