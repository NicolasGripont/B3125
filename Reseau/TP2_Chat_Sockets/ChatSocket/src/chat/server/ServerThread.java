/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chat.server;

import chat.protocol.Message;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 *
 * @author Nico
 */
public class ServerThread extends Thread {
    /**
     * Référence sur le serveur.
     */
    private final Server server;
    
    /**
     * Réference sur la socket de communication.
     */
    private final Socket clientSocket;
    
    /**
     * Référence sur le thread parent. 
     */
    private final ServerMultiThread serverMultiThread;
    
    /**
     * Flux d'écriture de message.
     */
    PrintStream socOut;
    
    /**
     * Flux de lecture de message.
     */
    BufferedReader socIn;
    
    /**
     * Nom de l'utilisateur relié.
     */
    private String userName;

    /**
     * COnstructeur.
     * @param s Référence sur le serveur.
     * @param smt Référence sur le thread parent.
     * @param c Socket de communication.
     */
    public ServerThread(Server s,ServerMultiThread smt, Socket c) {
        server = s;
        clientSocket = c;
        serverMultiThread = smt;
        try {
            socIn = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            socOut = new PrintStream(clientSocket.getOutputStream());
        } catch (Exception e) {
            System.err.println("ServerThread  exception : " + e.toString()); 
        } 
    }
    
    /**
     * Getter. 
     * @return Nom de l'utilisateur.
     */
    public String getUserName() {
        return userName;
    }
    
    /**
     * Méthode exécutée par le thread. Lit les messages provenant du client et la traite.
     */
    @Override
    public void run(){
        try {
            String line;
            while (server.isRunning()) {
                line = socIn.readLine();
                treatLine(line);
            }
    	} catch (Exception e) {
            System.err.println("ServerThread  exception : " + e.toString()); 
        } 
    }
    
    /**
     * Méthode d'intéruption du thread. Deconnecte l'utilisateur en lui envoyant un message de deconnexion et ferme la sockets.
     */
    @Override
    public void interrupt() {
        super.interrupt();
        try {
            sendMessage("SIGNOUT "+userName);
            socOut.close();
            socIn.close();
            clientSocket.close();
        } catch (Exception e) {
            System.err.println("Client exception : "+ e.toString());
            System.exit(1);
        }
    }
    
    /**
     * Methode traitant une ligne recue par le flux d'entrée "socIn".
     * @param line Ligne lu.
     */
    private void treatLine(String line){        
        if(line.contains("CONNECT")) {
            String[] splits = line.split("CONNECT ");
            userName = splits[1];
            serverMultiThread.signin(this);
        } else if(line.compareTo("QUIT")==0) {
            serverMultiThread.signout(this);
        } else if(line.contains("SENDTO") && line.contains("CONTENT")) {
            String[] splits1 = line.split("SENDTO ");
            String[] splits2 = splits1[1].split(" CONTENT ");
            String sender = userName;
            String receiver = splits2[0];
            String textMessage = "MESSAGE FROM " + sender + " TO " + receiver + " CONTENT " + splits2[1];
            serverMultiThread.sendMessage(new Message(sender,receiver,textMessage));
        }
    }
    
    /**
     * Méthode permettant d'envoyer un message au client.
     * @param m
     */
    public void sendMessage(String m) {
        try{
            socOut.println(m);
        } catch (Exception e) {
            System.err.println("ServerThread  exception : " + e.toString()); 
        } 
    }
}
