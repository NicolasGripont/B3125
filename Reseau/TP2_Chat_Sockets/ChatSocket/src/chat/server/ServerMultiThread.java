/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chat.server;

import chat.protocol.Message;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;

/**
* Thread d'écoute permettant la connexion d'utilisateurs et de transmettre les messages à tous les utilisateurs.
 * @author Nico
 */
public class ServerMultiThread extends Thread {
    
    private Server server;
    ServerSocket listenSocket;
    private LinkedList<ServerThread> serverThreads;

    /**
     * Constructeur.
     * @param s Reference sur le serveur.
     */
    public ServerMultiThread(Server s) {
        server = s;
        serverThreads = new LinkedList<>();
        try{
            listenSocket = new ServerSocket(server.getServerPort());
        } catch(Exception e) {
            System.err.println("ServerMultiThread exception : " + e.toString());
        }
    }
    
    /**
     * Getter.
     * @return Nombre d'utilisateurs connectés.
     */
    public int getClientsNumber() {
        return serverThreads.size();
    }
    
    /**
     * Méthode exécutée par le thread. Attend la connexion d'utilisateur et créer un ServerThread à la connexion d'un utilisateur.
     */
    public void run(){        
        try {
            while (server.isRunning()) {
                Socket clientSocket = listenSocket.accept();
               
                ServerThread serverThread = new ServerThread(server,this,clientSocket);
                serverThread.start();
            }
        } catch (Exception e) {
            System.err.println("ServerMultiThread exception : " + e.toString());
        }
    }
    
    /**
     * Méthode d'intéruption du thread. Ferme la socket d'écoute et arrête les threads d'écoute côté serveur de chaque utilisateurs.
     */
    @Override
    public void interrupt(){
        try {
            super.interrupt();
            listenSocket.close();
            for(ServerThread st : serverThreads) {
                st.interrupt();
            }
            serverThreads.removeAll(serverThreads);
        } catch (Exception e) {
            System.err.println("ServerMultiThread exception : " + e.toString());
        }
    }
    
    /**
     * Methode permettan d'envoyer un message.
     * @param m Message.
     */
    public void sendMessage(Message m) {
        if (m.getReceiver().compareTo("all") == 0) {
            for(ServerThread st : serverThreads) {
                st.sendMessage(m.getTextMessage());
            }
        } else {
            for(ServerThread st : serverThreads) {
                if(st.getUserName().compareTo(m.getReceiver())==0 || st.getUserName().compareTo(m.getSender())==0) {
                    st.sendMessage(m.getTextMessage());
                }
            }
        }
    }
    
    /**
     * Methode permettant de notifier la connexion d'un utilisateur.
     * @param st Thread d'écoute côté serveur de l'utilisateur qui se déconnecte.
     */
    public void signin(ServerThread st) {
        Message message;
        String text;
        if(server.getServerName().compareTo(st.getUserName()) == 0 || contains(st.getUserName())){
            text = "SIGNOUT ";
            text += st.getUserName();
            st.sendMessage(text);
            st.interrupt();
        } else {
            //On informe au nouveau client que la connexion est acceptée
            text = "SIGNIN ";
            text += st.getUserName();
            st.sendMessage(text);
            
            //On envoie la liste des utilisateurs deja connecté au client
            for (ServerThread s : serverThreads) {
                text = "SIGNIN ";
                text += s.getUserName();
                st.sendMessage(text);
            }
           
            
            serverThreads.add(st);
            
            //On informe tous utilisateurs de la connexion d'un nouveau client
            text = "SIGNIN ";
            text += st.getUserName();
            message = new Message(server.getServerName(),"all",text);
            sendMessage(message);

            server.refreshClientsNumber();
        }
    }
    
    /**
     * Methode permettant de notifier la déconnexion d'un utilisateur.
     * @param st Thread d'écoute côté serveur de l'utilisateur qui se déconnecte.
     */
    public void signout(ServerThread st) {
        String text;
        text = "SIGNOUT ";
        text += st.getUserName();
        Message message = new Message(server.getServerName(), "all", text);
        sendMessage(message);
        st.interrupt();
        serverThreads.remove(st);
        server.refreshClientsNumber();
    }
    
    /**
     * Getter permettant de recuperer le thread d'écoute côté serveur de l'utilisateur ayant le nom "username".
     * @param username Nom de l'utilisateur.
     * @return Thread d'écoute côté serveur du client ayant le nom "username".
     */
    public ServerThread getServerThread(String username) {
        ServerThread st = null;
        for(ServerThread s : serverThreads) {
            if (username.compareTo(s.getUserName())==0) {
                st = s;
                break;
            }
        }
        return st;
    }
    
    /**
     * Méthode permettant de savoir si un utilisateur ayant le nom d'utilisateur "username" est déjà connecté.
     * @param username Nom de l'utilisateur.
     * @return True si ouiu, false sinon.
     */
    public boolean contains(String username) {
        return getServerThread(username)!=null;
    }
    
}
