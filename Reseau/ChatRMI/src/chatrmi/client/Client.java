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

public class Client implements ClientInterface{
    
    protected String serverAdress;
    
    protected int serverPort;
    
    protected String userName;
    
    ServerInterface server;
        
    ClientChatView clientChatView;

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

    @Override
    public String getUserName() {
        return userName;
    }
    
    public String getServerAdress() {
        return serverAdress;
    }
    
    public int getServerPort() {
        return serverPort;
    }
    
    public void setUserName(String name) {
        userName = name;
    }
    
    public void setServerAdress(String adress) {
        serverAdress = adress;
    }
    
    public void setServerPort(int port) {
        serverPort = port;
    }
    
    
    @Override
    public void displayMessage(MessageInterface m) throws RemoteException {
        clientChatView.displayMessage(m);
    }
    
    @Override
    public void newUserConnected(ClientInterface c) throws RemoteException {
        clientChatView.addUser(c);
    }
    
    @Override
    public void userDisconnected(ClientInterface c) throws RemoteException {
        if (c.getUserName().compareTo(userName)==0){
            server = null;
            clientChatView.refresh();
        }
        clientChatView.removeUser(c);
    }
    
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

    public Boolean isConnected() {
        return null != server;
    }
}
