package fr.conrad.ppil.serveur.dessinateur;

import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferStrategy;

import fr.conrad.ppil.serveur.formes.formes_complexes.FormeComposee;
import fr.conrad.ppil.serveur.formes.formes_simple.Cercle;
import fr.conrad.ppil.serveur.formes.formes_simple.Polygone;
import fr.conrad.ppil.serveur.formes.formes_simple.Segment;

/**
 * Permet de dessiner 
 * @author alexandre
 *
 */
public class DessinateurAWT implements Dessinateur {
	
	/**
	 * Représente la stratégie du buffer de la fenêtre AWT
	 */
	private BufferStrategy strategie;
	/**
	 * Représente la composante graphique de la fenêtre AWT
	 */
	private Graphics graphics;
	
	/**
	 * Permet de créer la fenêtre AWT
	 * Lance une exception si le thread ne peut pas attendre 150 ms
	 * @throws Exception
	 */
	private void debutAffichage() throws Exception {
		
		/* Création de la fenêtre */
		Frame fenetre = new Frame("Affichage de votre forme");
	    
	    /*On donne les dimensions*/
	    fenetre.setBounds(250, 250, 500, 500);
	    
	    /*Rend la frame visible sur l'écran*/
	    fenetre.setVisible(true);
	    fenetre.setIgnoreRepaint(true);        // désactive l'appel automatique de la fct paint(...) par repaint()
	    
	    /*Permet de fermer la fenêtre*/
	    fenetre.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				fenetre.dispose();
			}

	    });
	    
	    int numBuffers = 1;
	    fenetre.createBufferStrategy(numBuffers);  // crée une stratégie de tampon d'image à 1 tampon vidéo
		Thread.sleep(150);// On laisse du temps pour  le buffert d'image    
	    
		strategie = fenetre.getBufferStrategy();
	    graphics = strategie.getDrawGraphics();        
	}
	
	/**
	 * Fin du code qui permet d'afficher une fenêtre
	 */
	private void finAffichage() {
	    strategie.show();       // place le tampon sur l'écran : la technique utilisée dépend du type de stratégie utilisé : blitting, pointeur vidéo, etc.
	    graphics.dispose();
	}

	@Override
	public void dessiner(Cercle cercle) throws Exception {		
		/*Procédure pour utilisé le début de code pour ouvrire une fenêtre*/
		this.debutAffichage();
	    
	    dessiner(cercle, graphics);
	    	
		/*Procédure fin de fenêtre*/
		this.finAffichage();
	}
	
	/**
	 * Procédure qui dessine un cercle grâce à dessiner.
	 * @param cercle
	 * @param graphics
	 * @throws Exception
	 */
	public void dessiner(Cercle cercle, Graphics graphics) throws Exception {		
	    /*Mettre la couleur sur la forme*/
	    graphics.setColor(new Color(cercle.getCouleurFormeSimple().getRouge(), cercle.getCouleurFormeSimple().getVert(), cercle.getCouleurFormeSimple().getBleu()));
	    
	    graphics.drawOval((int)cercle.getElement(0).getX(), (int)cercle.getElement(0).getY(), (int)cercle.getRayon(), (int)cercle.getRayon());
	}

	@Override
	public void dessiner(Polygone polygone) throws Exception {
		// TODO Auto-generated method stub
		this.debutAffichage();
		
		dessiner(polygone, graphics);
		
		this.finAffichage();
	}
	
	/**
	 * Procèdure qui affiche et dessine un Polygone
	 * @param polygone
	 * @param graphics
	 * @throws Exception
	 */
	public void dessiner(Polygone polygone, Graphics graphics) throws Exception {
		/*Récupération du nombres de points*/
	    int nbPoints = polygone.getTailleTab();
	    
	    /*Mettre la couleur sur la forme*/
	    graphics.setColor(new Color(polygone.getCouleurFormeSimple().getRouge(), polygone.getCouleurFormeSimple().getVert(), polygone.getCouleurFormeSimple().getBleu()));
	    
		/*Pour dessiner n'importe quel forme*/
		for(int i = 0 ; i < nbPoints ; i++) {
			if(nbPoints < i+2) {
				graphics.drawLine((int)polygone.getElement(i).getX(),(int)polygone.getElement(i).getY(),(int)polygone.getElement(0).getX(),(int)polygone.getElement(0).getY());
		    }else {
		    	graphics.drawLine((int)polygone.getElement(i).getX(),(int)polygone.getElement(i).getY(),(int)polygone.getElement(i+1).getX(),(int)polygone.getElement(i+1).getY());
		   	}	    	
		}
	}

	@Override
	public void dessiner(Segment segment) throws Exception {
		// TODO Auto-generated method stub
		this.debutAffichage();
		
		dessiner(segment, graphics);
		    	
		this.finAffichage();
	}
	

	/**
	 * Procèdure qui déssine un ségment
	 * @param segment
	 * @param graphics
	 * @throws Exception
	 */
	public void dessiner(Segment segment, Graphics graphics) throws Exception {
		
		/*Mettre la couleur sur la forme*/
		graphics.setColor(new Color(segment.getCouleurFormeSimple().getRouge(), segment.getCouleurFormeSimple().getVert(), segment.getCouleurFormeSimple().getBleu()));
	    
		/*Pour dessiner le segment*/
		graphics.drawLine((int)segment.getElement(0).getX(),(int)segment.getElement(0).getY(),(int)segment.getElement(1).getX(),(int)segment.getElement(1).getY());
	
	}

	/**
	 * Procèdure qui affiche une forme composée
	 */
	@Override
	public void dessiner(FormeComposee formeComposee) throws Exception {
		this.debutAffichage();
		
		/* Parcours de toutes les formes */
		for ( int i = 0; i < formeComposee.getNbFormes(); i++ ) {
			/*On test qu'elle forme c'est et on l'affiche*/
			if ( formeComposee.getForme(i) instanceof Cercle )
				dessiner((Cercle)formeComposee.getForme(i), graphics);
			
			if ( formeComposee.getForme(i) instanceof Polygone )
				dessiner((Polygone)formeComposee.getForme(i), graphics);
			
			if ( formeComposee.getForme(i) instanceof Segment )
				dessiner((Segment)formeComposee.getForme(i), graphics);
		}
		
		this.finAffichage();
	}

}