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
import static java.lang.System.exit;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Date;
import java.util.LinkedList;

/**
 *
 * @author Nico
 */
public class Server implements ServerInterface {
    
    private String serverName;
    private int serverPort;
    private Registry registry;
    private boolean state;
    
    private LinkedList<ClientInterface> clients;
    private LinkedList<MessageInterface> messages;
    
    private ServerRunningView serverRunningView;
    
    public Server() {
       initialize("server",1099);
    }
    
    private void initialize(String sName, int sPort) {
        serverName = sName;
        serverPort = sPort;
        state = false;
        clients = new LinkedList<>();
        messages = new LinkedList<>();
        serverRunningView = new ServerRunningView(this);
        serverRunningView.setLocationRelativeTo(null);
        serverRunningView.setVisible(true);
        try
        {
            UnicastRemoteObject.exportObject(this, 0);
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            exit(0);
        }
    }
        
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
    
    public boolean start(String port)
    {
        try
        {
            serverPort = Integer.parseInt(port);
            state = run();
        }
        catch(NumberFormatException e)
        {
            System.err.println("Server exception: " + e.toString());
        }
        return state;
    }
        
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
    
    public Boolean isRunning() {
        return state;
    }
    
    @Override
    public void sendMessageToAll(MessageInterface m) throws RemoteException {
        // TODO Auto-generated method stub
        for (ClientInterface client : clients) {
            client.displayMessage(m);
        }
        messages.addLast(m);
    }

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

    private boolean contains(ClientInterface client) throws RemoteException
    {
        boolean result = false;
        for(ClientInterface c : clients){
            System.out.println(client.getUserName()+"="+c.getUserName());
            if ( client.getUserName().compareTo(c.getUserName()) == 0 ){
                result = true;
                break;
            }
        }
        return result;
    }
    
    private void sendServerMessageToAll(String m) throws RemoteException {
        Message msg = new Message(new Date(),"Server",m);
        MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject
                    .exportObject(msg, 0);
        
        sendMessageToAll(stubMsg);
    }
    
    private void sendServerMessage(ClientInterface c,String m) throws RemoteException {
        Message msg = new Message(new Date(),"Server",m);
        MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject
                    .exportObject(msg, 0);
        
        c.displayMessage(stubMsg);
    }
    
    private void sendHistorics(ClientInterface c) throws RemoteException {
        for( MessageInterface m : messages)
        {
            c.displayMessage(m);
        }
    }

}
