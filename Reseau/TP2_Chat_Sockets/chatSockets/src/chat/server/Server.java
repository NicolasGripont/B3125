package chat.server;

import chat.Message;
import chat.client.Client;


import java.util.*;

public class Server {

    public static void main(String[] args) {
        Server server = new Server();
    }

    private String serverName;
    private int serverPort;
    private LinkedList<Client> clients;
    private LinkedList<Message> messages;

    public Server(String sName, int sPort) {
       initialize(sName,sPort);
    }
    
    public Server(int sPort) {
       initialize(null,sPort);
    }
    
    public Server() {
       initialize(null,1099);
    }
    
    private void initialize(String sName, int sPort) {
        serverName = sName;
        serverPort = sPort;
        clients = new LinkedList<>();
        messages = new LinkedList<>();

        try {

            System.err.println("Server ready.");
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }

    public void sendMessage(Message m) {
        // TODO Auto-generated method stub
        for (Client client : clients) {
            client.displayMessage(m);
        }
        messages.addLast(m);
    }

    public Boolean addClient(Client c) {
        // TODO Auto-generated method stub
        Boolean result = false;
        if (c != null){
            
            Boolean nameAlreadyUsed = false;
            
            if (c.getUserName().compareTo("Server") == 0){
                nameAlreadyUsed = true;
            }
            for (Client client : clients){
                if(client.getUserName().compareTo(c.getUserName()) == 0){
                    nameAlreadyUsed = true;
                }
            }
                  
            if(!nameAlreadyUsed){
                clients.addLast(c);
                for (Message m : messages) {
                    c.displayMessage(m);
                }
                System.err.println(clients.size() + " people connected.");
                Message msg = new Message(new Date(),"Server",c.getUserName() + " has joined.");

                sendMessage(msg);
                result = true;
            } else {
                Message msg = new Message(new Date(),"Server",String.format("User name \"%s\" already used.",c.getUserName()));
                c.displayMessage(msg);
            }

        }
        return result;
    }

    public void deleteClient(Client c) {
        // TODO Auto-generated method stub
        Message msg = new Message(new Date(),"Server",c.getUserName() + " has left.");
        sendMessage(msg);
        clients.remove(c);
        System.err.println(clients.size() + " people connected.");
    }
}
