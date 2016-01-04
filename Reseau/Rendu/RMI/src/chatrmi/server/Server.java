/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatrmi.server;

import chatrmi.protocol.ClientInterface;
import chatrmi.protocol.Message;
import chatrmi.protocol.MessageInterface;
import chatrmi.protocol.ServerInterface;
import java.io.File;
import static java.lang.System.exit;
import java.net.InetAddress;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.LinkedList;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;


/**
 * Classe permettant de créer un objet Remote de type server pour un server de chat
 * Implémente l'interface Remote "ServerInterface"
 * @author Nico
 */
public class Server implements ServerInterface {
    
    /**
     * Nom du serveur.
     */
    private String serverName;
    
    /**
     * Port de communication.
     */
    private int serverPort;
    
    /**
     * Chemin d'accès du fichier contenant l'historique des messages.
     */
    private String historicsFile;
    
    /**
     * Registre remote.
     */
    private Registry registry;
    
    /**
     * Etat du serveur. (Allumé : true, éteind : false).
     */
    private boolean state;
    
    /**
     * Liste des clients connectés.
     */
    private LinkedList<ClientInterface> clients;
    
    /**
     * Historiques de messages.
     */
    private LinkedList<MessageInterface> messages;
    
    /**
     * Vue serveur.
     */
    private ServerRunningView serverRunningView;
    
    /**
     * Constructeur. Initialise le nom du serveur à "server", le port de communication à 1099 et le fichier d'historique à "historics.xml".
     */
    public Server() {
       initialize("server",1099,"historics.xml");
    }
    
    /**
     * Permet d'initiliser les attributs.
     * @param sName Nom du serveur.
     * @param sPort Port de communication.
     * @param hFile Chemin d'accès du fichier d'historique.
     */
    private void initialize(String sName, int sPort, String hFile) {
        serverName = sName;
        serverPort = sPort;
        historicsFile = hFile;
        state = false;
        clients = new LinkedList<>();
        messages = new LinkedList<>();
        serverRunningView = new ServerRunningView(this);
        serverRunningView.setLocationRelativeTo(null);
        serverRunningView.setVisible(true);
        loadHistorics();
        try
        {
            UnicastRemoteObject.exportObject(this, 0);
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            exit(0);
        }
    }
        
    /**
     * Bind le serveur au registre Remote sur le port "serverPort" et avec le nom "serverName".
     * @return True si réussi, false sinon.
     */
    private boolean run() {
        boolean result = true;
        try {
            LocateRegistry.createRegistry(serverPort);
        } catch (Exception e) {
            //System.err.println("Server exception: " + e.toString());
        } finally {
            try {
                registry = LocateRegistry.getRegistry();
                registry.bind(serverName, this);
            } catch (Exception e) {
                System.err.println("Server exception: " + e.toString());
                result = false;
            }
        }
        return result;
    }
    
    /**
     * Permer de lancer le serveur avec comme port de communication "port".
     * Modifie l'état du serveur si reussi ou non (valeur retournée).
     * @param port Port de communication.
     * @return True si réussi, false sinon.
     */
    public boolean start(String port)
    {
        try
        {
            serverPort = Integer.parseInt(port);
            state = run();
            serverRunningView.diplayServerLocalAdress(InetAddress.getLocalHost().getHostAddress());
        }
        catch(Exception e)
        {
            System.err.println("Server exception: " + e.toString());
        }
        return state;
    }
        
    /**
     * Permet de stopper le serveur. 
     * Modifie l'état du serveur.
     * @return True si réussi, false sinon.
     */
    public boolean stop()
    {
        try {
            
            registry.unbind(serverName);
            state = false;
            
            for (ClientInterface c1 : clients) {
                c1.userDisconnected(c1);
            }

            clients.removeAll(clients);
            serverRunningView.setClientNumber(clients.size());
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
        }
        return !state;
    }
    
    /**
     * Méthode permettant de savoir si le serveur est en train de tourner ou non.
     * @return True si le serveur est en train de tourner, false sinon.
     */
    public Boolean isRunning() {
        return state;
    }
    
