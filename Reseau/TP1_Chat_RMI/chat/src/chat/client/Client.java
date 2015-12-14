package chat.client;

import chat.Message;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

import chat.protocol.*;
import java.util.Date;

public class Client implements ClientInterface {

    private ClientViewInterface view;
    
    protected String userName;
    
    protected String serverName;
    
    protected int serverPort;
    
    protected ServerInterface server;
    
    
    public Client(ClientViewInterface ci,String sName, int sPort) {
        initialise(ci,sName,sPort);
    }

    public Client(ClientViewInterface ci,int sPort) {
        initialise(ci,null,sPort);
    }

    public Client(ClientViewInterface ci) {
        initialise(ci,null,1099);
    }

    private void initialise(ClientViewInterface ci,String sName, int sPort) {
        view = ci;
        serverName = sName;
        serverPort = sPort;
        server = null;
        try{
            ClientInterface stub = (ClientInterface) UnicastRemoteObject
                    .exportObject(this, 0);
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
        
    }

    @Override
    public String getUserName() {
        return userName;
    }
    
    public void setUsername(String s) {
        userName = s;
    }

    public void setServername(String sName){
        serverName = sName;
    }
    
    public void setServerport(int sPort){
        serverPort = sPort;
    }
    
    @Override
    public void displayMessage(MessageInterface m) throws RemoteException {
        // TODO Auto-generated method stub
        System.out.println(m.getTextMessage());
        view.displayMessage(m);
    }

    public Boolean connect() {
        Boolean result = true;
        try {
            // utiliser avec null pour local host
            
            Registry registry = LocateRegistry.getRegistry(serverName,
                    serverPort);

            server = (ServerInterface) registry.lookup("server");

            if( server!=null && !server.addClient(this) ){
                server = null;
                result = false;
            }
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
            server = null;
            result = false;
        }
        return result;
    }

    public void disconnect() {
        try {
            server.deleteClient(this);
            server = null;
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }

    public Boolean isConnected() {
        return null != server;
    }

    public void sendMessage(String m) {
        try {
            Message msg = new Message(new Date(), userName, m);
            MessageInterface stubMsg = (MessageInterface) UnicastRemoteObject.exportObject(msg, 0);
            server.sendMessage(stubMsg);
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
