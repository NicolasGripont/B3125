/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chat.server;

import java.net.InetAddress;

/**
 * Classe representant un serveur d'un chat utilisant les sockets.
 * @author Nico
 */
public class Server {
    
    /**
     * Nom du serveur.
     */
    private String serverName;
    
    /**
     * Port de communication.
     */
    private int serverPort;
    
    /**
     * Etat du serveur. True : connecté, false sinon.
     */
    private boolean state;
    
    /**
     * Thread d'écoute permettant la connexion d'utilisateurs et de transmettre les messages à tous les utilisateurs.
     */
    private ServerMultiThread serverMultiThread;
    
    /**
     * Vue du serveur.
     */
    private ServerRunningView serverRunningView;
    
    /**
     * Constructeur.
     */
    public Server() {
       initialize("server",1099);
    }
    
    /**
     * Getter. 
     * @return Port de communication.
     */
    public int getServerPort() {
        return serverPort;
    }
   
    /**
     * Getter.
     * @return Nom du serveur.
     */
    public String getServerName() {
        return serverName;
    }
    
    /**
     * Methode permettant d'initialiser le serveur.
     * @param sName Nom du serveur.
     * @param sPort Port de communication.
     */
    private void initialize(String sName, int sPort) {
        serverName = sName;
        serverPort = sPort;
        state = false;
        serverMultiThread = null;
        serverRunningView = new ServerRunningView(this);
        serverRunningView.setLocationRelativeTo(null);
        serverRunningView.setVisible(true);
    }
    
    /**
     * Methode permettant de lancer le serveur.
     * @param port
     */
    public void start(String port)
    {
        try {
            serverPort = Integer.parseInt(port);
            state = true;
            serverMultiThread = new ServerMultiThread(this);
            serverMultiThread.start();
            serverRunningView.diplayServerLocalAdress(InetAddress.getLocalHost().getHostAddress());

        } catch (Exception e) {
            System.err.println("Server exception : " + e.toString());
        }
    }
        
    /**
     * Methode permettant d'arreter le serveur.
     */
    public void stop() {
        state = false;
        if (serverMultiThread!=null) {
            serverMultiThread.interrupt();
        }
        refreshClientsNumber();
    }
    
    /**
     * Methode permettant de raffraichir le nombre de client sur la vue.
     */
    public void refreshClientsNumber() {
        if(serverMultiThread!=null) {
            serverRunningView.setClientNumber(serverMultiThread.getClientsNumber());
        } else {
            serverRunningView.setClientNumber(0);
        }
    }
    
    /**
     * Methode permettant de savoir si le serveur est en train de tourner.
     * @return True si oui, false sinon.
     */
    public boolean isRunning() {
        return state;
    }

}
