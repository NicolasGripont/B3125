/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chat.client;

import chat.protocol.Message;
import java.io.BufferedReader;



/**
 * Thread client d'écoute de socket.
 * @author Nico
 */
public class ClientThread extends Thread{
    /**
     * Réference sur le client correspondant.
     */
    Client client;
    
    /**
    * Flux de lecture de message.
    */
    BufferedReader socIn;
    
    /**
     * Constructeur.
     * @param c Réference sur le client correspondant.
     * @param br Flux de lecture de message.
     */
    public ClientThread(Client c,BufferedReader br) {
        client = c;
        socIn = br;
    }
    
    /**
     * Méthode exécutée par le thread. Lit les messages provenant du serveur et en notifie le "client".
     * Traite les lignes que le BufferReader socIn (de la socket) reçoit du serveur et analyse ce qu'elle reçoit et fait le traitement approprié selon si c'est un message informatif(quelqu'un s'est connecté ou deconnecté) ou un message d'un client.
     */
    @Override
    public void run(){        
        try {
            String line;
            while (true) {
                line = socIn.readLine();
                treatLine(line);
            }
        } catch (Exception e) {
            System.err.println("ClientThread exception : " + e.toString());
        }
    }
    
    /**
     * Methode traitant uns ligne recus par le flux d'entrée "socIn".
     * @param line Ligne lu.
     */
    private void treatLine(String line){        
        if(line.contains("SIGNIN")) {
            String[] splits = line.split("SIGNIN ");
            client.newUserConnected(splits[1]);
        } else if(line.contains("SIGNOUT")) {
            String[] splits = line.split("SIGNOUT ");
            client.userDisconnected(splits[1]);
        } else if(line.contains("MESSAGE FROM") && line.contains("TO") && line.contains("CONTENT")) {
            String[] splits1 = line.split("MESSAGE FROM ");
            String[] splits2 = splits1[1].split(" TO ");
            String[] splits3 = splits2[1].split(" CONTENT ");
            String sender = splits2[0];
            String receiver = splits3[0];
            String textMessage = splits3[1];
            client.displayMessage(new Message(sender,receiver,textMessage));
        }
    }
}
