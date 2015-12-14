package chat.client;

import chat.Message;

import java.util.Date;

public class Client {

    private ClientViewInterface view;
    
    protected String userName;
    
    protected String serverName;
    
    protected int serverPort;
        
    
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

        try{

        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
        
    }

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
    
    public void displayMessage(Message m) {
        // TODO Auto-generated method stub
        System.out.println(m.getTextMessage());
        view.displayMessage(m);
    }

    public Boolean connect() {
        Boolean result = true;
        try {
            // utiliser avec null pour local host
            
           
           
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
            result = false;
        }
        return result;
    }

    public void disconnect() {
        try {

        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }

    public Boolean isConnected() {
        return false;
    }
    
    public void sendMessage(String m) {
        try {
            Message msg = new Message(new Date(), userName, m);

        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
