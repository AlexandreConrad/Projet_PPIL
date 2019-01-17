package fr.conrad.ppil.serveur.liste_expert;

public class Point {
	
	private float x;
	private float y;
	
	public Point(float x , float y) {
		this.setX(x);
		this.setY(y);
	}
	
	
	/*Setters*/
	private void setX(float px) {
		x = px;
	}
	
	private void setY(float py) {
		y = py;
	}
	
	/*Getters*/
	
	public float getX() {
		return x;
	}
	
	public float getY() {
		return y;
	}
}