    /**
     * Methode permettant d'envoyer un message à tous les clients connectés au serveur.
     * Affiche le message envoyé au serveur par un client à tous les clients de la liste Clients et rajoute le message à la liste de Messages. 
     * @param m Message à envoyer.
     * @throws RemoteException
     */
    @Override
    public void sendMessageToAll(MessageInterface m) throws RemoteException {
        // TODO Auto-generated method stub
        Message msg = new Message(m.getDate(),m.getUserName(),m.getTextMessage());
        MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject
                    .exportObject(msg, 0);
        
        for (ClientInterface client : clients) {
            client.displayMessage(stubMsg);
        }
        messages.addLast(stubMsg);
    }

    /**
     * Methode permettant d'ajouter un nouveau client à liste de clients connectés.
     * Elle permet de rajouter le client qui souhaite se connecter au serveur afin qu'il bénéficie des services offert par celui-ci. Elle vérifie bien que le username choisi par le client n'est pas déjà utilisé. Elle le rajoute à la liste des Clients et lui affiche tous les messages existants dans la liste Messages. 
     * @param c Client
     * @return True si l'ajout a pu se faire, false sinon.
     * @throws RemoteException
     */
    @Override
    public boolean addClient(ClientInterface c) throws RemoteException {
        // TODO Auto-generated method stub
        Boolean result = true;
        if(c == null){
            result = false;
        } else if(contains(c)) {
            result = false;
            sendServerMessage(c, "Username \"" + c.getUserName() + "\" already used.");
        } else {
            sendServerMessageToAll(c.getUserName() + " has joined the chat.");
            
            for (ClientInterface client : clients) {
                c.newUserConnected(client);
            }
            
            clients.add(c);
            sendHistorics(c);
            
            for (ClientInterface client : clients) {
                client.newUserConnected(c);
            }
                        
            serverRunningView.setClientNumber(clients.size());
            result = true;
        }
        return result;
    }
    
    /**
     * Methode permettant d'enlever un client à liste de clients connectés. 
     * Le serveur informe tous les clients que l'utilisateur c a quitté le chat. Tous les clients affichent sur le interface graphique : « c has left ». le client c est supprimé de la liste Clients.
     * @param c Client.
     * @throws RemoteException
     */
    @Override
    public void deleteClient(ClientInterface c) throws RemoteException {
        // TODO Auto-generated method stub
          
        for (ClientInterface client : clients) {
            client.userDisconnected(c);
        }
        clients.remove(c);
        
        sendServerMessage(c, "You have left the chat.");
        sendServerMessageToAll(c.getUserName() + " has left the chat.");
        
        serverRunningView.setClientNumber(clients.size());
    }

    /**
     * Methode permettant de savoir si un client ayant le même non d'utilisateur que "client" est connecté.
     * @param client Client.
     * @return True si oui, false sinon.
     * @throws RemoteException 
     */
    private boolean contains(ClientInterface client) throws RemoteException
    {
        boolean result = false;
        for(ClientInterface c : clients){
            if ( client.getUserName().compareTo(c.getUserName()) == 0 ){
                result = true;
                break;
            }
        }
        return result;
    }
    
    /**
     * Methode permettant d'envoyer un message à tous les clients connectés au serveur.
     * Elle permet d'afficher à tous les clients connectés des messages informatifs qui viennent du serveur et non pas d'autres clients (exemple : informer de la connexion d'un nouveau client est un message du serveur).
     * @param m Message à envoyer.
     * @throws RemoteException
     */
    private void sendServerMessageToAll(String m) throws RemoteException {
        Message msg = new Message(new Date(),"Server",m);
        MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject
                    .exportObject(msg, 0);
        
        for (ClientInterface client : clients) {
            client.displayMessage(stubMsg);
        }
        messages.addLast(stubMsg); //Tout depend si on enregistre les messages du server
    }
    
