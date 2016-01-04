package chat.client;

import chat.protocol.Message;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * Classe representant un client d'un chat utilisant les sockets.
 * @author Nico
 */
public class Client{
    /**
     * Etat du client, connecté : true, Déconnecté : false.
     */
    boolean state;

    /**
     * Adresse du serveur.
     */
    protected String serverAdress;

    /**
     * Port de communication.
     */
    protected int serverPort;

    /**
     * Nom d'utilisateur.
     */
    protected String userName;
    
    /**
     * Vue du client.
     */
    ClientChatView clientChatView;
    
    /**
     * Socket de communication.
     */
    Socket socket;
    
    /**
     * Flux d'écriture de message.
     */
    PrintStream socOut;
    
    /**
     * Flux de lecture de message.
     */
    BufferedReader socIn;
    
    /**
     * Thread de lecture du client.
     */
    ClientThread clientThread;

    /**
     * Constructeur.
     */
    public Client() {
        try {
            state = false;
            clientChatView = new ClientChatView(this);  
            serverAdress = null;
            socket = null;
            socIn = null;
            socOut = null;
            serverPort = 1099;  
            clientChatView.setVisible(true);
        } catch (Exception e) {
            System.err.println("Client exception : " + e.toString());
        }
    }

    /**
     * Getter.
     * @return Non d'utilisateur.
     */
    public String getUserName() {
        return userName;
    }
    
    /**
     * Getter.
     * @return Adresse du serveur.
     */
    public String getServerAdress() {
        return serverAdress;
    }
    
    /**
     * Getter.
     * @return Port de communication.
     */
    public int getServerPort() {
        return serverPort;
    }
    
    /**
     * Setter.
     * @param name Nom d'utilisateur.
     */
    public void setUserName(String name) {
        userName = name;
    }
    
    /**
     * Setter.
     * @param adress Adresse du serveur.
     */
    public void setServerAdress(String adress) {
        serverAdress = adress;
    }
    
    /**
     * Setter.
     * @param port Port de communication.
     */
    public void setServerPort(int port) {
        serverPort = port;
    }
    
    /**
     * Methode permettant d'afficher un message sur la vue.
     * @param m Message.
     */
    public void displayMessage(Message m){
        clientChatView.displayMessage(m);
    }
    
    /**
     * Methode permettant d'afficher un message sur la vue.
     * @param m Message.
     */
    public void displayMessage(String m){
        clientChatView.displayMessage(m);
    }
    
    /**
     * Methode notifiant la connexion d'un autre utilisateur.
     * Ajoute le nom du client à la vue
     * @param client Client
     */
    public void newUserConnected(String client) {
        clientChatView.addUser(client);
        displayMessage(new Message("server","all",client+" signed in ..."));
    }
    
    /**
     * Methode notifiant la déconnexion d'un autre utilisateur.
     * Enlève le nom du client à la vue
     * @param client Client
     */
    public void userDisconnected(String client) {
        clientChatView.removeUser(client);
        if(client.compareTo(userName)==0) {
            clientThread.interrupt();
            try {
                socOut.close();
                socIn.close();
                socket.close();
            } catch (Exception e) {
                System.err.println("Client exception : "+ e.toString());
                System.exit(1);
            }
            clientThread = null;
            state = false;
            clientChatView.refresh();
        } else {
            displayMessage(new Message("server","all",client+" signed in ..."));
        }
    }
    
    /**
     * Methode permettant d'envoyer un message au serveur et qui serra retransmi au "receiver". 
     * @param receiver Destinataire. ("all" si destiné à tous les utilisateurs)
     * @param m Texte du message.
     */
    public void sendMessage(String receiver,String m) { 
        socOut.println("SENDTO " + receiver + " CONTENT " + m);
    }
        
    /**
     * Methode permettant de se connecter au serveur. Créer un ClientThread permettant la recepetion de messages.
     * @param sAdress Adresse du serveur.
     * @param sPort Port de communication.
     * @param name Nom de l'utilsateur.
     * @return Retourne true si reussi, false sinon.
     */
    public boolean connect(String sAdress, String sPort, String name) {
        try {
//            serverAdress = sAdress;
            state = false;
            userName = name;
            serverPort = Integer.parseInt(sPort);//gerer exception
            
      	    socket = new Socket(serverAdress,serverPort);
	    socIn = new BufferedReader(new InputStreamReader(socket.getInputStream()));    
	    socOut= new PrintStream(socket.getOutputStream());

            socOut.println("CONNECT " + userName);
            String line = socIn.readLine();
            if(line.contains("SIGNOUT")) {
                displayMessage(new Message("server",userName,"username \"" + userName + "\" already used."));
            } else {
                clientThread = new ClientThread(this, socIn);
                clientThread.start();
                state = true;
                clientChatView.refresh();
            }
        } catch (UnknownHostException e) {
            displayMessage("Don't know about host:" + serverAdress);
            System.err.println();
        } catch (IOException e) {
            displayMessage("Client exception : Couldn't get I/O for "
                               + "the connection to:"+ serverAdress);
        }
                
        return state;
    }

    /**
     * Methode permettant de se deconnecter du serveur.
     */
    public void disconnect() {
        try {
            socOut.println("QUIT");
        } catch (Exception e) {
            displayMessage("Client exception : "+ e.toString());
        }
    }

    /**
     * Methode permettant de savoir si le client est connecté à un serveur.
     * @return True si oui, false sinon.
     */
    public Boolean isConnected() {
        return state;
    }
}
