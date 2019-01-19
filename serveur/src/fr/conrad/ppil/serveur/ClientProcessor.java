package fr.conrad.ppil.serveur;

import java.io.BufferedInputStream;
import java.net.Socket;

import fr.conrad.ppil.serveur.dessinateur.Dessinateur;
import fr.conrad.ppil.serveur.formes.Forme;
import fr.conrad.ppil.serveur.liste_expert.ChargeurForme;

/**
 * Client avec Mutli Thread 
 * @author alexandre
 *
 */
public class ClientProcessor implements Runnable {
	
	/**
	 * Données membres
	 */
	private Socket _Socket;
	private ChargeurForme _ChargeurForme;
	private Dessinateur _Dessinateur;
	
	/**
	 * Constructeur qui prend 3 paramètres.
	 * @param socket
	 * @param chargeurForme
	 * @param dessinateur
	 */
	public ClientProcessor(Socket socket, ChargeurForme chargeurForme, Dessinateur dessinateur) {
		_Socket = socket;
		_ChargeurForme = chargeurForme;
		_Dessinateur = dessinateur;
	}

	/**
	 * Procèdure run qui est lancé par le .start
	 */
	@Override
	public void run() {
		try {
			/* Ce qu'on revois , on le mets dans un tanpom */
			BufferedInputStream bufferedInputStream = new BufferedInputStream(_Socket.getInputStream());
		    int taille;
		    byte[] tabByte = new byte[4096];
		    
		    /* On lit l'information et on la mets dans "b" , avec stream qui est égale aux nombres de caractère lu */
		    taille = bufferedInputStream.read(tabByte);
		    String messageForme = new String(tabByte, 0, taille);
		    
		    /* On affiche l'information */
		    System.out.println(messageForme);
		    
		    /* Découpage */
		    String[] messageFormes = messageForme.split(";");
		    
		    /* Parcours de chaque information dans le chargeur de forme */
		    for ( String message : messageFormes ) {
		    	if ( message.length() > 0 ) {
		    		Forme forme = _ChargeurForme.traiter(message);
		    		forme.dessiner(_Dessinateur);
		    	}
		    }
			
			_Socket.close();
		} catch ( Exception e ) {
			/*Retourner le message d'erreur*/
			e.printStackTrace();
		}
	}

}
