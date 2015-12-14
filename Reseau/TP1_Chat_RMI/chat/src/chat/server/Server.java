package chat.server;

import chat.Message;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;


import chat.protocol.*;

import java.util.*;

public class Server implements ServerInterface {

    public static void main(String[] args) {
        Server server = new Server();
    }

    private String serverName;
    private int serverPort;
    private LinkedList<ClientInterface> clients;
    private LinkedList<MessageInterface> messages;

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

            LocateRegistry.createRegistry(serverPort);

            ServerInterface stub = (ServerInterface) UnicastRemoteObject
                    .exportObject(this, 0);

            Registry registry = LocateRegistry.getRegistry();
            registry.bind("server", stub);

            System.err.println("Server ready.");
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }

    @Override
    public void sendMessage(MessageInterface m) throws RemoteException {
        // TODO Auto-generated method stub
        for (ClientInterface client : clients) {
            client.displayMessage(m);
        }
        messages.addLast(m);
    }

    @Override
    public Boolean addClient(ClientInterface c) throws RemoteException {
        // TODO Auto-generated method stub
        Boolean result = false;
        if (c != null){
            
            Boolean nameAlreadyUsed = false;
            
            if (c.getUserName().compareTo("Server") == 0){
                nameAlreadyUsed = true;
            }
            for (ClientInterface client : clients){
                if(client.getUserName().compareTo(c.getUserName()) == 0){
                    nameAlreadyUsed = true;
                }
            }
                  
            if(!nameAlreadyUsed){
                clients.addLast(c);
                for (MessageInterface m : messages) {
                    c.displayMessage(m);
                }
                System.err.println(clients.size() + " people connected.");
                Message msg = new Message(new Date(),"Server",c.getUserName() + " has joined.");
                MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject
                            .exportObject(msg, 0);
                sendMessage(stubMsg);
                result = true;
            } else {
                Message msg = new Message(new Date(),"Server",String.format("User name \"%s\" already used.",c.getUserName()));
                MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject
                            .exportObject(msg, 0);
                c.displayMessage(stubMsg);
            }

        }
        return result;
    }

    @Override
    public void deleteClient(ClientInterface c) throws RemoteException {
        // TODO Auto-generated method stub
        Message msg = new Message(new Date(),"Server",c.getUserName() + " has left.");
        MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject
                    .exportObject(msg, 0);
        sendMessage(stubMsg);
        clients.remove(c);
        System.err.println(clients.size() + " people connected.");
    }
}
