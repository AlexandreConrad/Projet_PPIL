package fr.conrad.ppil.serveur.dessinateur;

import fr.conrad.ppil.serveur.formes.formes_complexes.FormeComposee;
import fr.conrad.ppil.serveur.formes.formes_simple.Cercle;
import fr.conrad.ppil.serveur.formes.formes_simple.Polygone;
import fr.conrad.ppil.serveur.formes.formes_simple.Segment;

/**
 * Interface avec le patern du visiteur
 * @author alexandre
 *
 */
public interface Dessinateur {
	
	void dessiner(Cercle forme) throws Exception;
	void dessiner(Polygone polygone) throws Exception;
	void dessiner(Segment segment) throws Exception;
	void dessiner(FormeComposee formeComposee) throws Exception;
}
