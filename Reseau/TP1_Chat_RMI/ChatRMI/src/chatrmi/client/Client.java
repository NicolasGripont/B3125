package chatrmi.client;

import chatrmi.protocol.ClientInterface;
import chatrmi.protocol.Message;
import chatrmi.protocol.MessageInterface;
import chatrmi.protocol.ServerInterface;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Date;

/**
 * Classe permettant de créer un objet Remote de type client pour un server de chat
 * Implémente l'interface Remote "ClientInterface"
 * @author Nico
 */
public class Client implements ClientInterface{
    
    /**
     * Adresse du serveur sur lequel le client est connecté
     */
    protected String serverAdress;
    
    /**
     * Port par lequel le client et le serveur communiquent
     */
    protected int serverPort;
    
    /**
     * Nom de l'utilisateur
     */
    protected String userName;
    
    /**
     * Reference sur le serveur (Remote) sur lequel on est connecté
     */
    ServerInterface server;
        
    /**
     * Reference sur la fenetre du client
     */
    ClientChatView clientChatView;

    /**
     * Constructeur
     */
    public Client() {
        try {
            clientChatView = new ClientChatView(this);  
            serverAdress = null;
            serverPort = 1099;  
            UnicastRemoteObject.exportObject(this, 0);
            clientChatView.setVisible(true);
        } catch (Exception e) {
            System.err.println("Client exception : " + e.toString());
                e.printStackTrace();
        }
    }

    /**
     * Getter
     * @return Le nom de l'utilisateur
     */
    @Override
    public String getUserName() {
        return userName;
    }
    
    /**
     * Getter
     * @return l'adresse du serveur
     */
    public String getServerAdress() {
        return serverAdress;
    }
    
    /**
     * Getter
     * @return le port 
     */
    public int getServerPort() {
        return serverPort;
    }
    
    /**
     * Setter
     * @param name nom de l'utilisateur
     */
    public void setUserName(String name) {
        userName = name;
    }
    
    /**
     * Setter
     * @param adress adress du serveur
     */
    public void setServerAdress(String adress) {
        serverAdress = adress;
    }
    
    /**
     * Setter
     * @param port port de communication
     */
    public void setServerPort(int port) {
        serverPort = port;
    }
    
    /**
     * Methode permettant d'afficher un message sur la vue
     * @param m message à afficher
     * @throws RemoteException 
     */
    @Override
    public void displayMessage(MessageInterface m) throws RemoteException {
        clientChatView.displayMessage(m);
    }
    
    /**
     * Methode notifiant la connexion d'un autre utilisateur.
     * Ajoute le nom du client à la vue
     * @param c Client
     * @throws RemoteException 
     */
    @Override
    public void newUserConnected(ClientInterface c) throws RemoteException {
        clientChatView.addUser(c);
    }
    
    /**
     * Methode notifiant la déconnexion d'un autre utilisateur.
     * Enlève le nom du client à la vue
     * @param c Client
     * @throws RemoteException 
     */
    @Override
    public void userDisconnected(ClientInterface c) throws RemoteException {
        if (c.getUserName().compareTo(userName)==0){
            server = null;
            clientChatView.refresh();
        }
        clientChatView.removeUser(c);
    }
    
    /**
     * Methode permettant d'envoyer un message à tous le client connecté au serveur
     * @param m texte du message
     */
    public void sendMessageToAll(String m) {
        try {
            Message msg = new Message(new Date(), userName, m);
            MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject.exportObject(msg, 0);
            server.sendMessageToAll(stubMsg);
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
        
    /**
     * Methode permettant de se connecter au serveur
     * @param sAdress adresse du serveur
     * @param sPort port de communication
     * @param name nom du client
     * @return 
     */
    public Boolean connect(String sAdress, String sPort, String name) {
        Boolean result = true;
        try {
            serverAdress = sAdress;
            userName = name;
            serverPort = Integer.parseInt(sPort);
            Registry registry = LocateRegistry.getRegistry(serverAdress,serverPort);
            server = (ServerInterface) registry.lookup("server");
            if(server != null && !server.addClient(this)) {
                server = null;
                result = false;
            }
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            server = null;
            result = false;
        }
        if (result){
            clientChatView.refresh();
        }
        return result;
    }

    /**
     * Methode permettant de se deconnecter du serveur
     */
    public void disconnect() {
        try {
            server.deleteClient(this);
            server = null;
            clientChatView.refresh();
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }

    /**
     * Methode permettant de savoir si le client est connecté a un serveur
     * @return Retourne true si connecté, false sinon
     */
    public Boolean isConnected() {
        return null != server;
    }
}