    /**
     * Methode permettant d'envoyer un message à un client connecté au serveur.
     * @param c Client à qui envoyer le message.
     * @param m Message à envoyer.
     * @throws RemoteException
     */
    private void sendServerMessage(ClientInterface c,String m) throws RemoteException {
        Message msg = new Message(new Date(),"Server",m);
        MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject
                    .exportObject(msg, 0);
        
        c.displayMessage(stubMsg);
    }
    
    /**
     * Méthode permettant d'envoyer l'historique des messages à un client spécifique.
     * @param c Client à qui envoyer le message.
     * @throws RemoteException 
     */
    private void sendHistorics(ClientInterface c) throws RemoteException {
        for( MessageInterface m : messages)
        {
            c.displayMessage(m);
        }
    }
    
    /**
     * Methode permettant de charger l'historique des messages (provenant du fichier "historicsFile").
     * Tous les messages enregistrés dans le document XML sont ajoutés dans l'ordre chronologique à la liste "messages". Ils sont stubés pour pouvoir être envoyés aux différents clients qui se connecterons.
     */
    public void loadHistorics() {
        try {
            DateFormat formatter = new SimpleDateFormat("MM/dd/yy h:m:s");
            final DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            final DocumentBuilder builder = factory.newDocumentBuilder();

	    final Document document= builder.parse(new File(historicsFile));

	    final Element racine = document.getDocumentElement();
	    final NodeList racineNoeuds = racine.getElementsByTagName("Message");
	    final int nbRacineNoeuds = racineNoeuds.getLength();
            System.out.println(nbRacineNoeuds);
            
	    for (int i = 0; i<nbRacineNoeuds; i++) {
                System.out.println(i);
	        final Element message = (Element) racineNoeuds.item(i);

                final Element date = (Element) message.getElementsByTagName("Date").item(0);
                final Element username = (Element) message.getElementsByTagName("Username").item(0);
                final Element text = (Element) message.getElementsByTagName("Text").item(0);

                Message msg = new Message(formatter.parse(date.getTextContent()),username.getTextContent(),text.getTextContent());
                MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject.exportObject(msg, 0);

                messages.addLast(stubMsg);
	        			
	    }	

        } catch(Exception e) {
            
        }
    }
    
    /**
     * Methode permettant d'enregistrer l'historique des messages (dans le fichier "historicsFile").
     * Tous les messages enregistrés dans la liste "messages" sont stockés à la suite dans un document XML avec précision de la date ainsi que le nom d'utilisateur pour chaque message dans l'ordre d'ajout à la liste.
     */
    public void saveHistorics() {
        try {
            DateFormat formatter = new SimpleDateFormat("MM/dd/yy h:m:s");
            final DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
	    final DocumentBuilder builder = factory.newDocumentBuilder();
	    final Document document= builder.newDocument();
	    final Element racine = document.createElement("Messages");
	    document.appendChild(racine);			
			
            for(MessageInterface m : messages){
                final Element message = document.createElement("Message");
                racine.appendChild(message);

                final Element date = document.createElement("Date");

                date.appendChild(document.createTextNode(formatter.format(m.getDate())));

                final Element username = document.createElement("Username");
                username.appendChild(document.createTextNode(m.getUserName()));

                final Element text = document.createElement("Text");
                text.appendChild(document.createTextNode(m.getTextMessage()));

                message.appendChild(date);
                message.appendChild(username);
                message.appendChild(text);
            }	    						
	
	    final TransformerFactory transformerFactory = TransformerFactory.newInstance();
	    final Transformer transformer = transformerFactory.newTransformer();
	    final DOMSource source = new DOMSource(document);
	    final StreamResult sortie = new StreamResult(new File(historicsFile));

	    transformer.setOutputProperty(OutputKeys.VERSION, "1.0");
	    transformer.setOutputProperty(OutputKeys.ENCODING, "UTF-8");
	    transformer.setOutputProperty(OutputKeys.STANDALONE, "yes");			

	    transformer.setOutputProperty(OutputKeys.INDENT, "yes");
	    transformer.setOutputProperty("{http://xml.apache.org/xslt}indent-amount", "2");

	    transformer.transform(source, sortie);	
        } catch(Exception e) {
            
        }
    }

}



            		

